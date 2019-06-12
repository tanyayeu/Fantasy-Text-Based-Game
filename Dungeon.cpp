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

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  Dungeon()
 *  Description:  Default constructor. Initializes variables
 * =========================================================================
 */
Dungeon::Dungeon()
{
    type = "Dungeon";
    BossDefeated = false;
    creature = nullptr;
    finalBoss = nullptr;
}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  printInfo
 *  Description:  Prints information about the space
 * =========================================================================
 */
void Dungeon::printInfo()
{
    cout << "You have entered the Dungeon Moria. It is dark and wet, and";
    cout << " you can't see a damn thing." << endl << endl;
}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  Interact(Character*, int&)
 *  Description:  This takes the character pointer and townhealth by ref
 *                and interacts with the space. In the dungeon, the user
 *                can choose to light a torch and there will be different
 *                outcomes. then they battle the final boss.
 * =========================================================================
 */
void Dungeon::interact(Character *p, int &townHealth)
{
    int input, chance;
    finalBoss = new Enemy();
    cout << "Do you want to light a torch? If you light a torch, you will";
    cout << " alert the creatures of\nyour presence. If you don't, you will ";
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
            creature = new Enemy;
            battle(p,creature);
            delete creature;
            break;
        case 2:
            cout << "You have chosen to stay in the dark (-5HP)" <<endl;
            p->setHP(p->getHP()-5);
            isLit = false;
            break;
            //end torch consequences
    }

    //continue if player is still alive
    if(p->isAlive() == true)
    {
        cout << "You venture deeper into the dungeon..." << endl;
        chance = rand() % 10 + 1;
        //if its lit, higher chance of fighting again
        if(isLit && chance >=3) 
        {
            cout << "Another creature is alerted of your presence!" << endl;
            creature = new Enemy;
            battle(p,creature);
            delete creature;
        }
        //end chance encounter
        if(p->isAlive()==true)
        {
            cout << "\nYou're in the very depths of Moria now... You see the Dark Wizard";
            cout << " doing... THINGS" << endl;
            cout << "== YOU: HEY PINHEAD!" << endl;
            cout << "== HIM: Who you callin a pinhead??" << endl << endl;
            finalBoss->setHP(30);
            battle(p,finalBoss);
            if(p->isAlive()==true)
            {
                this->setIsBossDefeated(true);
            }
        }
    }
}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  ~Dungeon
 *  Description:  Deconstructor
 * =========================================================================
 */
Dungeon::~Dungeon()
{
    delete finalBoss;
    finalBoss = nullptr;
}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  battle
 *  Description:  This function simulates a battle and displays the results
 * =========================================================================
 */
void Dungeon::battle(Character* p, Character *creature)
{
    int attackRoll,defenseRoll,totalDamage, input,itemIndex,choice;
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
        cout << "You attacked the Enemy for "<< totalDamage;
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
            cout << "The Enemy attacked you for "<<totalDamage;
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
        cout << "You defeated the Enemy!" << endl;
        cout << "Your HP:  " << p->getHP() << "HP" <<endl;
        if(p->isAlive() == true)
        {
            do
            {
                cout << "1. Open backpack" << endl << "2. Keep going" << endl;
                input = getInput(1,2);
                if(input ==1)
                {
                    p->openBP();
                    if(p->isEmpty() == false)
                    {
                        cout << "Use an item?" << endl;
                        cout << "1. Yes\n" << "2. No\n";
                        choice = getInput(1,2);
                        if(choice ==1)
                        {
                            cout << "Which item would you like to use?" << endl;
                            itemIndex = getInput(1,p->getNumBP());
                            p->useItem(itemIndex);
                        }
                    }

                }
            }while(input!=2);

        }

    }
    else
    {
        cout <<"You have been defeated..the town gets completely overrun!" << endl;
    }

}


