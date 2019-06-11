/*
 * ============================================================================
 *
 *       Filename:  Town.cpp
 *
 *    Description:  This is the source file for Town class
 *             
 *           Date:  6/11/2019
 *
 *         Author:  TANYA YEU
 *   Organization:  Oregon State University
 *
 * ============================================================================
 */
#include "Town.hpp"
#include <iostream>
#include <string>
#include "getInput.hpp"
using std::string;
using std::cout;
using std::endl;

Town::Town()
{
    type = "Town";
}


void Town::printInfo()
{
    cout << "== " << this->getName() << " ==" << endl;
    cout << "You have entered a town. From here you can rest up or";
    cout << " buy potions." << endl;
}

void Town::interact(Character *p, int &townHealth)
{
    int input;
    do
    {
        cout << "== " << this->getName() << " =="<< endl;
        cout << "1. Rest - You gain 5HP but the town loses 5HP" << endl;
        cout << "2. Go to shop" << endl;
        cout << "3. Continue on" << endl;
        input = getInput(1,3);
        switch(input)
        {
            case 1:
                p->recover(5);
                cout << "You now have " << p->getHP() << "HP" << endl;
                townHealth -=5;
                cout << "Town Health: " << townHealth <<"HP"<< endl;
                break;
            case 2:
                int input2;
                if(p->getGold()>0)
                {
                    do
                    {
                        cout << "\n== At the shop ==" << endl;
                        cout << "Gold: " << p->getGold() <<"g" << endl;
                        cout << "1. Buy Potion....+5HP....10g" << endl;
                        cout << "2. Buy Hi-Potion.+10HP...15g" << endl;
                        cout << "3. Exit" << endl;
                        input2= getInput(1,3);
                        switch(input2)
                        {
                            case 1:
                                //add stuff to backpack
                                cout << "That'll be 10g, thanks!" << endl;
                                p->setGold(p->getGold()-10);
                                p->addToBP('P');
                                cout << "You have " << p->getNumBP() << " items" << endl;
                                break;
                            case 2:
                                //add hi potion to backpack
                                cout << "That'll be 15g, thanks!" << endl;
                                p->setGold(p->getGold()-15);
                                p->addToBP('H');
                                break;
                            case 3:
                                break;

                        }
                        if(p->getGold()<0)
                        {
                            cout << "== Shopkeep: HEY! You owe me money! ==\n" << endl;
                        }
                    }while(input2!=3 && p->getGold()>=10);
                }
                else
                {
                    cout << "== How you gonna shop with no money? ==\n" << endl;
                }
                break;
            case 3:
                break;
        }
    }while(input!=3);
}

Town::~Town()
{

}
