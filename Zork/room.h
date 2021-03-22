#ifndef ROOM_H
#define ROOM_H

#include <map>
#include <string>
#include <vector>
#include "item.h"
using namespace std;
using std::vector;

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

class Room
{

private:
   string roomImage;
   string mapImage;
   string description;
   //Room* exits[4]; 
   //map<string, Room*> exits;
   //string exitString();
   //vector<item> itemsInRoom;
   //vectors with zombies + vector with items needed

public:
    Room(string description, string roomImage);
    void setExits(Room *north, Room *east, Room *south, Room *west);
    string getDescription();
    void setDescription(string describe);
    string getMap();
    Room* nextRoom(string direction);
    void addItem(item *inItem);
    string displayItem();
    void removeItemFromRoom(int location);
    void removeZombie(string zombieType);
    vector<Room*> exits;
    
};

#endif // ROOM_H
