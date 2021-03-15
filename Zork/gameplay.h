#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <QString>
#include "room.h"

class gameplay
{

private:
    Room *currentRoom;
    void createRooms();
    void addItemsToRoom(item);

public:
    gameplay();
    Room* getCurrentRoom();
    QString move(int direction);
};

#endif // GAMEPLAY_H
