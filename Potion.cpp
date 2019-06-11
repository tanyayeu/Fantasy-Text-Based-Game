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
void Potion::use(Character* p, Character *e)
{
    p->recover(recovery);
}

HiPotion::HiPotion()
{
    name = "HiPotion";
}
