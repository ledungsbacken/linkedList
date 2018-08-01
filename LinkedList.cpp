#include "LinkedList.h"

void LinkedList::add(string data) {
    this->cursor = new Node(data);
    if(this->getNumberOfNodes() > 0) {
        this->tail->setNext(this->cursor);
    } else {
        this->head = this->cursor;
    }
    this->tail = this->cursor;

    this->numberOfNodes++;
}

void LinkedList::remove(Node* node) {
    this->moveToHead();
    this->temp = this->cursor;
    bool isFound = false;
    for(int i = 0; i < this->getNumberOfNodes() && !isFound; i++) {
        if(this->cursor == node) {
            this->moveToNext();
            this->temp->setNext(this->cursor);
            delete node;
            this->numberOfNodes--;
            isFound = true;
        }
        this->temp = this->cursor;
        this->moveToNext();
    }
}

Node* LinkedList::get(int index) {
    this->cursor = this->head;
    for(int i = 0; i < this->getNumberOfNodes(); i++) {
        if(i == index) {
            return this->cursor;
        }
        this->moveToNext();
    }
}

Node* LinkedList::current() {
    return this->cursor;
}

void LinkedList::moveToNext() {
    if(this->cursor->getNext() != NULL) {
        this->cursor = this->cursor->getNext();
    }
}

void LinkedList::moveToHead() {
    this->cursor = this->head;
}

void LinkedList::moveToTail() {
    this->cursor = this->tail;
}
