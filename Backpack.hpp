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
    Item *head, *tail;
    int size = 6;
public:
    Backpack();
    ~Backpack();
    void showBackpack(Character *p);
    void add(Item *item);
    void removeItem(string name);
    int  count();
};
#endif
