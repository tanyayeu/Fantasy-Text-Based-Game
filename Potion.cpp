/*
 * ============================================================================
 *
 *       Filename:  Potion.cpp
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

#include "Potion.hpp"
Potion::Potion()
{
    name = "Potion";
}
void Potion::use(Character* p)
{
    p->recover(recovery);
}

