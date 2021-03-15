#include "gameplay.h"

gameplay::gameplay()
{
    createRooms();
}

void gameplay::createRooms()
{
    Room *gFloorMain, *gFloorRight, *gFloorLeft, *basement, *basementRight, *basementLeft, *upstairs, *upstairsRight, *upstairsLeft;

    gFloorMain = new Room("You're on the ground floor", "x.png", "x.gif");
    gFloorRight = new Room("You're in the sitting room on the ground floor", "map_basement.png", "roomB.gif");
    gFloorLeft = new Room("You're in the bathroom on the ground floor", "map_catRoom.png", "roomC.gif");
    basement = new Room("You're in a room d", "map_gate.png", "room_gate.png");
    basementRight = new Room("You're in a room e", "map_hallway.png", "room_hallway.png");
    basementLeft = new Room("You're in a room f", "map_kitchen.png", "roomF.gif");
    upstairs = new Room("You're in a room g", "map_landing.png", "roomG.gif");
    upstairsRight = new Room("You're in a room h", "map_livingRoom.png", "roomH.gif");
    upstairsLeft = new Room("You're in a room i", "map_street.png", "room_street.png");

    


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

QString gameplay::move(int direction) {

    pair<Room*, QString> nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom.first == NULL)
        return "There's no door there";
    else {
        currentRoom = nextRoom.first;
        return currentRoom->getDescription();
    }
}
