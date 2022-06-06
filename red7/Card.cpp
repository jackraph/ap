#include "Card.h"

Card::Card(int num) {
    this->number = num;
    
    if(num <= 6) {
        //RED

    } else if(num <= 13) {
        //ORANGE

    } else if(num <= 20) {
        //YELLOW

    } else if(num <= 27) {
        //GREEN

    } else if(num <= 34) {
        //BLUE

    } else if(num <= 41) {
        //INDIGO

    } else if (num <= 48) {
        //VIOLET

    }
 }
 
int Card::getNumber() {
    return this->number;
}
int Card::getColorID() {
    return this->colorID;
}
Color Card::getColor() {
    return this->color;
}
std::string Card::getRule() {
    return this->rule;
}