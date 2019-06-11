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
#include "getInput.hpp"
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

void Backpack::showBackpack(Character *p)
{
    Item *ptr = head;
    int i, input, itemNum;
    if(head == nullptr)
    {
        cout << "Your backpack is empty" << endl << endl;
    }
    while(ptr)
    {
        i = 1;
        cout << i << " " <<  ptr->getName() << endl;
        ptr = ptr->next;
        i++;
    }
    if(head != nullptr)
    {
    cout << "Use item?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    input = getInput(1,2);
    ptr = head;
    if(input ==1)
    {
        cout << "Item Number: ";
        itemNum = getInput(1,i);
        for(int x=1; x<itemNum; x++)
        {
            ptr = ptr->next;
        }
        ptr->use(p);
        ptr->prev->next = ptr->next->prev;
        ptr->next->prev = ptr->prev->next;
        delete ptr;

    }
    }
}

void Backpack::add(Item *item)
{
    //int size = count();
    if(head==NULL)
    {
        head = item;
        tail = head;
    }
    else
    {
        Item *ptr = tail;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = item;
        tail = ptr->next;
        tail->prev = ptr;
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

int Backpack::count()
{
    Item *ptr = head;
    int size = 0;
    while(ptr!=NULL)
    {
        size++;
        ptr = ptr->next;
    }
    return size;
}
