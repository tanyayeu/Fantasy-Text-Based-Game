/*
 * ============================================================================
 *
 *       Filename:  Game.cpp
 *
 *    Description:  This is the source file for Game class
 *             
 *           Date:  6/11/2019
 *
 *         Author:  TANYA YEU
 *   Organization:  Oregon State University
 *
 * ============================================================================
 */
#include "Game.hpp"
#include "Character.hpp"
#include "Knight.hpp"
#include "Forest.hpp"
#include "getInput.hpp"
#include <iostream>
#include <ctime>
#include "Town.hpp"
#include "Dungeon.hpp"
#include "Space.hpp"
#include <cstddef>
using std::cout;
using std::endl;

Game::Game()
{
    player = new Knight;
    createMap();
    townHealth = 50;
    tipShown = false;
}

void Game::playGame()
{
    unsigned seed;
    seed = time(0);
    int choice, itemIndex, input;
    srand(seed);
    int dir; //direction to go in
    playerLoc = Home; //starting location is home
    //setting of story
    intro();

    player->printStats();
    cout << endl;

    //map of area
    printMap();

    while(townHealth>=0 && player->getHP() > 0 && playerLoc->isBossDefeated()==false&&townHealth >0)
    {
        cout << "Town Health: " << townHealth << "HP"<< endl;
        cout << "Your Health: " << player->getHP() << "HP" << endl; 
        cout << "Gold:        " << player->getGold() << "g" << endl<<endl;

        playerLoc->printInfo();
        playerLoc->interact(player, townHealth);
        
        if(player->isAlive()==true &&playerLoc->isBossDefeated()==false && townHealth>0)
        {
            do
            {
                cout << "== MENU ==" <<endl;
                cout << "1. Open backpack" << endl;
                cout << "2. Show map" << endl;
                cout << "3. Continue on" << endl;
                choice = getInput(1,3);
                switch(choice)
                {
                    case 1:
                        player->openBP();
                        if(player->isEmpty() == false)
                        {
                            cout << "Use an item?" << endl;
                            cout << "1. Yes\n" << "2. No\n";
                            input = getInput(1,2);
                            if(input ==1)
                            {
                                cout << "Which item would you like to use?" << endl;
                                itemIndex = getInput(1,player->getNumBP());
                                player->useItem(itemIndex);
                            }
                        }
                        break;
                    case 2:
                        printMap();
                        cout << endl;
                        break;
                    case 3:
                        break;
                };
            }while(choice!=3);
            displayArea();
            cout << "Where would you like to travel to?" << endl;
            cout << "Direction: ";
            dir = getInput(1,4);
            while(!isValidDir(dir, player))
            {
                cout << "That is not a valid direction." << endl;
                cout << "Direction: ";
                dir = getInput(1,4);
            }
            if(isValidDir(dir,player))
            {
                travel(dir);
            }

            townHealth -= 5;
        }
        if(player->isAlive() == false || townHealth <=0)
        {
            if(townHealth<=0)
            {
                cout << "The town has been completely overrun. You're too late\n";
            }
            cout << "Game over..." << endl;
        }
        if(player->isAlive() == true && playerLoc->isBossDefeated() == true)
        {
            cout << "== CONGRATULATIONS ==" << endl;
            cout << "The evil is defeated and you saved the town! The creatures";
            cout <<" disppear\ninto the night sky and you are heralded as a hero.\n";
        }
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << endl;
    }
}
void Game::intro()
{
    cout << "==INTRODUCTION================================================";
    cout <<"================";
    cout << endl;
    cout << "You are a Knight in a small town surrounded by forests.";
    cout << " Recently mysterious\ncreatures have began appearing and ";
    cout << "terrorizing the townspeople. It is said that\na Dark Wizard has";
    cout << " opened a portal in the Dungeon Moria. You have been tasked\n";
    cout << "with traveling to Moria and defeating him before the town is";
    cout << " overrun. You can\nchoose to travel to Rivendell first to get";
    cout << " supplies for your journey or head\nstraight to the dungeon.";
    cout << " Either way, you will have to travel through the\nforests ";
    cout << " where enemies lie. Each day, the town will lose 5HP. If Town HP";
    cout << " drops to 0\n or you lose all your HP the game is over.\n";
    cout << endl;
    cout << "== Backpack ==" << endl;
    cout << "Your backpack can hold up to 6 items."<<endl<<endl;
    cout << "== Towns ==" << endl;
    cout << "You can choose to rest up here or buy potions. If you rest,";
    cout << " you will gain 5HP,\nbut the town will lose 5HP. Rivendell";
    cout << " sells Revives. Spend your gold wisely!" << endl;
    cout << endl;
    cout << "== Forests ==" << endl;
    cout << "Creatures infest the forest. Prepare to battle there.\n";
    cout << "If you defeat the creatures you will get +5g" << endl<<endl;
    cout << "== Dungeon ==" << endl;
    cout << "You must defeat the Boss in the Dungeon to close the portal";
    cout << " and save your town. You will need a key to enter, you can find";
    cout << " one in the forest on a creature." << endl;
    cout << "==============================================================";
    cout <<"================";
    cout << endl << endl;
}

/* 
 * ===  FUNCTION =============================================================
 *         Name:  createMap()
 *  Description:  This function creates the map and links the areas together
 *============================================================================
 */
void Game::createMap()
{
    /*
       ____________________________________
       | Rivendell    | Mirkwood  | Moria   |
       |--------------|-----------|---------|
       | Fangorn      | Kirkwall  | Deadwood|
       |____________________________________|


*/
    Home = new Town;
    Home->setName("Kirkwall");
    Rivendell = new Town;
    Rivendell->setName("Rivendell");
    Fangorn = new Forest;
    Fangorn->setName("Fangorn");
    Mirkwood = new Forest;
    Mirkwood->setName("Mirkwood");
    Deadwood = new Forest;
    Deadwood->setName("Deadwood");
    Moria = new Dungeon;
    Moria->setName("Moria");

    Home->left = Fangorn;
    Home->right = Deadwood;
    Home->top = Mirkwood;
    Home->bottom = nullptr;

    Fangorn->left=nullptr;
    Fangorn->right = Home;
    Fangorn->top = Rivendell;
    Fangorn->bottom = nullptr;

    Mirkwood->top = nullptr;
    Mirkwood->right = Moria;
    Mirkwood->left = Rivendell;
    Mirkwood->bottom = Home;

    Rivendell->left = nullptr;
    Rivendell->top = nullptr;
    Rivendell->bottom = Fangorn;
    Rivendell->right = Mirkwood;
    Rivendell->setHasGoods(true);

    Moria->left = Mirkwood;
    Moria->bottom = Deadwood;
    Moria->right = nullptr;
    Moria->top = nullptr;

    Deadwood->top = Moria;
    Deadwood->left = Home;
    Deadwood->right = nullptr;
    Deadwood->bottom = nullptr;

}

/* 
 * ===  FUNCTION =============================================================
 *         Name:  printMap()
 *  Description:  This function prints the map of the region
 *============================================================================
 */
void Game::printMap()
{
    cout << "== MAP ==============================" << endl;
    cout << "| Rivendell    | Mirkwood  | Moria   |" << endl;
    cout<< "|--------------|-----------|---------|" << endl;
    cout << "| Fangorn      | Kirkwall  | Deadwood|" << endl;
    cout << "|====================================|"<< endl;
    cout << endl;
}

/* 
 * ===  FUNCTION =============================================================
 *         Name:  isValidDir(int dir)
 *  Description:  This function validates the direction. It checks whether
 *                there is a valid location to travel to based on the user's
 *                input.
 *============================================================================
 */
bool Game::isValidDir(int dir, Character *p)
{
    if(dir==1)
    {
        if(playerLoc->top == nullptr)
        {
            return false;
        }
        if(playerLoc->top->getName() == "Moria" && p->hasKey() == false)
        {
            cout << "You need a key to enter Moria" << endl;
            return false;
        }

        else
        {
            return true;
        }
    }
    if(dir==2)
    {
        if(playerLoc->right == nullptr)
        {
            return false;
        }
        if(playerLoc->right->getName() == "Moria" && p->hasKey() == false)
        {
            cout << "You need a key to enter Moria" << endl;
            return false;
        }
        else
        {
            return true;
        }
    }
    if(dir==3)
    {
        if(playerLoc->bottom == nullptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    if(dir==4)
    {
        if(playerLoc->left == nullptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

/* 
 * ===  FUNCTION =============================================================
 *         Name:  travel(int dir)
 *  Description:  This function takes an int and updates the player location
 *============================================================================
 */
void Game::travel(int dir)
{
    switch(dir)
    {
        case 1:
            playerLoc = playerLoc->top;
            break;
        case 2:
            playerLoc = playerLoc->right;
            break;
        case 3:
            playerLoc = playerLoc->bottom;
            break;
        case 4:
            playerLoc = playerLoc->left;
            break;
    }
}

/* 
 * ===  FUNCTION =============================================================
 *         Name:  displayArea()
 *  Description:  This function displays the surrounding areas that the user
 *                can travel to.
 *============================================================================
 */
void Game::displayArea()
{
    if(playerLoc->top !=nullptr)
    {
        cout << "1. North is " << playerLoc->top->getName() << " ";
        cout << playerLoc->top->getType() << endl;
    }
    if(playerLoc->right !=nullptr)
    {
        cout << "2. East is " << playerLoc->right->getName() << " ";
        cout << playerLoc->right->getType() << endl;
    }
    if(playerLoc->bottom != nullptr)
    {
        cout << "3. South is " << playerLoc->bottom->getName() << " ";
        cout << playerLoc->bottom->getType() << endl;
    }
    if(playerLoc->left !=nullptr)
    {
        cout << "4. West is " << playerLoc->left->getName() << " ";
        cout << playerLoc->left->getType() << endl << endl;
    }
}

/* 
 * ===  FUNCTION =============================================================
 *         Name:  ~Game()
 *  Description:  Destructor. This deletes the pointers and frees up the 
 *                memory
 *============================================================================
 */
Game::~Game()
{ 
    delete Home;
    Home = nullptr;
    delete Fangorn;
    Fangorn = nullptr;
    delete Mirkwood;
    Mirkwood = nullptr;
    delete Deadwood;
    Deadwood = nullptr;
    delete Moria;
    Moria = nullptr;
    delete Rivendell;
    Rivendell = nullptr;
    delete player;
    player = nullptr;
} 
