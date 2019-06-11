/*
 * ============================================================================
 *
 *       Filename:  Character.hpp
 *
 *    Description:  This is the header file for the Character class
 *           
 *           Date:  6/11/2019
 *
 *         Author:  TANYA YEU
 *   Organization:  Oregon State University
 *
 * ============================================================================
 */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>
using std::string;

class Character
{
protected:
    int HP, maxHP, gold; //health points
    string type;
    Character();

public:
    virtual int attack() = 0;
    virtual int defend() = 0;
    int getHP();
    string getType();
    void recover(int n); //for potions
    int getMaxHP();
    virtual void printStats() = 0;
    virtual ~Character();
    int getGold();
    void setGold(int g);
};
#endif

