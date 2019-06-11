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
using std::cout;
using std::endl;

Dungeon::Dungeon()
{
    type = "Dungeon";
}
void Dungeon::printInfo()
{
    cout << "You have entered the Dungeon Moria.";
}

void Dungeon::spawnEnemy()
{
    //spawn enemy
}

void Dungeon::interact()
{
    cout << "1. Explore\n";
    cout << "2. ";
}
Dungeon::~Dungeon()
{

}


