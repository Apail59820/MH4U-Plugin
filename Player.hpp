#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "stdafx.hpp"
#include "Addresses.hpp"

#include "Structures.hpp"

namespace CTRPluginFramework
{
    class Player
    {
    public:
        /**
         *@brief Gets the Instance of the Class, also Create one if there isn't yet.
        */
        static Player *GetInstance(void);

        /**
         *@brief Updates the Variables of the Class, should be added in a PluginMenu Callback so it's Called in the Background and Values stay up to date.
        */
        void Update(void);

        /**
         *@brief Gets Player Instance Address.
         *@param Index Player Index to get the Instance Address from.
         *@param Offset Offset to add to the Address of the Instance.
         *@return Player Instance Address.
        */
        u32 Return(int Index = 0, int Offset = 0);
        
        /**
         *@brief Checks if the Player is Loaded.
         *@return True if the Instance of the Player is not null, else False.
        */
        bool IsLoaded(void);

        /**
         *@brief Gets Coordinates from Player Index.
         *@param Index Player Index to get the Coordinates from.
         *@param Coordinate Coordinate Index to get XYZ.
         *@return Player Coordinates.
        */
        float GetCoordinates(int Index = 0, int Coordinate = 0);
        
    private:
        Player();
        ~Player();

        static Player *PInstance;

        static int Player_Index;
        static u32 Player_Instance;
    };
}

#endif