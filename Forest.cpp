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
#include "getInput.hpp"
using std::cout;
using std::endl;
using std::string;

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  Forest()
 *  Description:  Default constructor
 * =========================================================================
 */
Forest::Forest()
{
    type = "Forest";
}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  printInfo()
 *  Description:  This function prints info about the space
 * =========================================================================
 */
void Forest::printInfo()
{
    cout << "== " << getName() << " ==" << endl;
    cout << "You have entered the forest. Enemies lie ahead!\n";
    cout << "Keep your wits about you and be careful!" << endl << endl;
}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  interact
 *  Description:  This function takes the character and town health as 
 *                parameters. It creates an enemy and calls battle.
 * =========================================================================
 */
void Forest::interact(Character *p, int &townHealth)
{
    cout << "A creature has appeared!" << endl;
    creature = new Enemy;
    battle(p,creature, townHealth);
    delete creature;
    creature = nullptr;
}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  ~Forest()
 *  Description:  Deconstructor
 * =========================================================================
 */
Forest::~Forest()
{
}


/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  battle
 *  Description:  This function simulates a battle. If the creature is
 *                defeated, it has a 45% drop rate for the key to Moria.
 *                If town health is low, then it has 100% drop rate.
 * =========================================================================
 */
void Forest::battle(Character* p, Character *creature, int townHealth)
{
    int attackRoll,defenseRoll,totalDamage, chance = 0;
    creature->printStats();
    cout << endl;
    p->printStats();
    cout << "== BATTLING ==" << endl;
    do
    {
        //player attacks creature
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
        //creature attacks player
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
            if(p->getHP() <=0 && p->hasRevive())
            {
                cout << "You have a Revive in your backpack!" << endl;
                p->useRevive();
            }
            cout<<"------------------------------------------------------------" <<endl;
        }
    }while(p->getHP()>0 && creature->getHP()>0);
    if(p->getHP()>0)
    {
        cout << "You defeated the creature! +5g" << endl;
        cout << "Your HP:  " << p->getHP() << "HP" <<endl << endl;
        p->setGold(p->getGold()+5);

        chance = rand() % 100 + 1;
        //key has 45% drop rate
        if(chance<=45 && p->hasKey() == false)
        {
            cout << "The creature dropped a key!" << endl;
            p->addToBP('K');
        }
        if(townHealth<=15 && p->hasKey() == false)
        {
            cout << "The creature dropped a key!" << endl;
            p->addToBP('K');
        }
    }
    else
    {
        cout << "You were defeated... you limp away with 1HP" << endl;
        p->setHP(1);
    }
}

