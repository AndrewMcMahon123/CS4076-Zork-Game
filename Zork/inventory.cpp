#include "inventory.h"

inventory::inventory(){}

void inventory::addItem(item Item){
    if(invent.size() < 9){
        invent.push_back(Item);
    }else{
        cout << "Inventory full drop an Item";
    }
}

/*int inventory::selectItem(item Item){
    int itemPos = 0;
    for(int i = 0; i < invent.size(); i++){
        if(invent[i] == Item){
            itemPos = i;
        }
    }
    return itemPos;
}

void inventory::dropItem(item Item){
    int n = invent.selectItem(Item);
    invent.erase(n);
}*/
