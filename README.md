# linkedList
Learning C++ by making a linked list helper tool

# Documentation

## Functions available

`int getNumberOfNodes();` Getter for how many nodes you have
`void add(string data = "");` Add a node
`void remove(Node* node);` Remove a node
`Node* get(int index);` Returns node of a specific index (think array) and moves cursor to that node
`Node* current();` Returns node of the cursors current position
`void moveToNext();` Moves cursor to the next node if not on last (will probably make this return a bool so you know if it did anything)
`void moveToHead();` Moves cursor to the start
`void moveToTail();` Moves cursor to the end
