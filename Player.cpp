#include "Convert.hpp"

#include "Player.hpp"

namespace CTRPluginFramework
{
    Player *Player::PInstance = nullptr;
    int Player::Player_Index = 0;
    u32 Player::Player_Instance = 0;

    Player::Player()
    {
        this->Update();
    }

    Player::~Player(void)
    {
        PInstance = nullptr;
    }

    Player *Player::GetInstance(void)
    {
        if (PInstance == nullptr)
            PInstance = new Player;

        return PInstance;
    }

    void Player::Update(void)
    {
        switch (Player_Index)
        {
            case 0:
                Player_Instance = *(u32 *)Player_Pointer;
                break;

            default:
                break;
        }
    }

    u32 Player::Return(int Index, int Offset)
    {
        Player_Index = Index;

        return (Index <= 4 && Player::GetInstance()->IsLoaded()) ? Player_Instance + Offset : 0;
    }

    bool Player::IsLoaded(void)
    {
        if (Player_Instance)
            return true;
        else
            return false;
    }

    float Player::GetCoordinates(int Index, int Coordinate)
    {
        PlayerStructure PlayerOffset;

        return *(float *)Player::GetInstance()->Return(Index, PlayerOffset.Coordinates[Coordinate]);
    }
}