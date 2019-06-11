/*
 *============================================================================
 *
 *       Filename:  Item.hpp
 *
 *    Description:  This is the Item class header file
 *           
 *           Date:  6/10/2019
 *
 *         Author:  TANYA YEU
 *   Organization:  Oregon State University
 *
 *============================================================================
 */
#ifndef ITEM_HPP
#define ITEM_HPP
#include <iostream>
#include <string>
#include "Character.hpp"
using std::string;
class Item
{
protected:
    string name;
    Item *next, *prev;
public:
    void use(Character *player);
    string getName();
    friend class Backpack;
    ~Item();
};
#endif

