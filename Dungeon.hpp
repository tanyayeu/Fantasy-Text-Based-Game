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
#include <string>
using std::string;

class Dungeon: public Space
{
public:
    void printInfo() override;
    void spawnEnemy() override;
    Dungeon();
    ~Dungeon();
    void interact() override;
    void explore() override;
};
#endif
