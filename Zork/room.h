#ifndef ROOM_H
#define ROOM_H

#include <map>
#include <string>
#include <vector>
#include "item.h"
using namespace std;
using std::vector;

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

class Room
{

private:
   string roomImage;
   string mapImage;
   string description;
   map<string, Room*> exits;
   string exitString();
   //vectors with zombies + vector with items needed

public:
    Room(string description, string roomImage);
    void setExits(Room *north, Room *east, Room *south, Room *west);
    string getDescription();
    void setDescription(string describe);
    string getMap();
    Room* nextRoom(string direction);
    void addItem(Item *inItem);
    string displayItem();
    void removeItemFromRoom(int location);
    void removeZombie(string zombieType);
};

#endif // ROOM_H
