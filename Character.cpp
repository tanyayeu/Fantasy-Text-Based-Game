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
#include <iostream>
using std::cout;
using std::endl;

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

void Character::openBP()
{
    if(backpack.empty())
    {
        cout << "Your backpack is empty" << endl << endl;
    }
    else
    {
        for(int i = 0; i<backpack.size(); i++)
        {
            cout << backpack[i] << " ";
        }
        cout << endl;
    }
}

void Character::addToBP(char x)
{
    if(backpack.size() > bpSize)
    {
        cout << "Your backpack is full!" << endl;
        return;
    }
    else
    {
        backpack += x;
    }
}
