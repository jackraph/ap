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
void readEnvStdin(Env env, Grid grid);

// Print out a Environment to standard output with path
// To be implemented for Milestone 3
void printEnvStdout(Env env, NodeList* solution);

//Milestone 4 additions
Env make_env(const int rows, const int cols);
void delete_env(Env env, int rows, int cols);

//----------------------------------
//DEBUG & TEST FUNCTIONS HERE
void debugPrintEnv(Env env, Grid grid);


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
    Env env;
    Grid grid;
    readEnvStdin(env, grid);
    debugPrintEnv(env, grid);
    //debugPrintEnv(env);
    
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
}

Env make_env(const int rows, const int cols) {
   Env env = nullptr;

   if (rows >= 0 && cols >= 0) {
      env = new char*[rows];
      for (int i = 0; i != rows; ++i) {
         env[i] = new char[cols];
      }
   }
   return env;
}

/*
 * This function is to help you delete a 
 * dynamically allocated 2D Environment.
 */
void delete_env(Env env, int rows, int cols) {
   if (rows >= 0 && cols >= 0) {
      for (int i = 0; i != rows; ++i) {
         delete env[i];
      }
      delete env;
   }
   return;
}


// Read environment here.
void readEnvStdin(Env env){
   
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

        // Create and populate the env
        env = make_env(env.size(), env[0].size());
        for(int y = 0; y < env.size(); y++) {
            for(int x = 0; x < env[y].size(); x++) {
                env[y][x] = env[y][x];
            }
        }    

        //Print env;
        for(int y = 0; y < grid.size(); y++) {
            std::cout << std::endl;
            for(int x = 0; x < grid[y].size(); x++) {
                std::cout << env[y][x];
            }
        }     

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


//----------------------------------
//DEBUG & TEST FUNCTIONS HERE

//Prints a given Env to the console
void debugPrintEnv(Env env, Grid grid) {
    for(int y = 0; y < grid.size(); y++) {
        std::cout << std::endl;
        for(int x = 0; x < grid[y].size(); x++) {
            std::cout << env[y][x];
        }
    }  
}