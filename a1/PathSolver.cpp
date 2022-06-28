#include "PathSolver.h"
#include <iostream>

PathSolver::PathSolver(){

}

PathSolver::~PathSolver(){
    // TODO
}

void PathSolver::forwardSearch(Env env){
    NodeList* openList;
    NodeList* closedList;

    // Find  and add start location to the open list.
    for(int y = 0; y < ENV_DIM; y++) {
        for(int x = 0; x < ENV_DIM; x++) {
            if (env[y][x] == SYMBOL_START) {
                openList->addElement(&Node(y, x, 0));
            }
        }
    }

    //Current position. Initially assigned to starting node.
    Node& p = *openList->getNode(0);
    
    do {

        //Select the node p from the open-list P that has the smallest estimated distance (see Section 3.2.2)
        //to goal and, is not in the closed-list C.
        for(int i = 0; i < openList->getLength(); i++) {

            Node& openNode = *openList->getNode(i);

            //Select node from open list if it has a lower distance travelled than current p.
            if (openNode.getDistanceTraveled() < p.getDistanceTraveled()) {

                //Check it is not in the closed list.
                // bool closed = false;
                // for (int j = 0; j < closedList->getLength(); j++) {
                //     if (&openNode == closedList->getNode(j)) {
                //         closed = true;
                //     }
                // }
                //If not found in the closed list update the position (p) reference.
                // if(!closed) {
                //     p = node;
                // }
                if(closedList->isNodeInList(openNode)) {
                    p = openNode;
                }

            }
        }

        //Up, Right, Down, Left
        // if(env[p.getRow()][p.getCol() + 1])
        // if(env[p.getRow()][p.getCol() + 1])
        // if(env[p.getRow()][p.getCol() + 1])
        // if(env[p.getRow()][p.getCol() + 1])

        //Find the postions that can be reached from p and add them to the open list.
        for(int i = 0; i < 4; i++) {

        }
        


    } while (env[p.getRow()][p.getCol()] != SYMBOL_GOAL);
}



NodeList* PathSolver::getNodesExplored(){
    return new NodeList(*this->nodesExplored);
}

NodeList* PathSolver::getPath(Env env){
    // TODO
}

//-----------------------------
