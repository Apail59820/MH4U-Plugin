#ifndef HELPER_HPP
#define HELPER_HPP

#include "stdafx.hpp"

namespace CTRPluginFramework
{
	static Keyboard *KB = new Keyboard("\n\n\n\n\nText"),
					*OptionsKB = new Keyboard("\n\n\n\n\nText");

    class Helper
    {
    public:
        /**
         *\param Message String to show at the top of the Keyboard.
         *\param Hexadecimal Set it to True if you want the Keyboard to be Hexadecimal, False if not.
         *\param Length Maximum count of Characters you can write with QWERTY Keyboard.
         *\param Output Where to place the User Input.
         *\param Start The Keyboard will Start with this Value as Input.
         *\param CallBack The Signature of the CallBack Called when the Input Changes.
         *\brief Sets a Keyboard.
        */
        static bool SetKeyboard(const String &Message, bool Hexadecimal, const int Length, u32 &Output, u32 Start, OnInputChange CallBack = nullptr);
        
        /**
         *\param Message String to show at the top of the Keyboard.
         *\param Hexadecimal Set it to True if you want the Keyboard to be Hexadecimal, False if not.
         *\param Length Maximum count of Characters you can write with QWERTY Keyboard.
         *\param Output Where to place the User Input.
         *\param Start The Keyboard will Start with this Value as Input.
         *\param CallBack The Signature of the CallBack Called when the Input Changes.
         *\brief Sets a Keyboard.
        */
        static bool SetKeyboard(const String &Message, bool Hexadecimal, const int Length, u16 &Output, u16 Start, OnInputChange CallBack = nullptr);
        
        /**
         *\param Message String to show at the top of the Keyboard.
         *\param Hexadecimal Set it to True if you want the Keyboard to be Hexadecimal, False if not.
         *\param Length Maximum count of Characters you can write with QWERTY Keyboard.
         *\param Output Where to place the User Input.
         *\param Start The Keyboard will Start with this Value as Input.
         *\param CallBack The Signature of the CallBack Called when the Input Changes.
         *\brief Sets a Keyboard.
        */
        static bool SetKeyboard(const String &Message, bool Hexadecimal, const int Length, u8 &Output, u8 Start, OnInputChange CallBack = nullptr);
        
        /**
         *\param Message String to show at the top of the Keyboard.
         *\param Hexadecimal Set it to True if you want the Keyboard to be Hexadecimal, False if not.
         *\param Length Maximum count of Characters you can write with QWERTY Keyboard.
         *\param Output Where to place the User Input.
         *\param Start The Keyboard will Start with this Value as Input.
         *\param CallBack The Signature of the CallBack Called when the Input Changes.
         *\brief Sets a Keyboard.
        */
        static bool SetKeyboard(const String &Message, bool Hexadecimal, const int Length, float &Output, float Start, OnInputChange CallBack = nullptr);
        
        /**
         *\param Message String to show at the top of the Keyboard.
         *\param Hexadecimal Set it to True if you want the Keyboard to be Hexadecimal, False if not.
         *\param Length Maximum count of Characters you can write with QWERTY Keyboard.
         *\param Output Where to place the User Input.
         *\param Start The Keyboard will Start with this Value as Input.
         *\param CallBack The Signature of the CallBack Called when the Input Changes.
         *\brief Sets a Keyboard.
        */
        static bool SetKeyboard(const String &Message, bool Hexadecimal, const int Length, String &Output, String Start, OnInputChange CallBack = nullptr);

        /**
         *\param Offset The Offset to Write to with Options.
         *\param Enable Value to Assign to Enable Option.
         *\param Disable Value to Assign to Disable Option.
         *\param Notification Title of the Notification when an Option got Pressed.
         *\brief Opens a Populate Keyboard with Enable/Disable Options. 
        */ 
        static void Toggle(u32 Offset, u32 Enable, u32 Disable, const String &Notification);

        /**
         *\param Offset u32 Table to put the Offsets.
         *\param Enable u32 Table to Assign the Values to Enable.
         *\param Disable u32 Table to Assign the Values to Disable.
         *\param Notification Title of the Notification when an Option got Pressed.
         *\brief Opens a Populate Keyboard with Enable/Disable Options for Multiple Offsets.
        */ 
        static void ToggleTable(u32 Offset[], u32 Enable[], u32 Disable[], u8 Length, const String &Notification);

        /**
         *\param Offset u32 Table to put the Offsets.
         *\param Value u8 Values to Write to the Offsets.
         *\param Length Length of the Table.
         *\brief Writes to Multiple Offsets.
        */
        static void WriteTable(u32 Offset[], u8 Value[], u8 Length);

        /**
         *\param Offset u32 Table to put the Offsets.
         *\param Value u16 Values to Write to the Offsets.
         *\param Length Length of the Table.
         *\brief Writes to Multiple Offsets.
        */
        static void WriteTable(u32 Offset[], u16 Value[], u8 Length);

        /**
         *\param Offset u32 Table to put the Offsets.
         *\param Value u32 Values to Write to the Offsets.
         *\param Length Length of the Table.
         *\brief Writes to Multiple Offsets.
        */
        static void WriteTable(u32 Offset[], u32 Value[], u8 Length);

        /**
         *\param Offset u32 Table to put the Offsets.
         *\param Value Float Values to Write to the Offsets.
         *\param Length Length of the Table.
         *\brief Writes to Multiple Offsets.
        */
        static void WriteTable(u32 Offset[], float Value[], u8 Length);
    };
}

#endif