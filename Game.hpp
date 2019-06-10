/*
 * ============================================================================
 *
 *       Filename:  Game.hpp
 *
 *    Description:  This is the header file for Game class
 *           
 *           Date:  6/11/2019
 *
 *         Author:  TANYA YEU
 *   Organization:  Oregon State University
 *
 * ============================================================================
 */

#ifndef GAME_HPP
#define GAME_HPP
#include <string>
#include "Character.hpp"
using std::string;

class Game
{
private:
    int attackRoll, defenseRoll, totalDamage;
    Character *player;
public:
    Game();
    void playGame();
    void createMap();
    ~Game();
};
#endif
