/*
 * ============================================================================
 *
 *       Filename:  Dungeon.hpp
 *
 *    Description:  This is the header file for Dungeon class
 *           
 *           Date:  6/11/2019
 *
 *         Author:  TANYA YEU
 *   Organization:  Oregon State University
 *
 * ============================================================================
 */
#ifndef DUNGEON_HPP
#define DUNGEON_HPP
#include "Space.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include <string>
using std::string;

class Dungeon: public Space
{
private:
    bool isLit;
public:
    void printInfo() override;
    Dungeon();
    ~Dungeon();
    void interact(Character *, int &, Backpack *) override;
    Character *creature, *finalBoss;
    void battle(Character *p, Character *creature);
};
#endif
