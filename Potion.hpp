/*
 * ============================================================================
 *
 *       Filename:  Potion.hpp
 *
 *    Description:  
 *           
 *           Date:
 *
 *         Author:  TANYA YEU
 *   Organization:  Oregon State University
 *
 * ============================================================================
 */

#ifndef POTION_HPP
#define POTION_HPP
#include "Character.hpp"
#include "Item.hpp"
class Potion: public Item
{
protected:
    int recovery = 5;
public:
    Potion();
    void use(Character* player);

};
#endif

