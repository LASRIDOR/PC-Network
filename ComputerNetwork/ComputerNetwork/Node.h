#ifndef __NODE_H
#define __NODE_H

#include <iostream>
#include <stdlib.h>
#include "Computer.h"

using namespace std;
#pragma warning (disable: 4996)


class Node {
	friend class List;
public:
	Node(Computer computer, Node* nextnode);
	~Node();

	Computer getComputer() const;
	int getComputerID();
    Node *getNext() const;

    void printNode();

private:
	Computer computer;
	Node* next;
};

#endif // !__NODE_H