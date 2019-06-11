/*
 * ============================================================================
 *
 *       Filename:  Enemy.hpp
 *
 *    Description:  This is the header file for Mage class
 *           
 *           Date:  6/11/2019
 *
 *         Author:  TANYA YEU
 *   Organization:  Oregon State University
 *
 * ============================================================================
 */
#ifndef ENEMY_HPP
#define ENEMY_HPP 
#include "Character.hpp"
#include "Die.hpp"
#include <iostream>
using std::cout;
using std::endl;

class Enemy: public Character
{
public:
    Enemy(); //constructor
    int attack() override;
    int defend() override;
    Die *d12 = nullptr;
    void printStats() override;
    ~Enemy();
};
#endif

