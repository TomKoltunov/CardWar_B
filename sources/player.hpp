/**
 * @file player.hpp
 * @author Tom Koltunov (tomkoltunov@gmail.com)
 * @brief Headers for 'player' object
 * @version 0.2
 * @date 2023-04-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include "card.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ariel
{
    class Player
    {
        string _name;
        vector<Card> _stack;
        int _cardsTaken;
        /*
        As I explained in the file game.cpp, in order to calculate the win rate of each player it will be more comfortable if each 
        player will hold the following attributes.
        */
        int _gamesWon;
        int _gamesPlayed;

        public:
            Player(string name);
            int stacksize(); // Prints the amount of cards left. Should be 21 but can be less if a draw was played
            int cardesTaken(); // Prints the amount of cards this player has won
            string getName(); // 'Getter' function for this class
            int getGamesWon(); // 'Getter' function for this class
            void setGamesWon(int number); // 'Setter' function for this class
            int getGamesPlayed(); // 'Getter' function for this class
            void setGamesPlayed(int number); // 'Setter' function for this class
            Card retrieve(); // Retrieves the next card from this player's stack
            void takeCard(Card card); // Add the card this player won to his stack
            void moreGames(int cards); // Add the cards this player won to hit stack
    };
}