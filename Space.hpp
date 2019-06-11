/*
 * ============================================================================
 *
 *       Filename:  Space.hpp
 *
 *    Description:  This is the header file for Space class
 *           
 *           Date:  6/11/2019
 *
 *         Author:  TANYA YEU
 *   Organization:  Oregon State University
 *
 * ============================================================================
 */
#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include "Item.hpp"
#include "Character.hpp"
#include "Backpack.hpp"
using std::string;

class Space
{
protected:
    Space();
    string name, //name of space
           type; //type of space
    bool isBossDefeated;
public:
    string getName();
    string getType();
    void setName(string n);
    virtual ~Space();
    virtual void printInfo() = 0;
    Space *top, *left, *right, *bottom; //4 space pointers
    virtual void interact(Character *p, int &townHealth, Backpack *b) = 0;
    void setIsBossDefeated();

};
#endif
