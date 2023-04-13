/**
 * @file card.cpp
 * @author Tom Koltunov (tomkoltunov@gmail.com)
 * @brief Implementation for 'card' object
 * @version 0.2
 * @date 2023-04-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "card.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace ariel
{
    Card::Card(int value, string type)
    {
        this->_value = value;
        this->_type = type;
    }

    int Card::getValue()
    {
        return this->_value;
    }

    string Card::getType()
    {
        return this->_type;
    }
}