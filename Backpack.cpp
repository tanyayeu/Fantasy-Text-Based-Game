/*
 * ============================================================================
 *
 *       Filename:  Backpack.cpp
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
#include "Backpack.hpp"
#include <iostream>
using std::cout;
using std::endl;

Backpack::Backpack()
{
    head = nullptr;
}

Backpack::~Backpack()
{
    Item *ptr = head;
    while(ptr!=nullptr)
    {
        Item *garbage = ptr;
        ptr = ptr->next;
        delete garbage;
    }
}

void Backpack::showBackpack()
{
    Item *ptr = head;
    if(head == nullptr)
    {
        cout << "Your backpack is empty" << endl;
    }
    while(ptr)
    {
        int i = 1;
        cout << i << " " <<  ptr->getName() << endl;
        ptr = ptr->next;
        i++;
    }
}

void Backpack::add(Item *item)
{
    Item *ptr = head;
    int i;
    if(head==nullptr)
    {
        head = item;
    }
    //get size
    while(ptr && head!=nullptr)
    {
        i = 1;
        ptr =ptr->next;
        i++;
    }
    while(i < size)
    {
        while(ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = item;
        head->prev = ptr->next;
        head->prev->prev = ptr;
    }
    if(i>=size)
    {
        cout << "Your backpack is full!" << endl;
    }
}

void Backpack::removeItem(string name)
{
    Item *ptr = head;
    while(ptr)
    {
        if(ptr->getName() == name)
        {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            delete ptr;
        }
    }
}
