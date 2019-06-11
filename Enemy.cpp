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
Enemy::Enemy()
{
    HP = 10;
    maxHP = 10;
    d12 = new Die(12);
    type = "Enemy";
}

Enemy::attack()
{
    return d12->rollDie();
}

Enemy::defend()
{
    int roll= d12->rollDie();
    if(roll==12)
    {
        recover(5);
    }
    return roll;
}

void Enemy::printStats()
{
    cout << "== Enemy Stats ==" << endl;
    cout << "HP:     " << HP << endl;
    cout << "Attack:  1d12" << endl;
    cout << "Defense: 1d12" << endl;
    cout << "=================" << endl;
}

Enemy::~Enemy()
{
    delete d12;
    d12 = nullptr;
}

