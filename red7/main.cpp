#include <iostream>
#include "Card.h"

void printCard(Card card);

int main(void) {

    //Dynamic Initialization.
    Card* cards[48];
    for(int i = 0; i <= 48; i++) {
        cards[i] = new Card(i);
    }

    int inp;
    int x = 0;
    //Input loop.
    while (x < 1) {
        std::cout << "Enter an integer between 0 & 48 to recieve card info. (Enter 999 to exit)" << std::endl;
        std::cin >> inp;

        if (inp > -1 && inp < 49) {
            printCard(*cards[inp]);
        } else if (inp == 999) {
            x++;
        }
    }
    return EXIT_SUCCESS;
}

void printCard(Card card) {
    std::cout <<"--------------------"<<std::endl;
    std::cout <<"CardNo: " <<  card.getNumber() <<std::endl;
    std::cout <<"Color: "  << card.getColor() + "(" + std::to_string(card.getColorNum()) + ")" << std::endl;
    std::cout <<"Rule: "  << card.getRule() << std::endl;
    std::cout <<"Deck Position: " <<  card.getDeckPos() <<std::endl;
    std::cout <<"--------------------"<<std::endl;
}