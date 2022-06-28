#include "NodeList.h"
#include <iostream>

//Constructor
NodeList::NodeList(){
    // TODO
    //Initialise variables.
}

//Deconstructor
NodeList::~NodeList(){

    //Loop through nodes array and call deconstructor for each stored node.
    for(int i = 0; i < this->length; i++) {
        delete this->nodes[i];
    }
}

// Copy Constructor that produces a DEEP COPY of a given NodeList
NodeList::NodeList(NodeList& other){

    this->length = other.getLength();
    //Loop through each node stored in the "other" nodes array and make a copy.
    for(int i = 0; i < this->length; i++) {
        this->nodes[i] = other.getNode(i);
    }
}

// Get the number of nodes currently being stored in the nodelist.
int NodeList::getLength(){
    return this->length;
}

// Add a COPY node element to the BACK of the nodelist.
void NodeList::addElement(Node* newPos){
    this->length++;
}

// Get a pointer to the ith node in the node list
Node* NodeList::getNode(int i){
    return this->nodes[i];
}
