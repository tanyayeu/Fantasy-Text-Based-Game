/*
 * =============================================================================
 *
 *       Filename:  getInput.hpp
 *
 *    Description:  This is the header file for getInput functions
 *
 *         Author:  TANYA YEU
 *   Organization:  Oregon State Univeristy
 *
 * =============================================================================
 */

#ifndef GETINPUT_HPP
#define GETINPUT_HPP
#include <string>
using std::string;

int getInput(int min, int max);
int validateInput(int min, int max);
bool isValid(int input, int min, int max);
bool validateString(const string &s);
void displayMenu(string *arr, int size);
string validate();
#endif
