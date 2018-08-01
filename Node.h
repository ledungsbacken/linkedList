#include <iostream>
#include <string>

using namespace std;

class Node
{
private:
    string data;
    Node* next;
public:
    Node(string data = "");
    inline string getData() { return this->data; }
    inline void setData(string value) { this->data = value; }
    inline Node* getNext() { return this->next; }
    inline void setNext(Node* node) { this->next = node; }
};
