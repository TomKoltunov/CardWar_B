/**
 * @file game.cpp
 * @author Tom Koltunov (tomkoltunov@gmail.com)
 * @brief Implementation for 'game' object
 * @version 0.2
 * @date 2023-04-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*
I have asked the site "https://chat.openai.com/chat" how to calculate the win rate and draw rate of each player in the original "War"
game. I am noting that I didn't used any code from this site, I have only took the theory of how to make this calculation. I'm giving 
the exact quote from this site that aided me:
"To calculate the win rate, we count the number of games won by each player and divide it by the total number of games played. To 
calculate the draw rate, we count the number of games that resulted in a draw and divide it by the total number of games played."
Although, I have used the same site ("https://chat.openai.com/chat") for the implementation of the constructor of this class.
*/

#include "game.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for std::shuffle
#include <random> // for std::mt19937 and std::random_device

using namespace std;

namespace ariel
{
    Game::Game(Player &player1, Player &player2) : _player1(player1), _player2(player2)
    {
        this->_draws = 0;

        // create deck of cards
        vector<Card> deck;
        for (int i = 1; i <= 13; i++) // Because there are 13 (numbers and symbols)
        {
            // for each number and symbol need 4 symbols
            deck.emplace_back(Card(i, "Hearts"));
            deck.emplace_back(Card(i, "Diamonds"));
            deck.emplace_back(Card(i, "Clubs"));
            deck.emplace_back(Card(i, "Spades"));
        }

        // shuffle deck
        random_device rd;
        mt19937 gen(rd());
        shuffle(deck.begin(), deck.end(), gen);

        // deal cards
        for (size_t i = 0; i < deck.size(); ++i) 
        {
            if (i % 2 == 0) 
            {
                this->_player1.takeCard(deck[i]);
            } 
            else 
            {
                this->_player2.takeCard(deck[i]);
            }
        }
    }

    void Game::printLastTurn()
    {
        cout << this->_turns.back() << endl;
    }

    void Game::playTurn()
    {
        string error = "";
        if (this->_player1.stacksize() == 0)
        {
            error = "ERROR: " + this->_player1.getName() + "has no more cards to play with";
            throw invalid_argument{error};
        }
        if (this->_player2.stacksize() == 0)
        {
            error = "ERROR: " + this->_player2.getName() + "has no more cards to play with";
            throw invalid_argument{error};
        }
        if (&this->_player1 == &this->_player2)
        {
            error = "ERROR: Player can't play against himself";
            throw invalid_argument{error};
        }
        Card player1Card = this->_player1.retrieve(), player2Card = this->_player2.retrieve();
        if (player1Card.getValue() > player2Card.getValue() || player1Card.getValue() == 1 && player2Card.getValue() > 2)
        {

        }
        if (player1Card.getValue() == player2Card.getValue())
        {
            this->_draws = this->_draws + 1;
        }
    }

    void Game::playAll()
    {
        while (this->_player1.stacksize() > 0) // Doesn't matter which player is used for this condition
        {
            playTurn();
        }
    }

    void Game::printWiner()
    {
        if (this->_player1.cardesTaken() > this->_player2.cardesTaken())
        {
            cout << "The winner in this game is: " << this->_player1.getName() << endl;
        }
        else if (this->_player1.cardesTaken() < this->_player2.cardesTaken())
        {
            cout << "The winner in this game is: " << this->_player2.getName() << endl;
        }
        else
        {
            cout << "It's a draw" << endl;
        }
    }

    void Game::printLog()
    {
        for (size_t i = 0; i < this->_turns.size(); i++)
        {
            cout << this->_turns.at(i) << endl;
        }
    }

    void Game::printStats()
    {
        cout << "Stats of the player: " << this->_player1.getName() << endl;
        cout << "win rate: " << this->_player1.getGamesWon() / this->_player1.getGamesPlayed() << endl;
        cout << "cards won: " << this->_player1.cardesTaken() << endl;
        cout << endl;
        cout << "Stats of the player: " << this->_player2.getName() << endl;
        cout << "win rate: " << this->_player2.getGamesWon() / this->_player2.getGamesPlayed() << endl;
        cout << "cards won: " << this->_player2.cardesTaken() << endl;
        cout << endl;
        cout << "draw rate: " << this->_draws / this->_player1.getGamesPlayed() << endl; // Doesn't matter which player is used for this calculation
    }
}