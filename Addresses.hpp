#ifndef ADDRESSES_HPP
#define ADDRESSES_HPP

#include "stdafx.hpp"

#define SUPPLY_BOX_SIZE 40
#define GUNNER_POUCH_SIZE 8

namespace CTRPluginFramework
{
    /*Pointers*/

    static const u32 Player_Pointer = 0x81C6DEC,
                     Monster_Pointer = 0x81C7750,
                     Monster2_Pointer = 0x81C7754;

    /*Addresses*/

    static const u32 Bombs_Limit_Address = 0x80B8D34;

    static const u32 Preset_Message_4_Address = 0x837D45E;
    static const u32 Preset_Message_5_Address = 0x837D49E;
}

#endif
