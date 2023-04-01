#ifndef STRUCTURES_HPP
#define STRUCTURES_HPP

#define INVENTORY_SIZE 24
#define TALENT_AMOUNT 14

namespace CTRPluginFramework
{
    struct ItemsStructure
    {
        const int Pouch_Amount = 0x1090;
    };


    struct PlayerStructure
    {
        const int Coordinates[3] = {0xE50, 0xE48, 0xE4C},
                  Rotation = 0xA358,
                  Speed = 0x11D4,
                  MaxHealth = 0x1186,
                  Health = 0x1184,
                  HbgAmmos = 0xA7B4,
                  GunnerPouch = 0x1070;
    };
    
    struct MonsterStructure
    {
        const int Health = 0x1218;
        const u16 Para_Value = 0x87A4,
                  Blast_Value = 0x88E1,
                  Sleep_Value = 0x8790,
                  Poison_Value = 0x878C,
                  Stun_Value = 0x88B1;
    };
}
#endif