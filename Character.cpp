/*
 * ============================================================================
 *
 *       Filename:  Character.cpp
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
#include "Character.hpp"

Character::Character()
{
}

int Character::getHP()
{
    return HP;
}

void Character::setHP(int n)
{
    HP = n;
}

string Character::getType()
{
    return type;
}

void Character::recover(int n)
{
    HP+= n;
    if(HP>maxHP)
    {
        HP = maxHP;
    }
}

int Character::getMaxHP()
{
    return maxHP;
}

Character::~Character()
{

}

int Character::getGold()
{
    return gold;
}

void Character::setGold(int g)
{
    gold =g;
}
