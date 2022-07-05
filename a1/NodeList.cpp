#include "NodeList.h"
#include <iostream>

NodeList::NodeList(int maxSize){
    this->length = 0;
    this->nodes = new Node*[maxSize];
}

NodeList::~NodeList(){

    //Loop through nodes array and call deconstructor for each stored node.
    for(int i = 0; i < this->length; i++) {
        delete this->nodes[i];
    }
}

NodeList::NodeList(NodeList& other, int maxSize){

    this->length = other.getLength();
    this->nodes = new Node*[maxSize];
    //Loop through each node stored in the "other" nodes array and make a copy.
    for(int i = 0; i < this->length; i++) {
        this->nodes[i] = new Node(*other.getNode(i));
    }
}

int NodeList::getLength(){
    return this->length;
}

void NodeList::addElement(Node* newPos){
    this->nodes[this->length] = new Node(*newPos);
    this->length++;
}

Node* NodeList::getNode(int i){
    return this->nodes[i];
}

bool NodeList::isPosInList(Node* node) {
    bool result = false;
    for(int i = 0; i < this->length; i++) {
        if(node->getCol() == this->nodes[i]->getCol() && node->getRow() == this->nodes[i]->getRow()) {
            result = true;
        } 
    }
    return result;
}
