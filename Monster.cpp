#include "Convert.hpp"

#include "Player.hpp"
#include "Monster.hpp"

namespace CTRPluginFramework
{
    Monster *Monster::MInstance = nullptr;
    u32 Monster::Monster_Instance = 0;

    Monster::Monster()
    {
        this->Update();
    }

    Monster::~Monster(void)
    {
        MInstance = nullptr;
    }

    Monster *Monster::GetInstance(void)
    {
        if (MInstance == nullptr)
            MInstance = new Monster;

        return MInstance;
    }

    void Monster::Update(void)
    {
        Monster_Instance = *(u32 *)Monster_Pointer;
    }

    u32 Monster::Return(int Offset)
    {
        return (Monster::GetInstance()->IsLoaded()) ? Monster_Instance + Offset : 0;
    }

    bool Monster::IsLoaded(void)
    {
        if (Monster_Instance)
            return true;
        else
            return false;
    }

    Monster2* Monster2::MInstance = nullptr;
    u32 Monster2::Monster_Instance = 0;

    Monster2::Monster2()
    {
        this->Update();
    }

    Monster2::~Monster2(void)
    {
        MInstance = nullptr;
    }

    Monster2* Monster2::GetInstance(void)
    {
        if (MInstance == nullptr)
            MInstance = new Monster2;

        return MInstance;
    }

    void Monster2::Update(void)
    {
        Monster_Instance = *(u32*)Monster2_Pointer;
    }

    u32 Monster2::Return(int Offset)
    {
        return (Monster2::GetInstance()->IsLoaded()) ? Monster_Instance + Offset : 0;
    }

    bool Monster2::IsLoaded(void)
    {
        if (Monster_Instance)
            return true;
        else
            return false;
    }
}