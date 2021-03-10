#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class item
{
private:
    string description;

public:
    item(string description);
    string getDescription();
};

#endif // ITEM_H
