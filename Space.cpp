/*
 * ============================================================================
 *
 *       Filename:  Space.cpp
 *
 *    Description:  This is the source file for Space class
 *             
 *           Date:  6/11/2019
 *
 *         Author:  TANYA YEU
 *   Organization:  Oregon State University
 *
 * ============================================================================
 */
#include "Space.hpp"

Space::Space()
{

}

string Space::getType()
{
    return type;
}
void Space::setName(string n)
{
    name = n;
}
string Space::getName()
{
    return name;
}

Space::~Space()
{

}

void Space::setIsBossDefeated()
{
    BossDefeated = true;
}

bool Space::isBossDefeated()
{
    return BossDefeated;
}
