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
    hasGoods = false;
    BossDefeated = false;
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

void Space::setIsBossDefeated(bool x)
{
    BossDefeated = x;
}

bool Space::isBossDefeated()
{
    return BossDefeated;
}

void Space::setHasGoods(bool x)
{
    hasGoods = x;
}
