#include "room.h"

Room::Room(string description, string roomImage)
{
    this->description = description;
    this->roomImage = roomImage;
}

string Room::getDescription(){
    return description;
}

void Room::setDescription(string describe){
    description = describe;
}

string Room::getMap(){
    return mapImage;
}

/*void Room::setExits(Room *north, Room *east, Room *south, Room *west){
    exits[NORTH] = north;
    exits[EAST] = east;
    exits[SOUTH] = south;
    exits[WEST] = west;
}*/

//nextRoom method tbd

void addItem(item *inItem){

}

void removeItemFromRoom(int location){

}

/*void removeZombie(string zombieType){

}*/

//Make map for rooms to move around
