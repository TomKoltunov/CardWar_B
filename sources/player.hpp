/**
 * @file player.hpp
 * @author your name (you@domain.com)
 * @brief Headers for 'player' object
 * @version 0.1
 * @date 2023-03-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace ariel
{
    class Player
    {
        public:
            Player(string name);
            int stacksize(); // Prints the amount of cards left. Should be 21 but can be less if a draw was played
            int cardesTaken(); // Prints the amount of cards this player has won
    };
}