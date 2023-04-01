#ifndef MONSTER_HPP
#define MONSTER_HPP

#include "stdafx.hpp"
#include "Addresses.hpp"

#include "Structures.hpp"

namespace CTRPluginFramework
{
    class Monster
    {
    public:
        /**
         *@brief Gets the Instance of the Class, also Create one if there isn't yet.
        */
        static Monster *GetInstance(void);

        /**
         *@brief Updates the Variables of the Class, should be added in a PluginMenu Callback so it's Called in the Background and Values stay up to date.
        */
        void Update(void);

        /**
         *@brief Gets Monster Instance Address.
         *@param Offset Offset to add to the Address of the Instance.
         *@return Monster Instance Address.
        */
        u32 Return(int Offset = 0);

        /**
         *@brief Checks if the Monster is Loaded.
         *@return True if the Instance of the Monster is not null, else False.
        */
        bool IsLoaded(void);
       
    private:
        Monster();
        ~Monster();

        static Monster *MInstance;

        static u32 Monster_Instance;
    };

    class Monster2
    {
    public:
        /**
         *@brief Gets the Instance of the Class, also Create one if there isn't yet.
        */
        static Monster2* GetInstance(void);

        /**
         *@brief Updates the Variables of the Class, should be added in a PluginMenu Callback so it's Called in the Background and Values stay up to date.
        */
        void Update(void);

        /**
         *@brief Gets Monster Instance Address.
         *@param Offset Offset to add to the Address of the Instance.
         *@return Monster Instance Address.
        */
        u32 Return(int Offset = 0);

        /**
         *@brief Checks if the Monster is Loaded.
         *@return True if the Instance of the Monster is not null, else False.
        */
        bool IsLoaded(void);

    private:
        Monster2();
        ~Monster2();

        static Monster2* MInstance;

        static u32 Monster_Instance;
    };
}

#endif