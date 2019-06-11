/*
 * ============================================================================
 *
 *       Filename:  Forest.cpp
 *
 *    Description:  This is the source file for Forest class
 *             
 *           Date:  6/11/2019
 *
 *         Author:  TANYA YEU
 *   Organization:  Oregon State University
 *
 * ============================================================================
 */
#include "Forest.hpp"
#include <iostream>
#include <string>
#include "Character.hpp"
#include "Space.hpp"
#include "Knight.hpp"
#include "Enemy.hpp"
#include "Backpack.hpp"
using std::cout;
using std::endl;
using std::string;

Forest::Forest()
{
    type = "Forest";
}

void Forest::printInfo()
{
    cout << "== " << getName() << " ==" << endl;
    cout << "You have entered the forest. Enemies lie ahead!\n";
    cout << "Keep your wits about you and be careful!" << endl << endl;
}

void Forest::interact(Character *p, int &townHealth, Backpack *b)
{
    int attackRoll, defenseRoll, totalDamage;
    cout << "A creature has appeared!" << endl;
    Character *creature = new Enemy;
    creature->printStats();
    cout << endl;
    p->printStats();
    cout << "== BATTLING ==" <<endl << endl;
    //battle sequence
    do
    {
        attackRoll = p->attack();
        defenseRoll = creature->defend();
        totalDamage = attackRoll - defenseRoll;
        if(totalDamage<0)
        {
            totalDamage = 0;
        }
        creature->setHP(creature->getHP()-totalDamage);
        if(p->getHP()>0 && creature->getHP() >0)
        {
            attackRoll = creature->attack();
            defenseRoll = p->defend();
            totalDamage = attackRoll - defenseRoll;
            if(totalDamage<0)
            {
                totalDamage = 0;
            }
            p->setHP(p->getHP()-totalDamage);
        }
        
    }while(p->getHP() > 0 && creature->getHP() >0);
    if(p->getHP() > 0)
    {
        cout << "You defeated the creature. You have " << p->getHP();
        cout << "HP left." << endl;
    }
    else
    {
        cout << "You were defeated!" << endl;
    }
    delete creature;
    creature = nullptr;
}

Forest::~Forest()
{
}
