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
    cout << "You have entered a town. You can choose one of the following";
    cout << " options:" << endl;
}


Town::~Town()
{

}
