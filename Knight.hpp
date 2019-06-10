/*
 * ============================================================================
 *
 *       Filename:  Knight.hpp
 *
 *    Description:  This is the header file for the Knight class
 *           
 *           Date:  6/11/2019
 *
 *         Author:  TANYA YEU
 *   Organization:  Oregon State University
 *
 * ============================================================================
 */
#ifndef KNIGHT_HPP
#define KNIGHT_HPP
#include "Die.hpp"
#include "Character.hpp"

class Knight: public Character
{
public:
    Knight();
    int attack() override;
    int defend() override;
    ~Knight();
    Die *d6 = nullptr;
};
#endif