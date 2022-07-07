
#include "LinkedList.h"

#include <iostream>
#include <string>
#include <vector>

#define EXIT_SUCCESS    0

void printMenu();
void printBoard();

int main(void) {
   LinkedList* list = new LinkedList();
   delete list;

   std::cout << "TODO: Implement Qwirkle!" << std::endl;

   return EXIT_SUCCESS;
}

void printMenu() {
   std::cout << "Menu" << std::endl << "-----" << std::endl;
   std::cout<< "1. New Game" << std::endl;
   std::cout<< "2. Load Game" << std::endl;
   std::cout<< "3. Credits" << std::endl;
   std::cout<< "4. Quit" << std::endl;

   int inp = 0;
   std::cin >> inp;
   if(inp == 1) {
      //Start new game.
   } else if (inp == 2) {
      //Load game.
   } else if (inp == 3) {
      //Print credits.
   } else if(inp == 4) {
      //Quit game.
   }
}
