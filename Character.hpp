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
    int bpSize = 6;
    string backpack;

public:
    virtual int attack() = 0;
    virtual int defend() = 0;
    int getHP();
    string getType();
    void recover(int n); //for potions
    void setHP(int n);
    int getMaxHP();
    virtual void printStats() = 0;
    virtual ~Character();
    int getGold();
    void setGold(int g);
    void addToBP(char x);
    void useItem(int n);
    void openBP();
    int getNumBP();
    bool isEmpty();
    bool hasRevive();
    void useRevive();
    bool isAlive();
    bool hasKey();
};
#endif

