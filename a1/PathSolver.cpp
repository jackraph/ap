#include "PathSolver.h"
#include <iostream>

PathSolver::PathSolver(){
    // TODO
}

PathSolver::~PathSolver(){
    delete this->nodesExplored;
}

void PathSolver::forwardSearch(Env env){


    // Environment-List(E) | Open-List(P) | Closed-List(C)
    NodeList E;
    NodeList P;
    NodeList C;

    // Starting-Node(S) | Goal-Node(G)
    Node* S;
    Node* G;

    // Build Environment-List(E)
    for(int y = 0; y < ENV_DIM; y++) {
        for(int x = 0; x < ENV_DIM; x++) {
                E.addElement(new Node(y, x, 0));          
        }
    }

    // Iterate Environment-List(E) to find Starting-Node(S) & Goal-Node(G)
    for(int i = 0; i < E.getLength(); i++) {
        Node* openN = E.getNode(i);
        char symbol = env[openN->getRow()][openN->getCol()];
        if(symbol == SYMBOL_START) {
            S = openN;
            P.addElement(S);
        } else if (symbol == SYMBOL_GOAL) {
            G = openN;
        } else if (symbol == SYMBOL_WALL) {
            C.addElement(openN);
        }
    }
    

    // Position(p)
    Node* p = S;

    int iterations = 0;
    do {
        
        // Iterate Open-List(P) to find next Position(p)
        // Next position to be closer to goal than current Position(p) and NOT in the Closed-List(C)
        for(int i = 0; i < P.getLength(); i++) {
            Node* openN = P.getNode(i);
            if (openN->getEstimatedDist2Goal(G) < p->getEstimatedDist2Goal(G) && !C.isNodeInList(openN)) {
                p = openN;
            }
        }
        
        // Iterate Environment-List(E) to find Other-Positions(q) in range of Position(p)
        // Populate Open-List(P) with Other-Positions(q) that are 1 grid step away
        for(int i = 0; i < E.getLength(); i++) {
            Node* q = E.getNode(i);
            if(std::abs(q->getCol() - p->getCol()) + std::abs(q->getRow() - p->getRow()) == 1) {
                q->setDistanceTraveled(p->getDistanceTraveled() + 1);
                if(!P.isNodeInList(q)) {
                    P.addElement(q);
                }
            }      
        }

        // Add Position(p) to the Closed-List(C)
        C.addElement(p);
        
        iterations++;
    } while (&p != &G || iterations >= NODE_LIST_ARRAY_MAX_SIZE);

    //Solved or failed to find path
    std::cout << "~~~~~~JACKS TESTING~~~~~~~~~~" << std::endl;

    
    this->nodesExplored = &C;
}



NodeList* PathSolver::getNodesExplored(){
    return new NodeList(*this->nodesExplored);
}

NodeList* PathSolver::getPath(Env env){

    // Explored-List(E) | Path-List(P)
    NodeList* E = this->nodesExplored;
    NodeList* P;

    // Starting-Node(S) | Goal-Node(G)
    Node* S;
    Node* G;


    // Iterate Explored-List(E) to find Starting-Node(S) & Goal-Node(G)
    // NOTE: This is backtracking so starting from the goal symbol and finishing at the start symbol.
    for(int i = 0; i < E->getLength(); i++) {
        Node* openN = E->getNode(i);
        char symbol = env[openN->getRow()][openN->getCol()];
        if(symbol == SYMBOL_GOAL) {
            S = openN;
            P->addElement(S);
        } else if (symbol == SYMBOL_START) {
            G = openN;
        }
    }

    // Path-Node(p)
    Node* p = S;
    do {
        
        // Iterate Explored-List(E) to find next Path-Node(p)
        // Other-Node(q) 1 grid step away from Path-Node(p) & its distance_travelled is 1 less than p.
        for(int i = 0; i < E->getLength(); i++) {
            Node* q = E->getNode(i);
            if(std::abs(q->getCol() - q->getCol()) + std::abs(q->getRow() - q->getRow()) == 1) {
                if(q->getDistanceTraveled() + 1 == p->getDistanceTraveled()) {
                    p = q;
                }
            }
        }

        // Add Path-Node(p) to Path-List(P)
        P->addElement(p);

    } while (p != G);

    //Flip Path-List(P) into new array before returning
    NodeList* Path;
    for(int i = 1; i <= P->getLength(); i++) {
        Path->addElement(P->getNode(P->getLength() - i));
    }
    return Path;
}

//-----------------------------
