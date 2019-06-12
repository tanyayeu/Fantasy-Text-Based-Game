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

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  Space()
 *  Description:  Default constructor
 * =========================================================================
 */
Space::Space()
{
    hasGoods = false;
    BossDefeated = false;
}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  getType()
 *  Description:  This function returns space type
 * =========================================================================
 */
string Space::getType()
{
    return type;
}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  setName getName
 *  Description:  These functions set the name and get the name of the space
 * =========================================================================
 */
void Space::setName(string n)
{
    name = n;
}
string Space::getName()
{
    return name;
}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  ~Space()
 *  Description:  Deconstructor
 * =========================================================================
 */
Space::~Space()
{

}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  setIsBossDefeated
 *  Description:  Changes the status of BossDefeated
 * =========================================================================
 */
void Space::setIsBossDefeated(bool x)
{
    BossDefeated = x;
}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  isBossDefeated
 *  Description:  Returns the bool BossDefeated
 * =========================================================================
 */
bool Space::isBossDefeated()
{
    return BossDefeated;
}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  setHasGoods
 *  Description:  Changes status of hasGoods
 * =========================================================================
 */
void Space::setHasGoods(bool x)
{
    hasGoods = x;
}
