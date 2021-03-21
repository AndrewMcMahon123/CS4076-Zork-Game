#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <iostream>
#include <string>
#include <QFileDialog>
using namespace std;

class zombie
{
private:
    string type;
    QString image;
    string question;
    int difficulty;
public:
   zombie(string type, QString image, string question, int difficulty); //png for creation add image
  QString getImage();
    string getType();
   void setQuestion(string question);
   string getQuestion();
   int getDifficulty();
   string randomQ(int difficulty);
};

#endif // ZOMBIE_H

