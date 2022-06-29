#include "PathSolver.h"
#include <iostream>

PathSolver::PathSolver(){
    // TODO
}
//Testing github connection from main PC
PathSolver::~PathSolver(){
    delete this->nodesExplored;
}

//Second attempt.
void PathSolver::forwardSearch(Env env){
    
    // Environment-List(E) | Open-List(P) | Closed-List(C)
    NodeList* E = new NodeList();
    NodeList* P = new NodeList();
    NodeList* C = new NodeList();

    // Starting-Node(S) | Goal-Node(G)
    Node* S = nullptr;
    Node* G = nullptr;

    // Build Environment-List(E) + find Starting-Node(S) & Goal-Node(G)
    for(int y = 0; y < ENV_DIM; y++) {
        for(int x = 0; x < ENV_DIM; x++) {

            //Create node for each position in environment
            Node* newNode = new Node(y, x, 0);
            E->addElement(newNode); 

            if (newNode->getSymbol(env) == SYMBOL_START) {
                S = newNode;
                P->addElement(newNode);  
                std::cout << "Start found at " << y << "," << x << std::endl; //!!!!!!!!!!!!!!!!!!!!!!!!!!
            } else if (newNode->getSymbol(env) == SYMBOL_GOAL) {
                G = newNode; 
                std::cout << "Goal found at " << y << "," << x << std::endl; //!!!!!!!!!!!!!!!!!!!!!!!!!!
            }            
        }
    }

    std::cout << std::endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<std::endl;

    //read environment using the node array. TESTING PURPOSED DELETE ME LATER
    for(int i = 0; i < E->getLength(); i++) {
        
        if(i%ENV_DIM == 0) {
            std::cout << std::endl;
        }
        Node* openN = E->getNode(i);
        std::cout << openN->getSymbol(env);
    }

    std::cout << std::endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<std::endl;

    //DYNAMIC DYNAMIC DYNAMCI


    //STUFF
}

//Original attempt.
// void PathSolver::forwardSearch(Env env){


//     // Environment-List(E) | Open-List(P) | Closed-List(C)
//     NodeList* E = new NodeList();
//     NodeList* P = new NodeList();
//     NodeList* C = new NodeList();

//     // Starting-Node(S) | Goal-Node(G)
//     Node* S;
//     Node* G;

//     // Build Environment-List(E)
//     for(int y = 0; y < ENV_DIM; y++) {
//         for(int x = 0; x < ENV_DIM; x++) {
//                 E->addElement(new Node(y, x, 0));          
//         }
//     }

//     //TESTING TESTING TESING~~~~~~~~~~~~~~~~~~~~~~~
//     // read environment using the node array.
//     for(int i = 0; i < E->getLength(); i++) {
        
//         if(i%ENV_DIM == 0) {
//             std::cout << std::endl;
//         }
//         Node* openN = E->getNode(i);
//         std::cout << env[openN->getRow()][openN->getCol()] ;
//     }
//     //TESTING TESTING TESING~~~~~~~~~~~~~~~~~~~~~~~^


//     // Iterate Environment-List(E) to find Starting-Node(S) & Goal-Node(G)
//     for(int i = 0; i < E->getLength(); i++) {
//         Node* openN = E->getNode(i);
//         char symbol = env[openN->getRow()][openN->getCol()];
//         if(symbol == SYMBOL_START) {
//             S = openN;
//             P->addElement(S);
//         } else if (symbol == SYMBOL_GOAL) {
//             G = openN;
//         } else if (symbol == SYMBOL_WALL) {
//             C->addElement(openN);
//         }
//     }
    

//     // Position(p)
//     Node* p = S;

//     int iterations = 0;
//     do {
//         std::cout << "-0-"; //!!!!!!!!!!!!!!!!!!!!!!!!!!
//         // Iterate Open-List(P) to find next Position(p)
//         // Next position to be closer to goal than current Position(p) and NOT in the Closed-List(C)
//         for(int i = 0; i < P->getLength(); i++) {
//             std::cout << "-1-"; //!!!!!!!!!!!!!!!!!!!!!!!!!!
//             Node* openN = P->getNode(i);
//             std::cout << "-2-"; //!!!!!!!!!!!!!!!!!!!!!!!!!!
//             if (openN->getEstimatedDist2Goal(G) < p->getEstimatedDist2Goal(G) && !C->isNodeInList(openN)) {
//                 std::cout << "-3-"; //!!!!!!!!!!!!!!!!!!!!!!!!!!
//                 p = openN;
//                 std::cout << "-4-"; //!!!!!!!!!!!!!!!!!!!!!!!!!!
//             }
//         }
        
//         // Iterate Environment-List(E) to find Other-Positions(q) in range of Position(p)
//         // Populate Open-List(P) with Other-Positions(q) that are 1 grid step away
//         for(int i = 0; i < E->getLength(); i++) {
//             Node* q = E->getNode(i);
//             std::cout << "-5-"; //!!!!!!!!!!!!!!!!!!!!!!!!!!
//             if(std::abs(q->getCol() - p->getCol()) < 2 && std::abs(q->getRow() - p->getRow()) <2) {
//                 std::cout << "-6-"; //!!!!!!!!!!!!!!!!!!!!!!!!!!
//                 q->setDistanceTraveled(p->getDistanceTraveled() + 1);
//                 if(!P->isNodeInList(q)) {
//                     P->addElement(q);
//                     std::cout << "-7-"; //!!!!!!!!!!!!!!!!!!!!!!!!!!
//                 }
//             }      
//         }

//         // Add Position(p) to the Closed-List(C)
//         if(!C->isNodeInList(p)) {
//             C->addElement(p);
//             std::cout << "-8-"; //!!!!!!!!!!!!!!!!!!!!!!!!!!
//         }
        
        
//         iterations++;
//     } while (env[p->getRow()][p->getCol()] != SYMBOL_GOAL);

//     //Solved or failed to find path

//     std::cout <<"Iterations: "  << iterations << std::endl;
//     this->nodesExplored = C;


//     //DELETE NODELISTS HERE.
// }

    



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

    //

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

    //DELETE NODELISTS HERE.
}

//-----------------------------
