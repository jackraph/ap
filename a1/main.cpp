#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Types.h"
#include "Node.h"
#include "NodeList.h"
#include "PathSolver.h"


// Read a environment from standard input
void readEnvStdin(Env &env, std::string);

// Print out a Environment to standard output with path
void printEnvStdout(Env env, NodeList* solution);


int main(int argc, char** argv){

    //Assume second argument passed is the filepath to a text document containing a valid environment.
    if(argc > 1 && argc < 3) {

        std::string filePath = argv[1];

        // Load Environment 
        Env env;
        readEnvStdin(env, filePath);

        // Solve using forwardSearch
        PathSolver* pathSolver = new PathSolver();
        pathSolver->forwardSearch(env);
        NodeList* exploredPositions = nullptr;
        exploredPositions = pathSolver->getNodesExplored(); 

        // Get the path
        NodeList* solution = nullptr;
        solution = pathSolver->getPath(env);
        printEnvStdout(env, solution);

        delete pathSolver;
        delete exploredPositions;
        delete solution;
    } else {
        std::cout << "Please provide a filepath argument when running the program." << std::endl;
    }
}


// Read environment here.
void readEnvStdin(Env& env, std::string filePath){
   
    std::ifstream infile(filePath);
    if (infile.is_open ()) 
    {  
        std::string line;
        // Read each line in the input file, push each char in the line to row vector, push row vector the env
        while(std::getline(infile, line)) {

            std::vector<char> row;
            for(char c : line) { 
                row.push_back(c); 
                }
            env.push_back(row);
        }   
    } 
}

// Print solution here.
void printEnvStdout(Env env, NodeList* solution) {

    //Get the co ordinates of the last node in the solution
    int prevNY = solution->getNode(solution->getLength() -1)->getRow();
    int prevNX = solution->getNode(solution->getLength() -1)->getCol();

    //Loop through ENV
    for(int y = 0; y < (int)env.size(); y++) {
        std::cout << std::endl;
        for(int x = 0; x < (int)env[y].size(); x++) {
             char toPrint = env[y][x];

            //For each env position check if solution contains a matching position, change char toPrint accordingly
            //Work backwards through the solution so the arrows reflect the NEXT step not the previous
            for(int i = 1; i <= solution->getLength(); i++) {

                Node* n = solution->getNode(solution->getLength()-i);
                int nY = n->getRow();
                int nX = n->getCol();

                //Determine direction of the move based on previous move coordinates.
                if(nY == y && nX == x) {      
                    //Inverted because we are working backwards through the solution.
                    if(toPrint != SYMBOL_GOAL && toPrint != SYMBOL_START) {
                        if(prevNY < nY && prevNX == nX) {              
                            toPrint = '^';
                        } else if(prevNY > nY && prevNX == nX) {              
                            toPrint = 'v';
                        } else if(prevNX < nX && prevNY == nY) {         
                            toPrint = '<';
                        } else if(prevNX > nX && prevNY == nY) {        
                            toPrint = '>';
                        }
                    }                   
                }
                prevNY = nY;
                prevNX = nX;
            }
            std::cout << toPrint;       
        }
    }
    std::cout << std::endl;  
}
