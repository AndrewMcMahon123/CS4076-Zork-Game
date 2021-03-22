#include "item.h"

item::item(string description, QString image)
{
    this->description = description;
    this->image = image;
}
string item::getDescription(){
    return description;
}
QString item::getImage(){
    return image;
}
