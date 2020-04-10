#ifndef __STACK_H
#define __STACK_H

#include <iostream>
#include <stdlib.h>
using namespace std;

#pragma warning (disable: 4996)

#include "Node.h"

typedef int Type;

class Stack {
public:
	Stack();
	~Stack();
	void MakeEmpty();
	int IsEmpty();
	void Push(Type square);
	Computer Pop();
	Computer Top();
private:
	Node* top;
};


#endif // !__STACK_H