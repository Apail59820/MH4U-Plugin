#include "Callbacks.hpp"

namespace CTRPluginFramework
{
    void PlayerUpdateCallback(void)
    {
        Player::GetInstance()->Update();
    }

    void MonsterUpdateCallback(void)
    {
        Monster::GetInstance()->Update();
        Monster2::GetInstance()->Update();
    }
}