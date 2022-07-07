#include <iostream>
#include <vector>

#include "LinkedList.h"


int main(int argc, char** argv){

    // QUESTION 1
    //---------------------------------------------------------------------------------
    // (a)Creates a C++ STL Vector of integers
    std::vector<int> myVector;

    // (b)Fills the vector with 100 integers from 0 to 99
    for(int i = 0; i < 100; i++) {
        myVector.push_back(i);
    }

    // (c)Prints out the contents of the vector as a comma separated list on a single line
    for(int i = 0; i < (int)myVector.size(); i++) {
        std::cout << myVector[i] << ",";
    }
    //---------------------------------------------------------------------------------


    std::cout << std::endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;


    // QUESTION 2
    //---------------------------------------------------------------------------------
    // (a)Write a code snippet to create a new Linked List
    LinkedList* myList = new LinkedList();

    // (b)Write additional code to add three integers to the Linked List
    myList->addFront(5);
    myList->addBack(6);
    myList->addFront(4);

    // (c)Write additional code to print out the contents of the Linked List in order
    for(int i = 0; i < myList->size(); i++) {
        std::cout << myList->get(i) << ",";
    }

    // (d)For each question above draw the picture of the Linked List after every step
    /*
        First Step Picture: [5]
        Second Step Picture: [5]-[6]
        Third Step Picture: [4]-[5]-[6]
    */
    //---------------------------------------------------------------------------------


    std::cout << std::endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;


    // QUESTION 3 - QUESTION 5. Repeat Q1 using linked list to demonstrate it working
    //---------------------------------------------------------------------------------
    myList->clear();

    for(int i = 0; i < 100; i++) {
        myList->addBack(i);
    }
    for(int i = 0; i < myList->size(); i++) {
        std::cout << myList->get(i) << ",";
    }
    //---------------------------------------------------------------------------------
    

    delete myList;
}