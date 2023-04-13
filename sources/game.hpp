/**
 * @file game.hpp
 * @author your name (you@domain.com)
 * @brief Headers for 'game' object
 * @version 0.1
 * @date 2023-03-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "player.hpp"
#include <iostream>

using namespace std;

namespace ariel
{
    class Game
    {
        public:
            Game(Player player1, Player player2);
            void printLastTurn(); // Print the last turn stats
            void playTurn();
            void playAll(); // Playes the game untill the end
            void printWiner(); // Prints the name of the winning player
            void printLog(); // Prints all the turns played one line per turn (same format as game.printLastTurn())
            void printStats();// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand (draw within a draw counts as 2 draws)
    };
}