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
#include "Space.hpp"

class Game
{
private:
    int townHealth;
    Character *player;
    Space *Home,
          *Rivendell,
          *Fangorn,
          *Mirkwood,
          *Deadwood,
          *Moria,
          *playerLoc;
    
public:
    Game();
    void playGame();
    void travel(int dir);
    void createMap();
    void displayArea();
    void printMap();
    bool isValidDir(int dir);
    void intro();
    ~Game();
};
#endif

