#include "Helper.hpp"

namespace CTRPluginFramework
{
	bool Helper::SetKeyboard(const String &Message, bool Hexadecimal, const int Length, u32 &Output, u32 Start, OnInputChange CallBack)
	{
		Sleep(Milliseconds(100));
		KB->GetMessage() = Message;
		KB->IsHexadecimal(Hexadecimal);
		KB->SetMaxLength(Length);
		KB->OnInputChange(CallBack);
		return KB->Open(Output, Start) == 0;
	}

	bool Helper::SetKeyboard(const String &Message, bool Hexadecimal, const int Length, u16 &Output, u16 Start, OnInputChange CallBack)
	{
		Sleep(Milliseconds(100));
		KB->GetMessage() = Message;
		KB->IsHexadecimal(Hexadecimal);
		KB->SetMaxLength(Length);
		KB->OnInputChange(CallBack);
		return KB->Open(Output, Start) == 0;
	}

	bool Helper::SetKeyboard(const String &Message, bool Hexadecimal, const int Length, u8 &Output, u8 Start, OnInputChange CallBack)
	{
		Sleep(Milliseconds(100));
		KB->GetMessage() = Message;
		KB->IsHexadecimal(Hexadecimal);
		KB->SetMaxLength(Length);
		KB->OnInputChange(CallBack);
		return KB->Open(Output, Start) == 0;
	}

	bool Helper::SetKeyboard(const String &Message, bool Hexadecimal, const int Length, float &Output, float Start, OnInputChange CallBack)
	{
		Sleep(Milliseconds(100));
		KB->GetMessage() = Message;
		KB->IsHexadecimal(Hexadecimal);
		KB->SetMaxLength(Length);
		KB->OnInputChange(CallBack);
		return KB->Open(Output, Start) == 0;
	}

	bool Helper::SetKeyboard(const String &Message, bool Hexadecimal, const int Length, String &Output, String Start, OnInputChange CallBack)
	{
		Sleep(Milliseconds(100));
		KB->GetMessage() = Message;
		KB->IsHexadecimal(Hexadecimal);
		KB->SetMaxLength(Length);
		KB->OnInputChange(CallBack);
		return KB->Open(Output, Start) == 0;
	}

	void Helper::Toggle(u32 Offset, u32 Enable, u32 Disable, const String &Notification)
	{
		StringVector Options = {"Enable", "Disable"};

		OptionsKB->GetMessage() = "\n\n\n\n\n Would you like to Enable/Disable it ?";
		OptionsKB->Populate(Options);

		switch (OptionsKB->Open())
		{
			case -1:
				break;
			case 0:
				Process::Write32(Offset, Enable);
				OSD::Notify(Color::Lime << Notification << " : " << Color::Cyan << "Enabled!");
				break;
			case 1:
				Process::Write32(Offset, Disable);
				OSD::Notify(Color::Lime << Notification << " : " << Color::Magenta << "Disabled!");
				break;
		}
	}

	void Helper::ToggleTable(u32 Offset[], u32 Enable[], u32 Disable[], u8 Length, const String &Notification)
	{
		StringVector Options = {"Enable", "Disable"};

		OptionsKB->GetMessage() = "\n\n\n\n\n Would you like to Enable/Disable it ?";
		OptionsKB->Populate(Options);
		
		switch (OptionsKB->Open())
		{
			case -1:
				break;
			case 0:
				for (u8 i = 0; i < Length; i++)
					Process::Write32(Offset[i], Enable[i]);
				OSD::Notify(Color::Lime << Notification << " : " << Color::Cyan << "Enabled!");
				break;
			case 1:
				for (u8 i = 0; i < Length; i++)
					Process::Write32(Offset[i], Disable[i]);
				OSD::Notify(Color::Lime << Notification << " : " << Color::Magenta << "Disabled!");
				break;
		}
	}

	void Helper::WriteTable(u32 Offset[], u8 Value[], u8 Length)
	{
		for (u8 i = 0; i < Length; i++)
			Process::Write8(Offset[i], Value[i]);
	}

	void Helper::WriteTable(u32 Offset[], u16 Value[], u8 Length)
	{
		for (u8 i = 0; i < Length; i++)
			Process::Write16(Offset[i], Value[i]);
	}

	void Helper::WriteTable(u32 Offset[], u32 Value[], u8 Length)
	{
		for (u8 i = 0; i < Length; i++)
			Process::Write32(Offset[i], Value[i]);
	}

	void Helper::WriteTable(u32 Offset[], float Value[], u8 Length)
	{
		for (u8 i = 0; i < Length; i++)
			Process::WriteFloat(Offset[i], Value[i]);
	}

	/*Allocates New Memory Space for Keyboard Pointers to avoid Memory Leaks*/
	void Allocate()
	{
		delete KB;
		delete OptionsKB;
	}
}