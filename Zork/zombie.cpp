#include "zombie.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


zombie::zombie(string type, QString image, string question, int difficulty) {
    type = this->type;
    image = this->image;
    question = this->question;
    difficulty = this->difficulty;
}

string zombie::getType() {
    return type;
}

void zombie::setQuestion(string newQ){
    question = newQ;
}

string zombie::getQuestion(){
    return question;
}

int zombie::getDifficulty(){
    return difficulty;
}

string zombie::randomQ(int difficulty){
    srand(time(0));
    int r = rand()%5;
    switch(difficulty){
        case(1): switch(r){
            case(0): setQuestion(); break;
        case(1): setQuestion(); break;
        case(2): setQuestion(); break;
        case(3): setQuestion() ; break;
        case(4): setQuestion(); break;
        } break;
    case(2): switch(r){
            case(0):setQuestion(); break;
            case(1):setQuestion(); break;
            case(2): setQuestion();break;
            case(3):setQuestion(); break;
            case(4):setQuestion(); break;
        }break;
    case(3): switch(r){
            case(0): setQuestion();break;
            case(1): setQuestion();break;
            case(2): setQuestion();break;
            case(3): setQuestion();break;
            case(4): setQuestion();break;
        }break;
    }
    return question;
}
