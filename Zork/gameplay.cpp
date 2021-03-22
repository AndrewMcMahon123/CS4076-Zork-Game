#include "gameplay.h"
#include "room.h"


gameplay::gameplay()
{
    createRooms();
}


void gameplay::createRooms()
{
    Room *gFloorMain, *gFloorRight, *gFloorLeft, *basement, *basementRight, *basementLeft, *upstairs, *upstairsRight, *upstairsLeft;

    gFloorMain = new Room("You're on the ground floor", "x.png");
    gFloorRight = new Room("You're on the ground floor", "x.png");
    gFloorLeft = new Room("You're on the ground floor", "x.png");
    basement = new Room("You're on the ground floor", "x.png");
    basementRight = new Room("You're on the ground floor", "x.png");
    basementLeft = new Room("You're on the ground floor", "x.png");
    upstairs = new Room("You're on the ground floor", "x.png");
    upstairsRight = new Room("You're on the ground floor", "x.png");
    upstairsLeft = new Room("You're on the ground floor", "x.png");

    


//             (U, R, D, L)
    gFloorMain->setExits(upstairs, gFloorRight, basement, gFloorLeft);
    gFloorRight->setExits(NULL, NULL, NULL, gFloorMain);
    gFloorLeft->setExits(NULL, gFloorMain, NULL, NULL);
    basement->setExits(gFloorMain, basementRight, NULL, basementLeft);
    basementRight->setExits(NULL, NULL, NULL, basement);
    basementLeft->setExits(NULL, basement, NULL, NULL);
    upstairs->setExits(NULL, upstairsRight, gFloorMain, upstairsLeft);
    upstairsRight->setExits(NULL, NULL, NULL, upstairs);
    upstairsLeft->setExits(NULL, upstairs, NULL, NULL);

    currentRoom = gFloorMain;
    
}




Room* gameplay::getCurrentRoom()
{
    return currentRoom;
}


vector<Room*> gameplay::getExits(){
    return currentRoom->exits;

}

string gameplay::move(char direction) {

    Room* nextRoom = currentRoom+direction;

    if (currentRoom+direction == NULL)
        return "There's no door there!";
    else {
        currentRoom = nextRoom;
        return currentRoom->getDescription();
    }
}


