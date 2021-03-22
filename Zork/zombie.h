#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <iostream>
#include <string>
#include <QFileDialog>
#include "item.h"
using namespace std;

class zombie
{
private:
    string type;
    QString image;
    string question;
    item* key;
    int difficulty;
public:
   zombie(string type, QString image, string question, item* key, int difficulty); //png for creation add image
   string getType();
   QString getImage();
   void setQuestion(string question);
   string getQuestion();
   int getDifficulty();
   string randomQ(int difficulty);
};

#endif // ZOMBIE_H
