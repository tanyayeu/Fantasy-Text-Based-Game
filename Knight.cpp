/*
 * ============================================================================
 *
 *       Filename:  Knight.cpp
 *
 *    Description:  This is the source file for the Knight class
 *             
 *           Date:  6/11/2019
 *
 *         Author:  TANYA YEU
 *   Organization:  Oregon State University
 *
 * ============================================================================
 */

#include "Character.hpp"
#include "Knight.hpp"
#include <iostream>
using std::cout;
using std::endl;


/* 
 * ===  FUNCTION  =============================================================
 *         Name:  Knight()
 *  Description:  This is the default constructor for Knight
 * ============================================================================
 */
Knight::Knight()
{
    HP = 20;
    maxHP = 20;
    type = "Knight";
    d6 = new Die(6); //knight will attack with 2d6
    gold = 50;
}


/* 
 * ===  FUNCTION  =============================================================
 *         Name:  int attack()
 *  Description:  The knight will roll a 2d6 to inflict damage
 * ============================================================================
 */
int Knight::attack()
{
    int roll1 = d6->rollDie();
    int roll2 = d6->rollDie();
    return roll1+roll2;
}

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  int defend()
 *  Description:  The knight will roll a 2d6 for defense
 * ============================================================================
 */
int Knight::defend()
{
    int roll1 = d6->rollDie();
    int roll2 = d6->rollDie();
    return roll1+roll2;
}

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  printStats()
 *  Description:  This function prints the stats of the Character
 * ============================================================================
 */
void Knight::printStats()
{
    cout << "== Knight Stats ===" << endl;
    cout << "HP:      " << HP << endl;
    cout << "Attack:  2d6" << endl;
    cout << "Defense: 2d6" << endl;
    cout << "===================" << endl;

}

/* 
 * ===  FUNCTION =============================================================
 *         Name:  getGold()
 *  Description:  This returns gold
 * ============================================================================
 */
int Knight::getGold()
{
    return gold;
}

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  ~Knight()
 *  Description:  Deconstructor. Deletes the die object and sets pointer to
 *                null
 * ============================================================================
 */
Knight::~Knight()
{
    delete d6;
    d6 = nullptr;
}
