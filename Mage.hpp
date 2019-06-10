/*
 * ============================================================================
 *
 *       Filename:  Mage.hpp
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
#ifndef MAGE_HPP
#define MAGE_HPP
#include "Character.hpp";
#include "Die.hpp"
#include <iostream>
using std::cout;
using std::endl;

class Mage: public Character
{
public:
    Mage(); //constructor
    int attack() override;
    int defend() override;
    Die *d12 = nullptr;
    void burn();
};
#endif

