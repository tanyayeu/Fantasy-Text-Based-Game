/*
 * ============================================================================
 *
 *       Filename:  Backpack.hpp
 *
 *    Description:  This is the backpack class
 *           
 *           Date:  6/11/2019
 *
 *         Author:  TANYA YEU
 *   Organization:  Oregon State University
 *
 * ============================================================================
 */
#ifndef BACKPACK_HPP
#define BACKPACK_HPP
#include "Item.hpp"

class Backpack
{
private:
    Item *head;
    int size = 6;
public:
    Backpack();
    ~Backpack();
    void showBackpack();
    void add(Item *item);
    void removeItem(string name);
};
#endif
