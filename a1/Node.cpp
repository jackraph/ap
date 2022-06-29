#include "Node.h"
#include <iostream>


Node::Node(int row, int col, int dist_traveled)
{
    this->row = row;
    this->col = col;
    this->dist_traveled = dist_traveled;
}

Node::~Node(){
    // TODO~~~~~~~~~~~~~
    // DECONSTRUCTOR CODE HERE!!!
    // TODO ~~~~~~~~~~
}

int Node::getRow(){
    return this->row;
}

int Node::getCol(){
    return this->col;
}

int Node::getDistanceTraveled(){
    return this->dist_traveled;
}

void Node::setDistanceTraveled(int dist_traveled)
{
    this->dist_traveled = dist_traveled;
}

// Algorithm for estimating distance from pos to goal = ([colp − colG] + [rowp − rowG]) + distance travelled.
int Node::getEstimatedDist2Goal(Node* goal){
    return ((this->col - goal->getCol()) + (this->row - goal->getRow())) + this->dist_traveled;
}
    
//--------------------------------                             

char Node::getSymbol(Env env) {
     return env[this->row][this->col];
}