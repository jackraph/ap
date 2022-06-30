#include "PathSolver.h"
#include <iostream>

PathSolver::PathSolver(){
    // TODO ???
}

PathSolver::~PathSolver(){
    //TODO ???
    delete nodesExplored;
    nodesExplored = nullptr;
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
    //Add Starting-Node(S) to the Open-List(P)
    P->addElement(S);  

    // Position(p) begins at start
    Node* p = S;

    int iterations = 0;
    //Repeat until goal is found or there is no reachable goal.
    do {

        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // For each Other-Position(q) in Environment-List(E)
        for(int i = 0; i < E->getLength(); i++) {
            Node* q = E->getNode(i);

            // If Other-Position(q) is 1 grid-step away from Position(p) & is not a wall then it is reachable
            bool reachable = false;
            if(std::abs(q->getRow() - p->getRow()) == 1 && q->getCol() == p->getCol() 
            || std::abs(q->getCol() - p->getCol()) == 1 && q->getRow() == p->getRow()) { 
                if(q->getSymbol(env) != SYMBOL_WALL) {
                    reachable = true;
                }
            }

            // Add the reachable Other-Position(q) to the Open-List(P) if it is NOT already in the list
            // Set the distance_travelled of Other-Position(q) to be one more that that of Position(p)
            if(reachable) {
                if(!(P->isNodeInList(q))) {        
                    P->addElement(q); 
                    q->setDistanceTraveled(p->getDistanceTraveled() + 1);
                }                           
            }
        }
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

        //Add Position(p) to the Closed-List(C)
        C->addElement(p);

     iterations++;
    } while (p->getSymbol(env) != SYMBOL_GOAL && iterations < E->getLength());


    //Update create new deep copy of C for nodesExplored
    nodesExplored = C;


    //      ~~~~~~TESTING~~~~~
    // std::cout << std::endl << "Position(p) at Goal: " << p->getRow() << ", " << p->getCol() << "  After the loop.";
    // std::cout << std::endl << "Steps taken to reach (G): " << p->getDistanceTraveled();

    //TESTING STUFF
    // for(int i = 0; i < C->getLength(); i++) {

    //     Node* n = C->getNode(i);
    //     std::cout << n->getRow() << "," << n->getCol() << std::endl; 
    // }

    // std::cout << std::endl << "-------------------_EXPLORED------------------" << std::endl; 
    // for(int i = 0; i < nodesExplored->getLength(); i++) {

    //     Node* n = nodesExplored->getNode(i);
    //     std::cout << n->getRow() << "," << n->getCol() << ", " << n->getDistanceTraveled() << std::endl; 
    // }

    // std::cout << std::endl << "-------------------_ENVIRONMENT------------------" << std::endl; 
    // for(int i = 0; i < E->getLength(); i++) {

    //     if(i % ENV_DIM == 0) {
    //         std::cout << std::endl;
    //     }

    //     Node* n = E->getNode(i);
    //     std::cout << n->getSymbol(env); 
    // }

    // std::cout << std::endl << "-------------------_ENVIRO-Distance------------------" << std::endl; 
    // for(int i = 0; i < E->getLength(); i++) {

    //     if(i % ENV_DIM == 0) {
    //         std::cout << std::endl;
    //     }

    //     Node* n = E->getNode(i);
    //     int cell = 100 + n->getDistanceTraveled();
    //     std::cout << "|" << cell; 
    // }
}

NodeList* PathSolver::getNodesExplored(){
    return this->nodesExplored;
}

//Third attempt.
NodeList* PathSolver::getPath(Env env){

    // Explored-List(E) | Open-List(P) | Closed-List(C)
    NodeList* E = new NodeList(*this->nodesExplored);
    NodeList* P = new NodeList();
    NodeList* C = new NodeList();

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

    //Add goal node to the Open-List(P)
    P->addElement(G);  

    // Position(p)
    Node* p = G;

    int iterations = 0;
    
    do {

        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        //Select a Position(p) from Open-List(P) that has a distance travelled one less than Position(p)
        for(int i = 0; i < P->getLength(); i++) {
            Node* n = P->getNode(i);
            if(p->getDistanceTraveled() -1 == n->getDistanceTraveled()) { 
                p = n; 
            }           
        }  
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        //Find Neighbour(q) and add it to Open-List(P) if it is NOT already in the list
        for(int i = 0; i < E->getLength(); i++) {
            Node* q = E->getNode(i);

            if(std::abs(q->getRow() - p->getRow()) == 1 && q->getCol() == p->getCol() 
            || std::abs(q->getCol() - p->getCol()) == 1 && q->getRow() == p->getRow()) { 
               if(!(P->isNodeInList(q))) {        
                    P->addElement(q);
                }       
            }
        }
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

        //Add Position(p) to the Closed-List(C)
        C->addElement(p);

     iterations++;
    } while (p->getSymbol(env) != SYMBOL_START && iterations < E->getLength());

    return C;
}

//-----------------------------
