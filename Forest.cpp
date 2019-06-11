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
    cout << "A creature has appeared!" << endl;
    creature = new Enemy;
    creature->printStats();
    cout << endl;
    p->printStats();
    battle(p,creature);
}

Forest::~Forest()
{
}


void Forest::battle(Character* p, Character *creature)
{
    creature = new Enemy;
    int attackRoll,defenseRoll,totalDamage;
    creature->printStats();
    cout << endl;
    p->printStats();
    cout << "== BATTLING ==" << endl;
    do
    {
        attackRoll = p->attack();
        defenseRoll = creature->defend();
        totalDamage = attackRoll - defenseRoll;
        if(totalDamage<0)
        {
            totalDamage = 0;
        }
        cout << "You attack the creature for "<< totalDamage;
        cout << " damage." << endl;
        cout << "Your HP:  " << p->getHP() << "HP"<<endl;
        creature->setHP(creature->getHP()-totalDamage);
        cout << "Enemy HP: "<<creature->getHP() <<"HP"<<endl;
        cout << "------------------------------------------------------------" <<endl;

        if(p->getHP()>0 && creature->getHP()>0)
        {
            attackRoll = creature->attack();
            defenseRoll = p->defend();
            totalDamage = attackRoll - defenseRoll;
            if(totalDamage<0)
            {   
                totalDamage = 0;
            }
            cout << "The creature attacked you for "<<totalDamage;
            cout << " damage." << endl;
            p->setHP(p->getHP()-totalDamage);
            cout << "Your HP:  " << p->getHP()<<"HP"<<endl;
            cout << "Enemy HP: " <<creature->getHP()<<"HP\n";
            cout<<"------------------------------------------------------------" <<endl;
        }
    }while(p->getHP()>0 && creature->getHP()>0);
    if(p->getHP()>0)
    {
        cout << "You defeated the creature!" << endl;
        cout << "Your HP:  " << p->getHP() << "HP" <<endl;
    }
    else
    {
        cout << "You were defeated. Game over." << endl;
    }
    delete creature;

}

