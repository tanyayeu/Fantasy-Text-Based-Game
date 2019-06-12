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
    backpack = "";
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
    if(isEmpty())
    {
        cout << "== BACKPACK ==" << endl;
        cout << "Your backpack is empty" << endl << endl;
    }
    else
    {
        cout << "== BACKPACK ==" << endl;
        for(string::size_type i = 1; i<=backpack.size(); i++)
        {
            cout << "["<<i<<"]" << " " << backpack[i-1] << endl;
        }
        cout << endl;
    }
}

void Character::addToBP(char x)
{
    if(backpack.size() >= bpSize)
    {
        cout << "== Your backpack is full! Stop wasting gold! ==" << endl << endl;
        return;
    }
    if(backpack.size() <bpSize)
    {
        backpack += x;
    }
}

int Character::getNumBP()
{
    return backpack.size();
}

void Character::useItem(int n)
{
    n = n-1;
    if(backpack[n] == 'P')
    {
        recover(5);
        cout << "Using a potion... You now have " << this->getHP() << "HP" << endl;
        backpack.erase(backpack.begin() + n);
        return;
    }
    if(backpack[n] == 'H')
    {
        recover(10);
        cout << "Using a Hi-Potion... You now have " << this->getHP() << "HP" << endl;
        backpack.erase(backpack.begin() + n);
        return;
    }
    if(backpack[n] == 'R')
    {
        cout << "Let's save that for battle!" << endl;
    }
    if(backpack[n] == 'K')
    {
        cout << "You'll need that key to enter the dungeon." << endl;
    }
}
//https://www.geeksforgeeks.org/stdstringerase-in-cpp/

bool Character::isEmpty()
{
    if(backpack.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Character::hasRevive()
{
    bool r;
    for(string::size_type i=0; i<backpack.size(); i++)
    {
        if(backpack[i] == 'R')
        {
            r = true;
            break;
        }
        else
        {
            r = false;
        }
    }
    return r;
}

void Character::useRevive()
{
    int index = 0;
    for(string::size_type i=0; i<backpack.size(); i++)
    {
        if(backpack[i] == 'R')
        {
            index = i;
            break;
        }
    }
    recover(20);
    cout << "Using a revive... You now have " << this->getHP() << "HP" << endl;
    backpack.erase(backpack.begin() + index);
    return;
}

bool Character::isAlive()
{
    bool alive = true;
    if(this->getHP()<=0)
    {
        alive = false;
    }
    return alive;
}

bool Character::hasKey()
{
    bool r;
    for(string::size_type i=0; i<backpack.size(); i++)
    {
        if(backpack[i] == 'K')
        {
            r = true;
            break;
        }
        else
        {
            r = false;
        }
    }
    return r;
}
