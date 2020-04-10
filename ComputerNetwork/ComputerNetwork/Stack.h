#ifndef __STACK_H
#define __STACK_H

#include <iostream>
#include <stdlib.h>
using namespace std;

#pragma warning (disable: 4996)

#include "ItemTypeNode.h"

class Stack {
public:
	Stack();
	~Stack();
	void MakeEmpty();
	int IsEmpty();
	void Push(Data item);
	void Push(int line,int ComputerPoint);
	Data Pop();
private:
	ItemTypeNode* top;
};


#endif // !__STACK_H