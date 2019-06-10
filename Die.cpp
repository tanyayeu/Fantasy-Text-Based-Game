/*
 * =========================================================================
 *
 *       Filename:  Die.cpp
 *
 *    Description:  This is the source file for the Die class. 
 *
 *           Date:  5/12/2019
 *
 *         Author:  TANYA YEU
 *   Organization:  Oregon State Univeristy
 *
 * =========================================================================
 */

#include "Die.hpp"
#include <ctime>
#include <cstdlib> //for rand

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  Die()
 *  Description:  This is the default constructor for Die. It takes an int 
 *                to set as the sides of the die.
 * =========================================================================
 */
Die::Die(int ns)
{
    N = ns;
}
/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  rollDie()
 *  Description:  This function returns a random number between 1 and N 
 *                for the die roll action.
 * =========================================================================
 */
int Die::rollDie()
{
    return rand() % N + 1; //random number between N and 1
}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  ~Die()
 *  Description:  This is a virtual destructor for the Die class.
 *                https://www.geeksforgeeks.org/virtual-destructor/
 * =========================================================================
 *//*  
Die::~Die()
{
    
}
*/
