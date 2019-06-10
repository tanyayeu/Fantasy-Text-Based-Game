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
}

void Game::playGame()
{
    unsigned seed;
    seed = time(0);
    srand(seed);
    playerLoc = Home; //starting location is home
    //setting
    cout << "You are knight in a small town surrounded by forests." << endl;
}

void Game::createMap()
{
    /*___________________________________
    | Rivendell    | Mirkwood  | Dungeon |
    |--------------|-----------|---------|
    | Fangorn      |   Home    | Deadwood|
    |____________________________________|


    */
    Home = new Town;
    Rivendell = new Town;
    Fangorn = new Forest;
    Mirkwood = new Forest;
    Deadwood = new Forest;
    Moria = new Dungeon;

    Home->left = Fangorn;
    Home->right = Deadwood;
    Home->top = Mirkwood;
    Home->bottom = nullptr;

    Fangorn->left=nullptr;
    Fangorn->right = Home;
    Fangorn->top = Rivendell;
    Fangorn->bottom = nullptr;

    Rivendell->left = nullptr;
    Rivendell->top = nullptr;
    Rivendell->bottom = Fangorn;
    Rivendell->right = Mirkwood;

    Moria->left = Mirkwood;
    Moria->bottom = Deadwood;
    Moria->right = nullptr;
    Moria->top = nullptr;

    Deadwood->top = Moria;
    Deadwood->left = Home;
    Deadwood->right = nullptr;
    Deadwood->bottom = nullptr;
    
}

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
