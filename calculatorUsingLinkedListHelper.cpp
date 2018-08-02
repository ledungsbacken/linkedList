#include <iostream>
#include <string>
#include "linkedList/LinkedList.h"

using namespace std;

struct node {
	int data;
	node* next;
};

struct numbers {
	int data;
	numbers* next;
};

struct operators {
	string data;
	operators* next;
};

int main() {

	numbers* numN;
	numbers* numT;
	numbers* numH;
	LinkedList* operators;
	operators = new LinkedList;

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
			operators->add(opInput);
		}
	}

	bool isEnd = false;

	numN = numH;
	numT = numH;
	operators->moveToHead();

	string output;

	int result;

	for(int j = 0; !isEnd; j++) {
		if(j > 0) {
			numN = numN->next;
		}
		if(j == 0) {
			result = numN->data;
		} else {
			if(operators->current()->getData() == "+") {
				result = result + numN->data;
			} else if(operators->current()->getData() == "-") {
				result = result - numN->data;
			} else if(operators->current()->getData() == "*") {
				result = result * numN->data;
			} else if(operators->current()->getData() == "/") {
				result = result / numN->data;
			}
			operators->moveToNext();
		}

		isEnd = numN->next == NULL ? true : false;

		if(isEnd) {
			operators->moveToNext();
		}

		output = output + to_string(numN->data) + " ";
		output = output + operators->current()->getData() + " ";

	}

	output = output + to_string(result);
	cout << output << endl;



	return 0;
}
