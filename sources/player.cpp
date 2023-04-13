/**
 * @file player.cpp
 * @author Tom Koltunov (tomkoltunov@gmail.com)
 * @brief Implementation for 'player' object
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
    Player::Player(string name)
    {
        this->_name = name;
        this->_cardsTaken = 0;
        this->_gamesWon = 0;
        this->_gamesPlayed = 0;
    }

    int Player::stacksize()
    {
        return this->_stack.size();
    }

    int Player::cardesTaken()
    {
        return this->_cardsTaken;
    }

    string Player::getName()
    {
        return this->_name;
    }

    int Player::getGamesWon()
    {
        return this->_gamesWon;
    }

    void Player::setGamesWon(int number)
    {
        this->_gamesWon = number;
    }

    int Player::getGamesPlayed()
    {
        return this->_gamesPlayed;
    }

    void Player::setGamesPlayed(int number)
    {
        this->_gamesPlayed = number;
    }

    Card Player::retrieve()
    {
        Card answer = this->_stack.back();
        this->_stack.pop_back();
        return answer;
    }

    void Player::takeCard(Card card)
    {
        this->_stack.push_back(card);
    }
}