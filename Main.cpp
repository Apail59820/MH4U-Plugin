#include "Codes.hpp"

void abort(void);

namespace CTRPluginFramework
{
    static void ToggleTouchscreenForceOn(void)
    {
        static u32 original = 0;
        static u32 *patchAddress = nullptr;

        if (patchAddress && original)
        {
            *patchAddress = original;
            return;
        }

        static const vector<u32> pattern =
        {
            0xE59F10C0, 0xE5840004, 0xE5841000, 0xE5DD0000,
            0xE5C40008, 0xE28DD03C, 0xE8BD80F0, 0xE5D51001,
            0xE1D400D4, 0xE3510003, 0x159F0034, 0x1A000003
        };

        Result  res;
        Handle  processHandle;
        s64     textTotalSize = 0;
        s64     startAddress = 0;
        u32     *found;

        if (R_FAILED(svcOpenProcess(&processHandle, 16)))
            return;

        svcGetProcessInfo(&textTotalSize, processHandle, 0x10002);
        svcGetProcessInfo(&startAddress, processHandle, 0x10005);
        if(R_FAILED(svcMapProcessMemoryEx(CUR_PROCESS_HANDLE, 0x14000000, processHandle, (u32)startAddress, textTotalSize)))
            goto exit;

        found = (u32 *)Utils::Search<u32>(0x14000000, (u32)textTotalSize, pattern);

        if (found != nullptr)
        {
            original = found[13];
            patchAddress = (u32 *)PA_FROM_VA((found + 13));
            found[13] = 0xE1A00000;
        }

        svcUnmapProcessMemoryEx(CUR_PROCESS_HANDLE, 0x14000000, textTotalSize);
exit:
        svcCloseHandle(processHandle);
    }

	void PatchProcess(FwkSettings &settings)
	{
        ToggleTouchscreenForceOn();
	}

    void OnProcessExit(void)
    {
        ToggleTouchscreenForceOn();
    }

    static MenuEntry *AddArg(void *arg, MenuEntry *entry)
    {
        if (entry != nullptr)
            entry->SetArg(arg);
        return (entry);
    }

    static MenuEntry *EntryWithHotkey(MenuEntry *entry, const Hotkey &hotkey)
    {
        if (entry != nullptr)
        {
            entry->Hotkeys += hotkey;
            entry->SetArg(new String(entry->Name()));
            entry->Name() += " " + hotkey.ToString();
            entry->Hotkeys.OnHotkeyChangeCallback([](MenuEntry *entry, int index)
            {
                String *name = reinterpret_cast<String *>(entry->GetArg());

                entry->Name() = *name + " " + entry->Hotkeys[0].ToString();
            });
        }
        return (entry);
    }

    static MenuEntry *EntryWithHotkey(MenuEntry *entry, const vector<Hotkey> &Hotkeys)
    {
        if (entry != nullptr)
        {
            for (const Hotkey &hotkey : Hotkeys)
                entry->Hotkeys += hotkey;
        }
        return (entry);
    }

    void CTRPF_Menu(PluginMenu &Menu)
    {
        const String Stable = " | " << Color::Cyan << "Stable", 
                     Unstable = " | " << Color::Orange << "Unstable",
                     Improving = " | " << Color::Yellow << "Improving", 
                     Fixing = " | " << Color::Lime << "Fixing",
                     Testing = " | " << Color::Red << "Testing", 
                     Debug = " | " << Color::Teal << "Debug";

        /*Menu Folders*/
        MenuFolder *Player_Folder = new MenuFolder("Player", "Player Folder."),
                   *Monster_Folder = new MenuFolder("Monsters", "Monsters Folder."),
                   *HbgHacks_Folder = new MenuFolder("HBG Hacks", "HBG Hacks.");

        /*Menu Folders Order*/

        Menu += Player_Folder;
        Menu += Monster_Folder;
        Menu += HbgHacks_Folder;


        /*Player*/

        *Player_Folder += EntryWithHotkey(new MenuEntry("Coordinates" + Stable, Coordinates, CoordinatesSettings, "Press the Hotkeys to Move to the Corresponding Direction."),
        {
            Hotkey(Key::A | Key::DPadUp, "Go Up"),
            Hotkey(Key::A | Key::DPadDown, "Go Down"),
            Hotkey(Key::A | Key::DPadRight, "Go Right"),
            Hotkey(Key::A | Key::DPadLeft, "Go Left")
        });

        *Player_Folder += new MenuEntry("Fast Movements" + Stable, FastMovements, FastMovementsSettings, "Allows you to Move Fast.\n\nPress \uE003.");

        *Player_Folder += new MenuEntry("Infinite Items" + Stable, InfiniteItems, "All Items Amount is set to 99.");

        *Player_Folder += new MenuEntry("Infinite Bombs Drop" + Stable, InfiniteBombsDrop, "Allows you to Drop an Infinite Amount of Bombs.");

        *Player_Folder += new MenuEntry("Max Health" + Stable, MaxHealth, "Set your health limit at its maximum.");

        *Player_Folder += new MenuEntry("Infinite Health" + Stable, InfiniteHealth, "Infinite HPs.");

        *Player_Folder += EntryWithHotkey(new MenuEntry("Spinning top" + Stable, SpinningTop, "TOURNER DANS LE VIDE."),
        {
            Hotkey(Key::L | Key::B, "Disable/Enable")
        });

        /*Monster*/

        *Monster_Folder += new MenuEntry("Set Preset Msg To Monster Hp" + Stable, setPresetMessageToMonster1Health, "Set the fourth preset message to the current monster HP.");
        *Monster_Folder += new MenuEntry("Set Preset Msg To Monster2 Hp" + Stable, setPresetMessageToMonster2Health, "Set the fourth preset message to the current monster HP.");

        *Monster_Folder += EntryWithHotkey(new MenuEntry("Status Monsters" + Stable, statusMonster, "L+Dpad for 1st monster, R+Dpad for 2nd monster."),
        {
            Hotkey(Key::L | Key::DPadLeft, "Stun monster 1"),
            Hotkey(Key::L | Key::DPadDown, "Sleep monster 1"),
            Hotkey(Key::L | Key::DPadRight, "Para monster 1"),
            Hotkey(Key::L | Key::DPadUp, "Poison monster 1"),
            Hotkey(Key::R | Key::DPadLeft, "Stun monster 2"),
            Hotkey(Key::R | Key::DPadDown, "Sleep monster 2"),
            Hotkey(Key::R | Key::DPadRight, "Para monster 2"),
            Hotkey(Key::R | Key::DPadUp, "Poison monster 2")
        });

        *Monster_Folder += EntryWithHotkey(new MenuEntry("EXPLOOOSION" + Stable, Explosion, "Blow up monsters. 2 hotkeys for 2 monsters."),
        {
            Hotkey(Key::X | Key::R, "Explode monster 1"),
            Hotkey(Key::X | Key::L, "Explode monster 2")
        });

        /*HBG Hacks*/

        *HbgHacks_Folder += new MenuEntry("Infinite Ammos" + Stable, InfiniteHBGammos, "Infinite HBG Ammos.");
        *HbgHacks_Folder += new MenuEntry("Infinite gunner pouch ammos" + Stable, InfiniteBombsDrop, "Infinite gunner pouch ammos.");

        *HbgHacks_Folder += new MenuEntry("RapidFire" + Stable, RapidFire, RapidFireSettings, "Allows you to RapidFire.");
    }

    int main()
    {
        PluginMenu *Menu = new PluginMenu("KeroZ", 1, 0, 1, "By Kero"),
        &PMenu = *Menu;

        CTRPF_Menu(*Menu);
        OSD::Notify(Color::Cyan << "Plugin By KeRoZeN");
        Menu->SynchronizeWithFrame(true);
        Menu->ShowWelcomeMessage(false);
        PMenu += PlayerUpdateCallback;
        PMenu += MonsterUpdateCallback;
        Menu->Run();

        delete Menu;
        return (0);
    }
}
