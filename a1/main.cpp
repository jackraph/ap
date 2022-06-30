#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

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

//Custom testing func
void CreateEnvFromInput();


int main(int argc, char** argv){
    // THESE ARE SOME EXAMPLE FUNCTIONS TO HELP TEST YOUR CODE
    // AS YOU WORK ON MILESTONE 2. YOU CAN UPDATE THEM YOURSELF
    // AS YOU GO ALONG.
    // COMMENT THESE OUT BEFORE YOU SUBMIT!!!
    //std::cout << "TESTING - COMMENT THE OUT TESTING BEFORE YOU SUBMIT!!!" << std::endl;
    //testNode();
    //testNodeList();
    //std::cout << "DONE TESTING" << std::endl << std::endl;

    // Load Environment 
    //Env env;
    //readEnvStdin(env);
    
    // Solve using forwardSearch
    // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 2

    // PathSolver* pathSolver = new PathSolver();
    // pathSolver->forwardSearch(env);

    // NodeList* exploredPositions = nullptr;
    // exploredPositions = pathSolver->getNodesExplored(); 

    // Get the path
    // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 3
    // NodeList* solution = nullptr;
    // solution = pathSolver->getPath(env);
    // printEnvStdout(env, solution);

    //delete pathSolver;
    //delete exploredPositions;
    //delete solution;

    CreateEnvFromInput();
}

// TODO make this return an env i guess.
void CreateEnvFromInput() {

    //Code for determining environment size from filestream input here.     
    std::ifstream infile("input.env");
    
    if (infile.is_open ()) 
    {
        
        std::vector<std::vector<char>> grid;
        std::string line;

        // Read each line in the input file, push each char in the line to row vector, push row vector grid vector
        while(std::getline(infile, line)) {

            std::vector<char> row;
            for(char c : line) { 
                row.push_back(c); 
                }

            grid.push_back(row);
        }
        

        // Print 2d vector to screen now.
        for(int y = 0; y < grid.size(); y++) {
            std::cout << std::endl;
            for(int x = 0; x < grid[y].size(); x++) {

                std::cout << grid[y][x];
            }
        }    

    } else {
    
        // Input file doesn't exist. 
        std::cout << "Input file not found at path 'input.env'." << std::endl;
    }   
}

// Read environment here.
void readEnvStdin(Env env){

    std::ifstream infile("input.env");
    // TEST IF FILE EXISTS BEFORE
    if (!infile.is_open ()) 
    {
        std::cout << "Input file not found at path 'input.env'." << std::endl;
        return;
    } else {
        
        //Read infile to our Env type.
        // for(int y = 0; y < ENV_DIM; y++) {
        //     for(int x = 0; x < ENV_DIM; x++) {
        //         infile >> env[y][x];
        //     }
        // }


        std::string r;
        char c;
        int row = 0;
        int col = 0;
        while(infile.get(c)) {
            
            //If endline reached iterate row
            if(c == '\n') { row++; }


            
        }

        std::cout << "File Read." << std::endl;
    }   
}

// Print solution here.
void printEnvStdout(Env env, NodeList* solution) {

    // std::cout << std::endl << "-------------------PATH------------------" << std::endl; 

    // //Get the co ordinates of the start node.
    // int prevNY = solution->getNode(0)->getRow();
    // int prevNX = solution->getNode(0)->getCol();

    //Loop through ENV
    // for(int y = 0; y < ENV_DIM; y++) {
    //     std::cout << std::endl;
    //     for(int x = 0; x < ENV_DIM; x++) {
    //          char toPrint = env[y][x];

    //         //For each env position check if solution contains a matching position, change char toPrint accordingly
    //         for(int i = 0; i < solution->getLength(); i++) {

    //             Node* n = solution->getNode(i);
    //             int nY = n->getRow();
    //             int nX = n->getCol();

    //             //Determine direction of the move based on previous move coordinates
    //             if(nY == y && nX == x) {      
    //                 if(toPrint != SYMBOL_GOAL && toPrint != SYMBOL_START) {
    //                     if(prevNY < nY && prevNX == nX) {
    //                         //UP
    //                         toPrint = '^';
    //                     } else if(prevNY > nY && prevNX == nX) {
    //                         //DOWN
    //                         toPrint = 'v';
    //                     } else if(prevNX < nX && prevNY == nY) {
    //                         //LEFT
    //                         toPrint = '<';
    //                     } else if(prevNX > nX && prevNY == nY) {
    //                         //RIGHT
    //                         toPrint = '>';
    //                     }
    //                 }                   
    //             }

    //             prevNY = nY;
    //             prevNX = nX;
    //         }

    //         std::cout << toPrint;       
    //     }
    // }

}

void testNode() {
    // std::cout << "TESTING Node" << std::endl;

    // // Make a Node and print out the contents
    // Node* node = new Node(1, 1, 2);
    // std::cout << node->getRow() << ",";
    // std::cout << node->getCol() << ",";
    // std::cout << node->getDistanceTraveled() << std::endl;
    // delete node;

    // // Change Node and print again
    // node = new Node(4, 2, 3);
    // std::cout << node->getRow() << ",";
    // std::cout << node->getCol() << ",";
    // std::cout << node->getDistanceTraveled() << std::endl;
    // delete node;
}

void testNodeList() {
    // std::cout << "TESTING NodeList" << std::endl;

    // // Make a simple NodeList, should be empty size
    // NodeList* nodeList = new NodeList();
    // std::cout << "NodeList size: " << nodeList->getLength() << std::endl;

    // // Add a Node to the NodeList, print size
    // Node* b1 = new Node(1, 1, 1);
    // nodeList->addElement(b1);
    // std::cout << "NodeList size: " << nodeList->getLength() << std::endl;

    // // Add second Nodetest
    // Node* b2 = new Node(0, 0, 1);
    // nodeList->addElement(b2);
    // std::cout << "NodeList size: " << nodeList->getLength() << std::endl;

    // // Test Get-ith - should be 0,0,1
    // Node* getB = nodeList->getNode(1);
    // std::cout << getB->getRow() << ",";
    // std::cout << getB->getCol() << ",";
    // std::cout << getB->getDistanceTraveled() << std::endl;

    // // Print out the NodeList
    // std::cout << "PRINTING OUT A NODELIST IS AN EXERCISE FOR YOU TO DO" << std::endl;


}