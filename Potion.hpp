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
private:
    int recovery = 10;
public:
    Potion();
    void use(Character* player, Character *enemy);

};
#endif

#ifndef HIPOTION_HPP
#define HIPTION_HPP
#include "Potion.hpp"
class HiPotion: public Potion
{
private:
    int recovery = 10;
public:
    HiPotion();
};
#endif
