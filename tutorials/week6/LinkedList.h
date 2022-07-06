#include "Node.h"

class LinkedList {

public:
    LinkedList();
    ~LinkedList();

    //Return the number of nodes in the list
    int size();

    //Deletes all nodes in the chain from memory
    void clear();

    //Return the data stored in the ith node
    int get(int i);

    //Add a new node to the front of the chain
    void addFront(int data);

    //Add a new node to the back of the chain
    void addBack(int data);

private:

    //The first node in the chain
    Node* head;

    //The last node in the chain
    Node* back;

    //The number of nodes contained in the chain
    int count;
};