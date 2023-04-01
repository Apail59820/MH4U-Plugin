#include "Codes.hpp"

namespace CTRPluginFramework
{
    /*Global Variables*/

	static float Coordinates_Speed = 50.0,
                 Movements_Speed = 1.0,
                 RapidFire_Speed = 9.0;

	/*Codes*/


	/*Player*/

	void CoordinatesSettings(MenuEntry *entry)
	{
		if (Helper::SetKeyboard(" \n\n\n\n How much Speed would you like\n to set for Coordinates ?", false, 3, Coordinates_Speed, Coordinates_Speed, 0))
			OSD::Notify(Color::Lime << "Coordinates Speed : " << Color::Cyan << Coordinates_Speed);
	}

	void Coordinates(MenuEntry *entry)
	{
		if (Player::GetInstance()->IsLoaded())
		{
			PlayerStructure PlayerOffset;

			if (entry->Hotkeys[0].IsDown())
				Process::WriteFloat(Player::GetInstance()->Return(0, PlayerOffset.Coordinates[0]), Player::GetInstance()->GetCoordinates() - Coordinates_Speed);
			else if (entry->Hotkeys[1].IsDown())
				Process::WriteFloat(Player::GetInstance()->Return(0, PlayerOffset.Coordinates[0]), Player::GetInstance()->GetCoordinates() + Coordinates_Speed);
			else if (entry->Hotkeys[2].IsDown())
				Process::WriteFloat(Player::GetInstance()->Return(0, PlayerOffset.Coordinates[1]), Player::GetInstance()->GetCoordinates(0, 1) + Coordinates_Speed);
			else if (entry->Hotkeys[3].IsDown())
				Process::WriteFloat(Player::GetInstance()->Return(0, PlayerOffset.Coordinates[1]), Player::GetInstance()->GetCoordinates(0, 1) - Coordinates_Speed);
		}
	}

    void FastMovementsSettings(MenuEntry *entry)
    {
		if (Helper::SetKeyboard(" \n\n\n\n How much Speed would you like to set for Movements ?", false, 3, Movements_Speed, Movements_Speed, 0))
			OSD::Notify(Color::Lime << "Movements Speed : " << Color::Cyan << Movements_Speed);
    }

    void FastMovements(MenuEntry *entry)
    {
        if (Player::GetInstance()->IsLoaded())
        {
            PlayerStructure PlayerOffset;

            if (Controller::IsKeyDown(Key::Y))
                Process::WriteFloat(Player::GetInstance()->Return(0, PlayerOffset.Speed), Movements_Speed);
        }
    }


    void InfiniteBombsDrop(MenuEntry *entry)
    {
        if (Player::GetInstance()->IsLoaded())
            Process::Write8(Bombs_Limit_Address, 0);
    }

    void InfiniteItems(MenuEntry *entry)
    {
        if (Player::GetInstance()->IsLoaded())
        {
            ItemsStructure ItemsOffset;

            for(int i = 0; i < INVENTORY_SIZE; i++)
                Process::Write8(Player::GetInstance()->Return(0, ItemsOffset.Pouch_Amount + (i * 4)), 99);
        }
    }

    void SpinningTop(MenuEntry* entry)
    {
        u32 RotationValue;

        if (Player::GetInstance()->IsLoaded())
        {
            PlayerStructure PlayerOffset;
            Process::Read32(Player::GetInstance()->Return(0, PlayerOffset.Rotation), RotationValue);
            if (entry->Hotkeys[0].IsDown()) {
                if (RotationValue >= 65000)
                    Process::Write32(Player::GetInstance()->Return(0, PlayerOffset.Rotation), 0);
                else
                    Process::Write32(Player::GetInstance()->Return(0, PlayerOffset.Rotation), RotationValue + 1000);
            }
        }
    }

    void MaxHealth(MenuEntry* entry)
    {
        if (Player::GetInstance()->IsLoaded())
        {
            PlayerStructure PlayerOffset;
            Process::Write8(Player::GetInstance()->Return(0, PlayerOffset.MaxHealth), 150);
        }
    }

    void InfiniteHealth(MenuEntry* entry)
    {
        if (Player::GetInstance()->IsLoaded())
        {
            PlayerStructure PlayerOffset;
            u8 current_max_health;
            Process::Read8(Player::GetInstance()->Return(0, PlayerOffset.MaxHealth), current_max_health);
            Process::Write8(Player::GetInstance()->Return(0, PlayerOffset.Health), current_max_health);
        }
    }

    /*HBG Hacks*/

    void InfiniteHBGammos(MenuEntry* entry)
    {
        if (Player::GetInstance()->IsLoaded())
        {
            PlayerStructure PlayerOffset;
            Process::Write8(Player::GetInstance()->Return(0, PlayerOffset.HbgAmmos ), 0xFF);
        }

    }

    void InfiniteGunnerPouchAmmos(MenuEntry* entry)
    {
        if (Player::GetInstance()->IsLoaded())
        {
            PlayerStructure PlayerOffset;
            for (int i = 0; i < GUNNER_POUCH_SIZE; i++)
                Process::Write8(Player::GetInstance()->Return(0, PlayerOffset.GunnerPouch + (i * 4)), 99);
        }
    }

    void RapidFireSettings(MenuEntry* entry)
    {
        if (Helper::SetKeyboard(" \n\n\n\n How much Speed would you like to set for RapidFire ?", false, 3, RapidFire_Speed, RapidFire_Speed, 0))
            OSD::Notify(Color::Lime << "RapidFire Speed : " << Color::Cyan << RapidFire_Speed);
    }

    void RapidFire(MenuEntry* entry)
    {
        if (Player::GetInstance()->IsLoaded())
        {
            PlayerStructure PlayerOffset;

            if (Controller::IsKeyDown(Key::R) && Controller::IsKeyDown(Key::X))
                Process::WriteFloat(Player::GetInstance()->Return(0, PlayerOffset.Speed), RapidFire_Speed);
        }
    }


    /*Monster*/

    void statusMonster(MenuEntry* entry)
    {
        MonsterStructure MonstersOffset;

        if (entry->Hotkeys[0].IsDown() && Monster::GetInstance()->IsLoaded()) //stun
            Process::Write16(Monster::GetInstance()->Return(MonstersOffset.Stun_Value), 0xFFFF);
        else if (entry->Hotkeys[1].IsDown() && Monster::GetInstance()->IsLoaded()) //sleep
            Process::Write16(Monster::GetInstance()->Return(MonstersOffset.Sleep_Value), 0xFFFF);
        else if (entry->Hotkeys[2].IsDown() && Monster::GetInstance()->IsLoaded()) //para
            Process::Write16(Monster::GetInstance()->Return(MonstersOffset.Para_Value), 0xFFFF);
        else if (entry->Hotkeys[3].IsDown() && Monster::GetInstance()->IsLoaded()) //poison
            Process::Write16(Monster::GetInstance()->Return(MonstersOffset.Poison_Value), 0xFFFF);

        else if (entry->Hotkeys[4].IsDown() && (Monster2::GetInstance()->IsLoaded())) //stun
            Process::Write16(Monster2::GetInstance()->Return(MonstersOffset.Stun_Value), 0xFFFF);
        else if (entry->Hotkeys[5].IsDown() && (Monster2::GetInstance()->IsLoaded())) //sleep
            Process::Write16(Monster2::GetInstance()->Return(MonstersOffset.Sleep_Value), 0xFFFF);
        else if (entry->Hotkeys[6].IsDown() && (Monster2::GetInstance()->IsLoaded())) //para
            Process::Write16(Monster2::GetInstance()->Return(MonstersOffset.Para_Value), 0xFFFF);
        else if (entry->Hotkeys[7].IsDown() && (Monster2::GetInstance()->IsLoaded())) //poison
            Process::Write16(Monster2::GetInstance()->Return(MonstersOffset.Poison_Value), 0xFFFF);
    }

    void setPresetMessageToMonster1Health(MenuEntry* entry)
    {
        if (Monster::GetInstance()->IsLoaded() )
        {
            MonsterStructure MonstersOffset;
            String HP = Convert::Decimal(*(u32*)Monster::GetInstance()->Return(MonstersOffset.Health));

            const String To_Start = "Monster HP : ",
                To_Write_Str = To_Start + HP,
                Space_Str = " ";

            String To_Write_Char;

            for (int i = 0; i < 18; i++)
                Process::WriteString(Preset_Message_4_Address + (i * 2), Space_Str); ///CLEAN THE PRESET MESSAGE

            for (unsigned int i = 0; i < To_Write_Str.size(); i++)
            {
                To_Write_Char = To_Write_Str[i];
                Process::WriteString(Preset_Message_4_Address + (i * 2), To_Write_Char);
            }

        }
    }

    void setPresetMessageToMonster2Health(MenuEntry* entry)
    {
        if (Monster2::GetInstance()->IsLoaded())
        {
            MonsterStructure MonstersOffset;
            String HP = Convert::Decimal(*(u32*)Monster2::GetInstance()->Return(MonstersOffset.Health));

            const String To_Start = "Monster2 HP : ",
                To_Write_Str = To_Start + HP,
                Space_Str = " ";

            String To_Write_Char;

            for (int i = 0; i < 18; i++)
                Process::WriteString(Preset_Message_5_Address + (i * 2), Space_Str); ///CLEAN THE PRESET MESSAGE

            for (unsigned int i = 0; i < To_Write_Str.size(); i++)
            {
                To_Write_Char = To_Write_Str[i];
                Process::WriteString(Preset_Message_5_Address + (i * 2), To_Write_Char);
            }

        }
    }

    void OneShotMonster1(MenuEntry* entry)
    {
        if (Monster::GetInstance()->IsLoaded())
        {
            MonsterStructure MonstersOffset;
            Process::Write32(Monster::GetInstance()->Return(MonstersOffset.Health), 1);
        }
    }
    void OneShotMonster2(MenuEntry* entry)
    {
        if (Monster2::GetInstance()->IsLoaded())
        {
            MonsterStructure MonstersOffset;
            Process::Write32(Monster2::GetInstance()->Return(MonstersOffset.Health), 1);
        }
    }

    void Explosion(MenuEntry* entry)
    {
        MonsterStructure MonstersOffset;
        if (Monster::GetInstance()->IsLoaded()){
            if (entry->Hotkeys[0].IsDown()) {
                Process::Write16(Monster::GetInstance()->Return(MonstersOffset.Blast_Value), 0xFFFF);
            }
            
        }
        if (Monster2::GetInstance()->IsLoaded()) {
            if (entry->Hotkeys[1].IsDown()) {
                Process::Write16(Monster2::GetInstance()->Return(MonstersOffset.Blast_Value), 0xFFFF);
            }
        }
    }
}
