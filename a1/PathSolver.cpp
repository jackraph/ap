#include "PathSolver.h"
#include <iostream>

PathSolver::PathSolver(){
    
}


PathSolver::~PathSolver(){
    delete nodesExplored;
    nodesExplored = nullptr;
}

void PathSolver::forwardSearch(Env env){
    int maxSize = env.size() * env.size() * 4;

    // Environment-List(E) | Open-List(P) | Closed-List(C)
    NodeList* E = new NodeList(maxSize);
    NodeList* P = new NodeList(maxSize);
    NodeList* C = new NodeList(maxSize);

    // Starting-Node(S) | Goal-Node(G)
    Node* S = nullptr;
    Node* G = nullptr;

    // Build Environment-List(E) from given env, then find Starting-Node(S) & Goal-Node(G)
    for(int y = 0; y < (int)env.size(); y++) {
        for(int x = 0; x < (int)env[0].size(); x++) {

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

        //Select a Position(p) from Open-List(P) that has the smallest estimated distance to goal and is not in the Closed-List(C)
        for(int i = 0; i < P->getLength(); i++) {
            Node* n = P->getNode(i);
            //New-Position(n) is not the Closed-List(C)
            if(!C->isPosInList(n)) {            
                //Current Position(p) is in the Closed-List(C) or New-Position(n) is closer to the goal
                if(C->isPosInList(p) || n->getEstimatedDist2Goal(G) < p->getEstimatedDist2Goal(G)) { 
                    p = n; 
                }           
            }
        }  

        // For each Other-Position(q) in Environment-List(E)
        for(int i = 0; i < E->getLength(); i++) {
            Node* q = E->getNode(i);

            // If Other-Position(q) is 1 grid-step away from Position(p) & is not a wall then it is reachable
            bool reachable = false;
            if((std::abs(q->getRow() - p->getRow()) == 1 && q->getCol() == p->getCol()) 
            || (std::abs(q->getCol() - p->getCol()) == 1 && q->getRow() == p->getRow())) { 
                if(q->getSymbol(env) != SYMBOL_WALL) {
                    reachable = true;
                }
            }

            // Add the reachable Other-Position(q) to the Open-List(P) if it is NOT already in the list
            // Set the distance_travelled of Other-Position(q) to be one more that that of Position(p)
            if(reachable) {
                if(!(P->isPosInList(q))) {  
                    q->setDistanceTraveled(p->getDistanceTraveled() + 1);      
                    P->addElement(q); 
                }                           
            }
        }

        //Add Position(p) to the Closed-List(C)
        C->addElement(p);

     iterations++;
    } while (p->getSymbol(env) != SYMBOL_GOAL && iterations < E->getLength());


    //Update nodesExplored with a deep copy of C
    nodesExplored = new NodeList(*C, maxSize);

    delete E;
    delete P;
    delete C;
}

NodeList* PathSolver::getNodesExplored(){
    return new NodeList(*this->nodesExplored);
}

NodeList* PathSolver::getPath(Env env){
    int maxSize = env.size() * env.size() * 4;

    // Explored-List(E) | Open-List(P) | Closed-List(C)
    NodeList* E = new NodeList(*this->nodesExplored, maxSize);
    NodeList* P = new NodeList(maxSize);
    NodeList* C = new NodeList(maxSize);

    // Goal-Node(G)
    Node* G = nullptr;

    // Find Goal-Node(G)
    for(int i = 0; i < nodesExplored->getLength(); i++){
        Node* n = nodesExplored->getNode(i);

       if (n->getSymbol(env) == SYMBOL_GOAL) {
            G = n; 

        }
    }

    P->addElement(G);

    // Position(p)
    Node* p = G;

    int iterations = 0;
    
    do {

        //Select a Position(p) from Open-List(P) that has a distance travelled one less than Position(p)
        for(int i = 0; i < P->getLength(); i++) {
            Node* n = P->getNode(i);
            //std::cout << "Position(p) distance travelled: " << p->getDistanceTraveled() << std::endl;
            //std::cout << "Other pos(n) distance travelled: " << n->getDistanceTraveled() << std::endl;
            if(p->getDistanceTraveled() -1 == n->getDistanceTraveled()) {   
                p = n; 
            }           
        }  

        //Find Neighbour(q) and add it to Open-List(P) if it is NOT already in the list
        for(int i = 0; i < E->getLength(); i++) {
            Node* q = E->getNode(i);

            if((std::abs(q->getRow() - p->getRow()) == 1 && q->getCol() == p->getCol()) 
            || (std::abs(q->getCol() - p->getCol()) == 1 && q->getRow() == p->getRow())) { 
               if(!(P->isPosInList(q))) {     
                    P->addElement(q);
                }       
            }
        }

        //Add Position(p) to the Closed-List(C)
        C->addElement(p);

     iterations++;
    } while (p->getSymbol(env) != SYMBOL_START && iterations < E->getLength());
    
    //Flip the closed list to get the path from start to finish.
    this->solvedPath = new NodeList(maxSize);
    for(int i = 1; i <= C->getLength(); i++) {
        solvedPath->addElement(C->getNode(C->getLength() - i));
    }

    delete E;
    delete P;
    delete C;

    //Return a deep copy of the path
    return new NodeList(*solvedPath, maxSize);
}

