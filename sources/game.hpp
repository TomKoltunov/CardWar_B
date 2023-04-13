/**
 * @file game.hpp
 * @author Tom Koltunov (tomkoltunov@gmail.com)
 * @brief Headers for 'game' object
 * @version 0.2
 * @date 2023-04-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "player.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ariel
{
    class Game
    {
        Player &_player1;
        Player &_player2;
        vector<string> _turns;
        /*
        As I explained in the file game.cpp, in order to calculate the win rate of each player it will be more comfortable if each 
        player will hold the following attribute.
        */
        int _draws;

        public:
            Game(Player &player1, Player &player2); // A constructor for this class which receives the references of the two players 
                                                    // that play the current game.
            void printLastTurn(); // Print the last turn stats
            void playTurn();
            void playAll(); // Playes the game untill the end
            void printWiner(); // Prints the name of the winning player
            void printLog(); // Prints all the turns played one line per turn (same format as game.printLastTurn())
            void printStats();// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand (draw within a draw counts as 2 draws)
    };
}