#ifndef ITEM_H
#define ITEM_H
#include <QFileDialog>
#include <string>
using namespace std;

class item
{
private:
    string description;
    QString image;

public:
    item(string description, QString image);
    string getDescription();
    QString getImage();
};

#endif // ITEM_H
