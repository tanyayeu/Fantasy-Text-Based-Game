/*
 * ============================================================================
 *
 *       Filename:  Character.cpp
 *
 *    Description:  This is the source file for Character class
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

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  Character()
 *  Description:  Default constructor
 * =========================================================================
 */
Character::Character()
{
    backpack = "";
}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  getHP() setHP(int)
 *  Description:  These get and set HP for the character
 * =========================================================================
 */
int Character::getHP()
{
    return HP;
}

void Character::setHP(int n)
{
    HP = n;
}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  getType
 *  Description:  This returns the character type
 * =========================================================================
 */
string Character::getType()
{
    return type;
}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  recover(int n)
 *  Description:  This recovers the players health
 * =========================================================================
 */
void Character::recover(int n)
{
    HP+= n;
    if(HP>maxHP)
    {
        HP = maxHP;
    }
}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  getMaxHP
 *  Description:  This returns the characters maxhP
 * =========================================================================
 */
int Character::getMaxHP()
{
    return maxHP;
}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  ~Character()
 *  Description:  Deconstructor
 * =========================================================================
 */
Character::~Character()
{

}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  getGold setGold
 *  Description:  Returns the characters gold and sets the gold
 * =========================================================================
 */
int Character::getGold()
{
    return gold;
}

void Character::setGold(int g)
{
    gold =g;
}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  oepnBP()
 *  Description:  This function opens the backpack and displays the conent
 * =========================================================================
 */
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

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  addToBP(char)
 *  Description:  Adds a char to represent the item into the string
 * =========================================================================
 */
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

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  getNumBP
 *  Description:  returns the number of items in the backpack
 * =========================================================================
 */
int Character::getNumBP()
{
    return backpack.size();
}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  useItem
 *  Description:  This function uses the item and removes it from the string
 * =========================================================================
 */
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

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  isEmpty
 *  Description:  Checks whether the backpack is empty
 * =========================================================================
 */
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

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  hasRevive
 *  Description:  Checks the backpack for any revives
 * =========================================================================
 */
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

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  useRevive
 *  Description:  uses the revive and removes it from the backpack
 * =========================================================================
 */
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

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  isAlive()
 *  Description:  Checks if player is still alive and returns true or false
 * =========================================================================
 */
bool Character::isAlive()
{
    bool alive = true;
    if(this->getHP()<=0)
    {
        alive = false;
    }
    return alive;
}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  hasKey
 *  Description:  Checks the backpack for a key and returns true or false
 * =========================================================================
 */
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
