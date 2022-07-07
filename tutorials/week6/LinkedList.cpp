#include "LinkedList.h"

LinkedList::LinkedList() {
    this->count = 0;
    this->head = nullptr;
    this->back = nullptr;
}

LinkedList::~LinkedList() {
    clear();
}

int LinkedList::size() {
    return this->count;
}

void LinkedList::clear() {
    Node* current = this->head;
    Node* next = this->head->next;
    while (next != nullptr) {
        delete current;
        current = next;
        next = current->next;
    }
    delete current;
    this->count = 0;
    this->head = nullptr;
    this->back = nullptr;
}

int LinkedList::get(int i) {
    Node* node = this->head;
    for(int j = 0; j < i; j++) {
        node = node->next;
    }
    return node->data;
}

void LinkedList::addFront(int data) {
    Node* newNode = nullptr;
    if(this->count < 1) { 
        // This is the only node in chain, store it as back node & head node
        newNode = new Node(data, nullptr);
        this->back = newNode;
    } else {
        newNode = new Node(data, this->head);
    }
    this->head = newNode;
    this->count++;
}

void LinkedList::addBack(int data) {
    Node* newNode = new Node(data, nullptr);
    if(this->count < 1) { 
        // This is the only node in chain, store it as back node & head node
        this->head = newNode;
    } else {
        this->back->next = newNode;
    } 
    this->back = newNode;
    this->count++;
}
