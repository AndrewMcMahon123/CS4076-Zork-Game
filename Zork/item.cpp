#include "item.h"

item::item(string inDescription)
{
    description = inDescription;
}
string item::getDescription(){
    return description;
}
