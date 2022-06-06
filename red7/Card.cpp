#include "Card.h"
#include <string>

//Default constructor.
Card::Card() {
        deckNum = -1;
        number = -1;
        colorNum = -1;
        color = "OOB";
        rule = "OOB";
}

Card::Card(int num) {
    deckNum = num;

    if(num <= 6) {
        //RED
        number = num + 1;
        colorNum = 0;
        color = "Red";
        rule = "Highest card wins.";
    } else if(num <= 13) {
        //ORANGE
        number = num - 6;
        colorNum = 1;
        color = "Orange";
        rule = "Most of one number wins.";
    } else if(num <= 20) {
        //YELLOW
        number = num - 13;
        colorNum = 2;
        color = "Yellow";
        rule = "Most of one color wins";
    } else if(num <= 27) {
        //GREEN
        number = num - 20;
        colorNum = 3;
        color = "Green";
        rule = "Most even cards wins.";
    } else if(num <= 34) {
        //BLUE
        number= num - 27;
        colorNum = 4;
        color = "Blue";
        rule = "Most differnt colors wins.";
    } else if(num <= 41) {
        //INDIGO
        number = num - 34;
        colorNum = 5;
        color = "Indigo";
        rule = "Most cards in a row wins.";
    } else if (num <= 48) {
        //VIOLET
        number = num - 41;
        colorNum = 6;
        color = "Violet";
        rule = "Most cards below 4 wins.";
    }
 }

int Card::getDeckNum() {
    return deckNum;
}
 
int Card::getNumber() {
    return number;
}

int Card::getColorNum() {
    return colorNum;
}

std::string Card::getColor() {
    return color;
}

std::string Card::getRule() {
    return rule;
}