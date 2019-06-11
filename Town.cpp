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
#include <String>
#include "Item.hpp"
#include "getInput.hpp"
#include "Potion.hpp"
using std::string;
using std::cout;
using std::endl;

Town::Town()
{
    type = "Town";
}

void Town::printInfo()
{
    cout << "You have entered the town of " << this->getName() << ".";
}

void Town::interact(Character *p, int &townHealth, Backpack *&backpack)
{
    int input;
    //1 explore
    cout << "1. Explore" << endl;
    /////////find random item

    //2 rest
    cout << "2. Rest" << endl;
    ////////+5 health, -5 townhealth
    cout << "3. Go to shop" << endl;
    //3 Go to shop
    //4 contine on
    input = getInput(1,4);
    switch(input)
    {
        case 1:
            //explore
            break;
        case 2:
            p->recover(5);
            cout << "You now have " << p->getHP() << " HP" << endl;
            townHealth -=5;
            cout << "Town Health: " << townHealth << endl;
            break;
        case 3:
            cout << "== At the shop ==" << endl;
            int input2;
            do
            {
                cout << "Gold: " << p->getGold() <<"g" << endl;
                cout << "1. Buy Potion....+5HP....10g" << endl;
                cout << "2. Buy Hi-Potion.+10HP...15g" << endl;
                cout << "3. Exit" << endl;
                input2= getInput(1,3);
                switch(input2)
                {
                    case 1:
                        Item *potion = new Potion;
                        p->setGold(p->getGold()-10);
                        backpack->add(potion);

                }
            }while(input2!=6 && p->getGold()>10);
    }
}
void Town::explore()
{
    
}


void Town::spawnEnemy()
{

}
Town::~Town()
{

}
