/**
 * @file card.hpp
 * @author Tom Koltunov (tomkoltunov@gmail.com)
 * @brief Headers for 'card' object
 * @version 0.2
 * @date 2023-04-13
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
    class Card
    {
        int _value; // The value of the card can be a number in range 2-10 or one of the following symbols: J - Jack, Q - Queen, K - King, A - Ace.
                       // The hierarchy of the values of the cards is as described a line above, with the only change that determines that
                       // 2 is higher than A and so 2 is the highest value in the hierarchy.
        string _type; // The type of the card can be one of the following: "Hearts", "Diamonds", "Clubs", "Spades".

        public:
            Card(int value, string type); // A constructor for this class which receives the card's value and type as parameters.
            int getValue(); // 'Getter' function to the class
            string getType(); // 'Getter' function to the class
    };
}