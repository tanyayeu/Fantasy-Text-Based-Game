/*
 * =========================================================================
 *
 *       Filename:  Die.hpp
 *
 *    Description:  This is the header file for the Die class.
 *                  This class has int N for number of sides and function 
 *                  to roll die
 *
 *           Date:  5/12/2019
 *
 *         Author:  TANYA YEU
 *   Organization:  Oregon State Univeristy
 *
 * =========================================================================
 */

#ifndef DIE_HPP
#define DIE_HPP

class Die
{
protected:
    int N; //number of sides

public:
    Die(int ns);
    int rollDie(); //return an int number rolled
    //Die(); //virtual destructor to ensure it is deleted properly
};

#endif

/* 
 * https://www.geeksforgeeks.org/virtual-function-cpp/
 * virtual allows pointer to derived class use the overriden
 */
