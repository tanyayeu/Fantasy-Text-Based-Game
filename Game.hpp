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
#include "Item.hpp"

class Game
{
private:
    int attackRoll, defenseRoll, totalDamage, townHealth = 50;
    Character *player, *enemy;
    Space *Home,
          *Rivendell,
          *Fangorn,
          *Mirkwood,
          *Deadwood,
          *Moria,
          *playerLoc;
    int backpackSize = 6;
    
public:
    Game();
    void playGame();
    void travel(int dir);
    void createMap();
    void displayArea();
    void printMap();
    bool isValidDir(int dir);
    void intro();
    void showBackpack();
    void addTobp(Item item);
    ~Game();
};
#endif

