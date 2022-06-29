#include "PathSolver.h"
#include <iostream>

PathSolver::PathSolver(){
    // TODO
}

PathSolver::~PathSolver(){
    //TODO
}

void PathSolver::forwardSearch(Env env){
    
    // Environment-List(E) | Open-List(P) | Closed-List(C)
    NodeList* E = new NodeList();
    NodeList* P = new NodeList();
    NodeList* C = new NodeList();

    // Starting-Node(S) | Goal-Node(G)
    Node* S = nullptr;
    Node* G = nullptr;

    // Build Environment-List(E) from given env, then find Starting-Node(S) & Goal-Node(G)
    for(int y = 0; y < ENV_DIM; y++) {
        for(int x = 0; x < ENV_DIM; x++) {

            //Create node for each position in the environment
            Node* newNode = new Node(y, x, 0);
            E->addElement(newNode); 

            //Assign Starting-Node(S) & Goal-Node(G) pointers to their respective Node obj memory addresses
            if (newNode->getSymbol(env) == SYMBOL_START) {
                S = newNode;
            } else if (newNode->getSymbol(env) == SYMBOL_GOAL) {
                G = newNode; 
            }            
        }
    }

    //Add starting node to the Open-List(P)
    P->addElement(S);  

    // Position(p)
    Node* p = S;

    int iterations = 0;
    //Repeat until goal is found or there is no reachable goal.
    do {

        //Select a Position(p) from Open-List(P) that has the smallest estimated distance to goal and is not in the Closed-List(C)
        for(int i = 0; i < P->getLength(); i++) {
            Node* n = P->getNode(i);

            //New-Position(n) is not the Closed-List(C)
            if(!C->isNodeInList(n)) {
                
                //Current Position(p) is in the Closed-List(C) or New-Position(n) is closer to the goal
                if(C->isNodeInList(p) || n->getEstimatedDist2Goal(G) < p->getEstimatedDist2Goal(G)) { 
                    p = n; 
                }           
            }
        }      

        //For each Other-Position(q) in Environment-List(E) that the robot can reach from Position(p)
        for(int i = 0; i < E->getLength(); i++) {
            Node* q = E->getNode(i);

            //Axis booleans.
            bool v,h = false;
      
            //Other-Position(q) is 1 grid-step away from Position(p) on the Vertical axis.
            if(std::abs(q->getRow() - p->getRow()) == 1 && q->getCol() == p->getCol()) { 
                v = true; 
            }

            //Other-Position(q) is 1 step away from Position(p) on the Horizontal axis.
            if(std::abs(q->getCol() - p->getCol()) == 1 && q->getRow() == p->getRow()) { 
                h = true; 
            }

            //XOR operation to filter diagonals. If the position is 1 grid-step away on both axis it is a diagonal
            if((v != h && (v == true || h == true))) {

                //Other-Position(q) is not an obstacle
                if(q->getSymbol(env) != SYMBOL_WALL) {

                    //Set the distance_travelled of q to be one more that that of p
                    q->setDistanceTraveled(p->getDistanceTraveled() + 1);

                    //Add q to Open-List(P) only if it is not already in it.
                    if(!(P->isNodeInList(q))) { 
                        P->addElement(q); 
                    }               
                }
            }
        }

        //Add Position(p) to the Closed-List(C)
        C->addElement(p);

     iterations++;
    } while (p->getSymbol(env) != SYMBOL_GOAL && iterations < E->getLength());

    nodesExplored = C;

    //MEMORY CLEANUP
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    delete E;
    E = nullptr;
    delete P;
    P = nullptr;
    delete C;  
    C = nullptr; 
}

NodeList* PathSolver::getNodesExplored(){
    return this->nodesExplored;
}

//Attempt 2
NodeList* PathSolver::getPath(Env env){


    //Path-List(P)
    NodeList* P = new NodeList();

    // Starting-Node(S) | Goal-Node(G)
    Node* S = nullptr;
    Node* G = nullptr;

    // Find Starting-Node(S) & Goal-Node(G)
    for(int i = 0; i < nodesExplored->getLength(); i++){
   
        Node* n = nodesExplored->getNode(i);
        if (n->getSymbol(env) == SYMBOL_START) {
            S = n;
        } else if (n->getSymbol(env) == SYMBOL_GOAL) {
            G = n; 
        }
    }
    

    //Position(p) starts at the last node in the exploredNodes NodeList
    Node* p = nodesExplored->getNode(nodesExplored->getLength() - 1);

    do {

        //For each Neighbour-Position(q) in nodesExplored 
        for(int i = 0; i < nodesExplored->getLength(); i++) {
            Node* q = nodesExplored->getNode(i);

            //Axis booleans.
            bool v,h = false;
        
            //Other-Position(q) is 1 grid-step away from Position(p) on the Vertical axis.
            if(std::abs(q->getRow() - p->getRow()) == 1 && q->getCol() == p->getCol()) { 
                v = true; 
            }

            //Other-Position(q) is 1 step away from Position(p) on the Horizontal axis.
            if(std::abs(q->getCol() - p->getCol()) == 1 && q->getRow() == p->getRow()) { 
                h = true; 
            }

            //XOR operation to filter diagonals. If the position is 1 grid-step away on both axis it is a diagonal
            if((v != h && (v == true || h == true))) {

                //Add to path
                if(p->getDistanceTraveled() - q->getDistanceTraveled() == 1) {
                    
                    P->addElement(q);
                    p = q;
                }
            }
        }

    } while(p->getSymbol(env) != SYMBOL_START);

    std::cout << "Made it here yay" <<std::endl;

    return P;

    //how am i ment to do this I wonder?
}

// NodeList* PathSolver::getPath(Env env){

//     // Explored-List(E) | Path-List(P)
//     NodeList* E = this->nodesExplored;
//     NodeList* P;

//     // Starting-Node(S) | Goal-Node(G)
//     Node* S;
//     Node* G;


//     // Iterate Explored-List(E) to find Starting-Node(S) & Goal-Node(G)
//     // NOTE: This is backtracking so starting from the goal symbol and finishing at the start symbol.
//     for(int i = 0; i < E->getLength(); i++) {
//         Node* openN = E->getNode(i);
//         char symbol = env[openN->getRow()][openN->getCol()];
//         if(symbol == SYMBOL_GOAL) {
//             S = openN;
//             P->addElement(S);
//         } else if (symbol == SYMBOL_START) {
//             G = openN;
//         }
//     }

//     //

//     // Path-Node(p)
//     Node* p = S;
//     do {
        
//         // Iterate Explored-List(E) to find next Path-Node(p)
//         // Other-Node(q) 1 grid step away from Path-Node(p) & its distance_travelled is 1 less than p.
//         for(int i = 0; i < E->getLength(); i++) {
//             Node* q = E->getNode(i);
//             if(std::abs(q->getCol() - q->getCol()) + std::abs(q->getRow() - q->getRow()) == 1) {
//                 if(q->getDistanceTraveled() + 1 == p->getDistanceTraveled()) {
//                     p = q;
//                 }
//             }
//         }

//         // Add Path-Node(p) to Path-List(P)
//         P->addElement(p);

//     } while (p != G);

//     //Flip Path-List(P) into new array before returning
//     NodeList* Path;
//     for(int i = 1; i <= P->getLength(); i++) {
//         Path->addElement(P->getNode(P->getLength() - i));
//     }
//     return Path;

//     //DELETE NODELISTS HERE.
// }

//-----------------------------
