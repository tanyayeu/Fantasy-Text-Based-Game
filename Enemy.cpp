/*
 * ============================================================================
 *
 *       Filename:  Enemy.cpp
 *
 *    Description:  This is the enemy source file
 *             
 *           Date:  6/11/2019
 *
 *         Author:  TANYA YEU
 *   Organization:  Oregon State University
 *
 * ============================================================================
 */
#include "Enemy.hpp"
#include <cstdlib>

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  Enemy()
 *  Description:  Default constructor
 * =========================================================================
 */
Enemy::Enemy()
{
    HP = rand() % (18-10 +1) + 10; 
    d12 = new Die(12);
    maxHP = HP;
    type = "Enemy";
}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  attack defend
 *  Description:  These functions simulate dice rolls and returns the number
 * =========================================================================
 */
int Enemy::attack()
{
    return d12->rollDie();
}

int Enemy::defend()
{
    int roll= d12->rollDie();
    return roll;
}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  printStats()
 *  Description:  This function prints the stats
 * =========================================================================
 */
void Enemy::printStats()
{
    cout << "== Enemy Stats ==" << endl;
    cout << "HP:      " << HP << endl;
    cout << "Attack:  1d12" << endl;
    cout << "Defense: 1d12" << endl;
    cout << "=================" << endl;
}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  ~Enemy()
 *  Description:  Deconstructor. Frees memory
 * =========================================================================
 */
Enemy::~Enemy()
{
    delete d12;
    d12 = nullptr;
}

