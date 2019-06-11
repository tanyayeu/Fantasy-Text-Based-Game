/*
 * ============================================================================
 *
 *       Filename:  Enemy.cpp
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
#include "Enemy.hpp"
#include <cstdlib>
Enemy::Enemy()
{
    HP = rand() % (18-10 +1) + 10; 
    d12 = new Die(12);
    maxHP = HP;
    type = "Enemy";
}

int Enemy::attack()
{
    return d12->rollDie();
}

int Enemy::defend()
{
    int roll= d12->rollDie();
    return roll;
}

void Enemy::printStats()
{
    cout << "== Enemy Stats ==" << endl;
    cout << "HP:      " << HP << endl;
    cout << "Attack:  1d12" << endl;
    cout << "Defense: 1d12" << endl;
    cout << "=================" << endl;
}

Enemy::~Enemy()
{
    delete d12;
    d12 = nullptr;
}

