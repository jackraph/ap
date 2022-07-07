class Node {
    
public:
    Node(int data, Node* next);

    Node(Node& other);

    //Data stored by this node
    int data;

    //Next node in the chain
    Node* next;
};