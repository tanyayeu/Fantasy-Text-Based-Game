/*
 * ============================================================================
 *
 *       Filename:  Town.hpp
 *
 *    Description:  
 *           
 *           Date:
 *
 *         Author:  TANYA YEU
 *   Organization:  Oregon State University
 *
 * ============================================================================
 */
#ifndef TOWN_HPP
#define TOWN_HPP
#include "Space.hpp"
#include <string>
using std::string;

class Town: public Space
{
public:
    void printInfo() override;
    void interact(Character *p, int &townHealth) override;
    Town();
    ~Town();
};
#endif
