/*
 * ============================================================================
 *
 *       Filename:  Forest.hpp
 *
 *    Description:  This is the header file for Forest
 *           
 *           Date:  6/11/2019
 *
 *         Author:  TANYA YEU
 *   Organization:  Oregon State University
 *
 * ============================================================================
 */
#ifndef FOREST_HPP
#define FOREST_HPP
#include "Space.hpp"

class Forest: public Space
{
public:
    Forest();
    void printInfo() override;
    void interact(Character*p, int &townHealth, Backpack *b) override;
    ~Forest();
};
#endif
