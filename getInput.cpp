/*
 * =============================================================================
 *
 *       Filename:  getInput.cpp
 *
 *    Description:  This is the source file for getInput file
 *
 *         Author:  TANYA YEU
 *   Organization:  Oregon State Univeristy
 *
 * =============================================================================
 */

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using std::isalpha;
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::getline;
using std::stoi;
using std::stringstream;

int validateInput(int min, int max)
{
    char c;
    int input;
    string line;
    bool isValid = false;

    //validate user input
    while(!isValid)
    {
        getline(cin, line);
        stringstream inputStream(line);

        if (!(inputStream >> input) ||
            ((input < min) || (input > max)) ||
            (inputStream >> c))
        {
            cout << "Please enter a valid number between " << min << " and " <<
                max << endl;
        }
        else
        {
            inputStream >> input;
            isValid = true;

        }
    }
    return input;
}

bool isValid(int input, int min, int max);

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  getInput()
 *  Description:  This function takes a string argument and checks to see if it
 *                is a valid input. It checks whether that string is empty or 
 *                not a number. It then converts the string to an int and 
 *                returns it.
 * =============================================================================
 */
int getInput(int min, int max)
{
    string strNumber;
    int iNumber;
    do
    {

        getline(cin, strNumber); //getline
        while (cin.fail() || cin.eof() || strNumber.find_first_not_of("0123456789") != string::npos)
        {
            cout << "Please enter a number between " << min << " and " << max;
            cout << endl;
            if (strNumber.find_first_not_of("0123456789") == string::npos)
            {
                cin.clear();
                cin.ignore(1000, '\n');
            }
            std::getline(cin, strNumber);
        }
        if(strNumber.empty())
        {
            cout << "Please enter a number between " << min << " and " << max;
            cout << endl;
        }
    } while (strNumber.empty());

    string::size_type st;
    iNumber = stoi(strNumber, &st);
    if(!isValid(iNumber,min,max))
    {
        cout << "Please enter a number between " << min << " and " << max;
        cout << endl;
        iNumber = getInput(min,max);
    }
    return iNumber;
}

/*
source: https://stackoverflow.com/questions/18728754/checking-cin-input-
\stream-produces-an-integer
*/

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  isValid(int input, int in, int max)
 *  Description:  This function takes ints for input, min, and max, and checks 
 *                whether t is in range and returns true if it is in bounds, 
 *                and false if it is not.
 * =============================================================================
 */
bool isValid(int input, int min, int max)
{
    if(input < min || input > max)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void displayMenu(string arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}

/* 
 * ===  FUNCTION  ==========================================================
 *         Name:  validate()
 *  Description:  This returns a string if the string is not empty
 * =========================================================================
 */
string validate()
{
    string input;
    getline(cin,input);
    while (input.empty())
    {
        cout << "Please enter a valid string" << endl;
        getline(cin,input);
    }
    return input;
}
