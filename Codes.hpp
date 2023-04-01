#ifndef CODES_HPP
#define CODES_HPP

#include "Helper.hpp"
#include "Player.hpp"
#include "Monster.hpp"
#include "Convert.hpp"
#include "Callbacks.hpp"

namespace CTRPluginFramework
{
    /*Player*/

    void CoordinatesSettings(MenuEntry *entry);
	void Coordinates(MenuEntry *entry);

    void FastMovementsSettings(MenuEntry *entry);
    void FastMovements(MenuEntry *entry);

    void SpinningTop(MenuEntry* entry);

    void InfiniteBombsDrop(MenuEntry *entry);
    void InfiniteItems(MenuEntry *entry);

    void MaxHealth(MenuEntry* entry);
    void InfiniteHealth(MenuEntry* entry);

    /*HBG Hacks*/

    void InfiniteHBGammos(MenuEntry* entry);
    void InfiniteGunnerPouchAmmos(MenuEntry* entry);
    void RapidFireSettings(MenuEntry* entry);
    void RapidFire(MenuEntry* entry);

    /*Monster*/
    
    void statusMonster(MenuEntry* entry);

    void setPresetMessageToMonster1Health(MenuEntry* entry);
    void setPresetMessageToMonster2Health(MenuEntry* entry);

    void Explosion(MenuEntry* entry);

    void OneShotMonster1(MenuEntry* entry);
    void OneShotMonster2(MenuEntry* entry);
}

#endif
