#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "item.h"
#include <string>
#include <iostream>
using namespace std;
using std::vector;

class inventory
{
private:
    vector<item> invent;
public:
    inventory();
    void addItem(item Item);
    void dropItem(item Item);
    int selectItem(item Item);

};

#endif // INVENTORY_H
