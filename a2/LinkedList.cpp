#include "LinkedList.h"

LinkedList::LinkedList() {
    this->head = nullptr;
    this->back = nullptr;
    this->count = 0;
}

LinkedList::~LinkedList() {
    clear();
}

int LinkedList::size() {
    return this->count;
}

void LinkedList::clear() {
    if(this->count > 0) {
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
}

Tile* LinkedList::get(int i) {
    Node* node = this->head;
    for(int j = 0; j < i; j++) {
        node = node->next;
    }
    return node->tile;
}

void LinkedList::addFront(Tile* tile) {
    Node* newNode = nullptr;
    if(this->count < 1) { 
        newNode = new Node(tile, nullptr);
        this->back = newNode;
    } else {
        newNode = new Node(tile, this->head);
    }
    this->head = newNode;
    this->count++;
}

void LinkedList::addBack(Tile* tile) {
    Node* newNode = new Node(tile, nullptr);
    if(this->count < 1) { 
        this->head = newNode;
    } else {
        this->back->next = newNode;
    } 
    this->back = newNode;
    this->count++;
}
