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
using std::cout;
using std::endl;
using std::string;

Forest::Forest()
{
    type = "Forest";
}

void Forest::spawnEnemy()
{
    //spawn some creepy crawly
}

void Forest::printInfo()
{
    cout << "You have entered the forest. Enemies lie ahead!\n";
    cout << "Keep your wits about you and be careful!" << endl;
}

Forest::~Forest()
{

}
