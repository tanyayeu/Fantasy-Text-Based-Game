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

class Town: public Space
{
public:
    void printInfo() override;
    Town();
    ~Town();
};
#endif
