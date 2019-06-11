/*
 * ============================================================================
 *
 *       Filename:  Dungeon.cpp
 *
 *    Description:  This is the source file for Dungeon class
 *             
 *           Date:  6/11/2019
 *
 *         Author:  TANYA YEU
 *   Organization:  Oregon State University
 *
 * ============================================================================
 */
#include "Dungeon.hpp"
#include <iostream>
#include "getInput.hpp"
#include "Enemy.hpp"
using std::cout;
using std::endl;

Dungeon::Dungeon()
{
    type = "Dungeon";
    BossDefeated = false;
    creature = nullptr;
    finalBoss = nullptr;
}
void Dungeon::printInfo()
{
    cout << "You have entered the Dungeon Moria. It is dark and wet, and";
    cout << " you can't see a damn thing." << endl << endl;
}

void Dungeon::interact(Character *p, int &townHealth, Backpack *bp)
{
    int input, chance;
    cout << "Do you want to light a torch? If you light a torch, you will";
    cout << " alert the creatures of\nyour presence. If you don't, you will";
    cout << "be at a disadvantage fighting the wizard." << endl;
    cout << "1. Yes. Light torch (battle)" << endl;
    cout << "2. No. stay in the dark (-5HP)" << endl;

    //torch action
    input = getInput(1,2);
    switch(input)
    {
        case 1:
            cout << "You light a torch. A creature starts screeching";
            cout << " and approaches you." << endl;
            isLit = true;
            battle(p,creature);
            break;
        case 2:
            cout << "You have chosen to stay in the dark (-5HP)" <<endl;
            p->setHP(p->getHP()-5);
            isLit = false;
            break;

            //end torch consequences
    }
    cout << "You venture deeper into the dungeon..." << endl;
    chance = rand() % 10 + 1;
    if(isLit && chance >=5) //if lit, 50% chance to battle again
    {
        cout << "Another creature is alerted of your presence!" << endl;
        battle(p,creature);
    }
}
Dungeon::~Dungeon()
{

}

void Dungeon::battle(Character* p, Character *creature)
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
        cout << "You were defeated!" << endl;
    }
    delete creature;

}




