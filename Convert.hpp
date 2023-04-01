#ifndef CONVERT_HPP
#define CONVERT_HPP

#include "stdafx.hpp"

namespace CTRPluginFramework
{
    class Convert
    {
    public:
        /**
         *\param Value Value to Convert.
         *\brief Allows you to Convert Values to Hexadecimal.
        */
        static String Hexadecimal(u8 Value);

        /**
         *\param Value Value to Convert.
         *\brief Allows you to Convert Values to Hexadecimal.
        */
        static String Hexadecimal(u16 Value);

        /**
         *\param Value Value to Convert.
         *\brief Allows you to Convert Values to Hexadecimal.
        */
        static String Hexadecimal(u32 Value);

        /**
         *\param Value Value to Convert.
         *\brief Allows you to Convert Values to Hexadecimal.
        */
        static String Hexadecimal(u64 Value);

        /**
         *\param Value Value to Convert.
         *\brief Allows you to Convert Values to Decimal.
        */
        static String Decimal(u8 Value);

        /**
         *\param Value Value to Convert.
         *\brief Allows you to Convert Values to Decimal.
        */
        static String Decimal(u16 Value);

        /**
         *\param Value Value to Convert.
         *\brief Allows you to Convert Values to Decimal.
        */
        static String Decimal(u32 Value);

        /**
         *\param Value Value to Convert.
         *\brief Allows you to Convert Values to Decimal.
        */
        static String Decimal(u64 Value);
    };
}

#endif