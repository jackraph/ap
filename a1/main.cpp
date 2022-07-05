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
void readEnvStdin(Env &env);

// Print out a Environment to standard output with path
// To be implemented for Milestone 3
void printEnvStdout(Env env, NodeList* solution);

//Milestone 4 additions
Env make_env(const int rows, const int cols);
void delete_env(Env env, int rows, int cols);

//----------------------------------
//DEBUG & TEST FUNCTIONS HERE
void debugPrintEnv(Env env);


int main(int argc, char** argv){

    // Load Environment 
    Env env;
    readEnvStdin(env);
    
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
}


// Read environment here.
void readEnvStdin(Env& env){
   
    std::ifstream infile("input.env");
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

    std::cout << std::endl << "-------------------PATH------------------" << std::endl; 

    //Get the co ordinates of the start node.
    int prevNY = solution->getNode(0)->getRow();
    int prevNX = solution->getNode(0)->getCol();

    //Loop through ENV
    for(int y = 0; y < env.size(); y++) {
        std::cout << std::endl;
        for(int x = 0; x < env[y].size(); x++) {
             char toPrint = env[y][x];

            //For each env position check if solution contains a matching position, change char toPrint accordingly
            for(int i = 0; i < solution->getLength(); i++) {

                Node* n = solution->getNode(i);
                int nY = n->getRow();
                int nX = n->getCol();

                //Determine direction of the move based on previous move coordinates
                if(nY == y && nX == x) {      
                    if(toPrint != SYMBOL_GOAL && toPrint != SYMBOL_START) {
                        if(prevNY < nY && prevNX == nX) {
                            //UP
                            toPrint = '^';
                        } else if(prevNY > nY && prevNX == nX) {
                            //DOWN
                            toPrint = 'v';
                        } else if(prevNX < nX && prevNY == nY) {
                            //LEFT
                            toPrint = '<';
                        } else if(prevNX > nX && prevNY == nY) {
                            //RIGHT
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
}


//----------------------------------
//DEBUG & TEST FUNCTIONS HERE

//Prints a given Env to the console
void debugPrintEnv(Env env) {
    //Print env;
    for(int y = 0; y < env.size(); y++) {
        std::cout << std::endl;
        for(int x = 0; x < env[y].size(); x++) {
            std::cout << env[y][x];
        }
    } 
}