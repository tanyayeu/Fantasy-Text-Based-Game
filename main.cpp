/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  This is the main file
 *             
 *           Date:  6/11/2019
 *
 *         Author:  TANYA YEU
 *   Organization:  Oregon State University
 *
 * ============================================================================
 */

#include <iostream>
#include <ctime>
#include <string>
#include "getInput.hpp"
using std::cout;
using std::endl;

int main()
{
    cout << "Welcome to your adventure!" << endl << endl;
    int input;
    string menu[2] = {"1. Embark on your journey",
                      "2. Exit"};
    do
    {
        displayMenu(menu,2);
        input = getInput(1,2);
        if(input ==1)        
        {
            //do stuff
        }
        if(input ==2)
        {
            return 0;
        }
        cout << "Would you like to play again?" << endl;
    }while(input!=2);
    return 0;
}

