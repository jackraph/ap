#include "PathSolver.h"
#include <iostream>

PathSolver::PathSolver(){
    // TODO
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

    // Build Environment-List(E)
    for(int y = 0; y < ENV_DIM; y++) {
        for(int x = 0; x < ENV_DIM; x++) {
                E->addElement(new Node(y, x, 0));          
        }
    }

    // Iterate Environment-List(E) to find Starting-Node(S) & Goal-Node(G)
    for(int i = 0; i < E->getLength(); i++) {
        Node* openN = E->getNode(i);
        char symbol = env[openN->getRow()][openN->getCol()];
        if(symbol == SYMBOL_START) {
            S = openN;
            P->addElement(S);
        } else if (symbol == SYMBOL_GOAL) {
            G = openN;
        }
    }

    // Position(p)
    Node* p = S;

    int iterations = 0;
    do {
        
        // Iterate Open-List(P) to find next Position(p)
        // Next position to be closer to goal than current Position(p) and NOT in the Closed-List(C)
        for(int i = 0; i < P->getLength(); i++) {
            Node* openN = P->getNode(i);
            if (openN->getEstimatedDist2Goal(G) < p->getEstimatedDist2Goal(G) && !C->isNodeInList(openN)) {
                p = openN;
            }
        }

        // Iterate Environment-List(E) to find Other-Positions(q) in range of Position(p)
        // Populate Open-List(P) with Other-Positions(q) that are 1 grid step away
        for(int i = 0; i < E->getLength(); i++) {
            Node* q = E->getNode(i);
            if(std::abs(q->getCol() - p->getCol()) + std::abs(q->getRow() - p->getRow()) == 1) {
                q->setDistanceTraveled(p->getDistanceTraveled() + 1);
                if(!P->isNodeInList(q)) {
                    P->addElement(q);
                }
            }      
        }

        // Add Position(p) to the Closed-List(C)
        C->addElement(p);
        //Remove from open list too.
        
        iterations++;
    } while (p != G || iterations < NODE_LIST_ARRAY_MAX_SIZE);

    //Solved or failed to find path
}



NodeList* PathSolver::getNodesExplored(){
    return new NodeList(*this->nodesExplored);
}

NodeList* PathSolver::getPath(Env env){
    // TODO
}

//-----------------------------
