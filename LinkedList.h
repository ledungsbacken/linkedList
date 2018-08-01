#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

class LinkedList
{
private:
    Node* cursor;
    Node* temp;
    Node* tail;
    Node* head;
    int numberOfNodes = 0;
public:
    int getNumberOfNodes() { return this->numberOfNodes; }
    void add(string data = "");
    void remove(Node* node);
    Node* get(int index);
    Node* current();
    void moveToNext();
    void moveToHead();
    void moveToTail();
};
