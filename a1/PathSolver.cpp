#include "PathSolver.h"
#include <iostream>

PathSolver::PathSolver(){

}

PathSolver::~PathSolver(){
    // TODO
}

void PathSolver::forwardSearch(Env env){

    // Environment-List(E) | Open-List(P) | Closed-List(C)
    NodeList* E;
    NodeList* P;
    NodeList* C;

    // Starting-Node(S) | Goal-Node(G)
    Node* S;
    Node* G;

    // Build Environment-List(E).
    for(int y = 0; y < ENV_DIM; y++) {
        for(int x = 0; x < ENV_DIM; x++) {
                E->addElement(&Node(y, x, 0));          
        }
    }

    // Iterate Environment-List(E) to find Starting-Node(S) & Goal-Node(G).
    for(int i = 0; i < E->getLength(); i++) {
        Node* openNode = E->getNode(i);
        char symbol = env[openNode->getRow()][openNode->getCol()];
        if(symbol == SYMBOL_START) {
            S = openNode;
            P->addElement(S);
        } else if (symbol == SYMBOL_GOAL) {
            G = openNode;
        }
    }


    
    do {

        // Position(p)
        Node* p = S;
        
        // Assign node from Open-List(P) as Position(p) 
        // If it current p and is not in closed-list(C).
        for(int i = 0; i < P->getLength(); i++) {

            //Open-Node(o)
            Node* o = P->getNode(i);
            if (o->getEstimatedDist2Goal() < p->getEstimatedDist2Goal() 
            && !C->isNodeInList(o)) {
                p = openNode;
            }
        }

        //Up, Right, Down, Left
        // if(env[p.getRow() + 1][p.getCol()])
        // if(env[p.getRow()][p.getCol() + 1])
        // if(env[p.getRow() - 1][p.getCol()])
        // if(env[p.getRow()][p.getCol() - 1])

        //if(openList->isNodeInList(p.getRow(), p.getRow()))

        //Loop through all 4 directions robot can move.
        for(int i = -1; i < 1; i++) {

            //Down then Right
            if(!openList->isNodeInList(p.getRow() + i, p.getCol() + i + 1)) {

            }

            //Up then Left
            if(!openList->isNodeInList(p.getRow() - i, p.getCol() - i - 1)) {

            }
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
