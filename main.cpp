#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Node.h"

//#include <typeinfo>
//typeid(variable).name

using namespace std;

// struct node {
// 	int data;
// 	node* next;
// };

struct numbers {
	int data;
	numbers* next;
};

struct operators {
	string data;
	operators* next;
};

int main() {
	//cout << "Hello World!" << endl;
	LinkedList* linkedList;
	linkedList = new LinkedList;
	Node* node;
	node = new Node;
	cout << node->getData() << endl;
	cout << linkedList->numberOfNodes << endl;

	return 0;
	// node* n;
	// node* t;
	// node* h;
/*
	n = new node;
	n->data = 1;
	t = n;
	h = n;

	n = new node;
	n->data = 2;
	t->next = n;
	t = t->next;

	n = new node;
	n->data = 3;
	t->next = n;
	t = t->next;

	n = new node;
	n->data = 4;
	t->next = n;
	t = t->next;

	n->next = NULL;
*/

	numbers* numN;
	numbers* numT;
	numbers* numH;
	operators* opN;
	operators* opT;
	operators* opH;

	int numInput;
	string opInput;
	bool isEven = true;
	for(int i = 0; opInput != "=" && i < 10; i++) {
		isEven = i % 2 == 0;
		if(isEven) {
			cout << "Enter your integer: ";
			cin >> numInput;
		} else if(!isEven) {
			cout << "Enter your operator: ";
			cin >> opInput;
		}

		if(isEven) {
			if(i == 0) {
				numN = new numbers;
				numN->data = numInput;
				numT = numN;
				numH = numN;
			} else {
				numN = new numbers;
				numN->data = numInput;
				numT->next = numN;
				numT = numT->next;
			}
		} else if(!isEven) {
			if(i == 1) {
				opN = new operators;
				opN->data = opInput;
				opT = opN;
				opH = opN;
			} else {
				opN = new operators;
				opN->data = opInput;
				opT->next = opN;
				opT = opT->next;
			}

		}
	}

	bool isEnd = false;

	numN = numH;
	numT = numH;
	opN = opH;
	opT = opH;

	string output;

	int result;

	for(int j = 0; !isEnd; j++) {
		for(int k = 0; k < j; k++) {
			numN = numN->next;
			opN = opN->next;
		}
		for(int l = 0; l < j - 1; l++) {
			opT = opT->next;
		}

		if(j == 0) {
			result = numN->data;
		} else {
			if(opT->data == "+") {
				result = result + numN->data;
			} else if(opT->data == "-") {
				result = result - numN->data;
			} else if(opT->data == "*") {
				result = result * numN->data;
			} else if(opT->data == "/") {
				result = result / numN->data;
			}
		}

		output = output + to_string(numN->data) + " ";
		output = output + opN->data + " ";

		isEnd = numN->next == NULL ? true : false;
	}

	output = output + to_string(result);
	cout << output << endl;



	return 0;
}
