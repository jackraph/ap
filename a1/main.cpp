#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

#include "Types.h"
#include "Node.h"
#include "NodeList.h"
#include "PathSolver.h"

// Helper test functions
void testNode();
void testNodeList();

// Read a environment from standard input.
void readEnvStdin(Env env);

// Print out a Environment to standard output with path.
// To be implemented for Milestone 3
void printEnvStdout(Env env, NodeList* solution);


int main(int argc, char** argv){
    // THESE ARE SOME EXAMPLE FUNCTIONS TO HELP TEST YOUR CODE
    // AS YOU WORK ON MILESTONE 2. YOU CAN UPDATE THEM YOURSELF
    // AS YOU GO ALONG.
    // COMMENT THESE OUT BEFORE YOU SUBMIT!!!
    std::cout << "TESTING - COMMENT THE OUT TESTING BEFORE YOU SUBMIT!!!" << std::endl;
    testNode();
    testNodeList();
    std::cout << "DONE TESTING" << std::endl << std::endl;

    // Load Environment 
    Env env;
    readEnvStdin(env);
    
    // Solve using forwardSearch
    // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 2

    PathSolver* pathSolver = new PathSolver();
    pathSolver->forwardSearch(env);

    NodeList* exploredPositions = nullptr;
    exploredPositions = pathSolver->getNodesExplored(); 

    // Get the path
    // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 3
    NodeList* solution = nullptr;
    solution = pathSolver->getPath(env);
    printEnvStdout(env, solution);

    //delete pathSolver;
    //delete exploredPositions;
    //delete solution;

}

// Read environment here.
void readEnvStdin(Env env){

    std::ifstream infile("input.env");
    if (!infile.is_open ()) // ALWAYS TEST IF FILE EXISTS
    {
        std::cout << "Input file not found at path 'input.env'." << std::endl;
        return;
    }

    //Read infile to our Env type.
    for(int y = 0; y < ENV_DIM; y++) {
        for(int x = 0; x < ENV_DIM; x++) {
            infile >> env[y][x];
        }
    }

    //Print env to console.
    // for(int y = 0; y < ENV_DIM; y++) {
    //     for(int x = 0; x < ENV_DIM; x++) {
    //         std::cout << env[y][x];      
    //     }
    //     std::cout << std::endl;
    // }

    std::cout << "File Read." << std::endl;
    
}

// Print solution here.
void printEnvStdout(Env env, NodeList* solution) {

    std::cout << std::endl << "-------------------_PATH------------------" << std::endl; 
    
    // for(int i = 0; i < solution->getLength(); i++) {

    //     Node* n = solution->getNode(i);
    //     std::cout << n->getRow() << "," << n->getCol() << "," << std::endl; 
    // }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    for(int i = 0; i < solution->getLength(); i++) {

        if(i%ENV_DIM == 0) { std::cout << std::endl; }

        Node* n = solution->getNode(i);
        std::cout << env[n->getRow()][n->getCol()]; 
    }

    for(int y = 0; y < ENV_DIM; y++) {
        std::cout << std::endl;
        for(int x = 0; x < ENV_DIM; x++) {

            //For each step check if solution contains a matching position.
            bool match = false;
            for(int i = 0; i < solution->getLength(); i++) {
                Node* n = solution->getNode(i);
                if(n->getRow() == y && n->getCol() == x) {
                    match = true;
                }
            }

            if(match) {
                std::cout << "x";
            } else {
                std::cout << env[y][x];
            }
        }
    }
}

void testNode() {
    std::cout << "TESTING Node" << std::endl;

    // Make a Node and print out the contents
    Node* node = new Node(1, 1, 2);
    std::cout << node->getRow() << ",";
    std::cout << node->getCol() << ",";
    std::cout << node->getDistanceTraveled() << std::endl;
    delete node;

    // Change Node and print again
    node = new Node(4, 2, 3);
    std::cout << node->getRow() << ",";
    std::cout << node->getCol() << ",";
    std::cout << node->getDistanceTraveled() << std::endl;
    delete node;
}

void testNodeList() {
    std::cout << "TESTING NodeList" << std::endl;

    // Make a simple NodeList, should be empty size
    NodeList* nodeList = new NodeList();
    std::cout << "NodeList size: " << nodeList->getLength() << std::endl;

    // Add a Node to the NodeList, print size
    Node* b1 = new Node(1, 1, 1);
    nodeList->addElement(b1);
    std::cout << "NodeList size: " << nodeList->getLength() << std::endl;

    // Add second Nodetest
    Node* b2 = new Node(0, 0, 1);
    nodeList->addElement(b2);
    std::cout << "NodeList size: " << nodeList->getLength() << std::endl;

    // Test Get-ith - should be 0,0,1
    Node* getB = nodeList->getNode(1);
    std::cout << getB->getRow() << ",";
    std::cout << getB->getCol() << ",";
    std::cout << getB->getDistanceTraveled() << std::endl;

    // Print out the NodeList
    std::cout << "PRINTING OUT A NODELIST IS AN EXERCISE FOR YOU TO DO" << std::endl;


}