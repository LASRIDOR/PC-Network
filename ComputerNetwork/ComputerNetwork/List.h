
#ifndef __LIST_H
#define __LIST_H

#include <iostream>
#include <stdlib.h>
using namespace std;

#pragma warning (disable: 4996)

#include "Square.h"

class List {
private:
	Square *data;
	int head, tail;
	int MAX_SIZE;
	int AddOne(int x);
public:
	List(int size_of_data);
	~List();
	void MakeEmpty(void);
	int IsEmpty(void);
	Square Front(void);
	void EnQueue(Square item);
	Square DeQueue(void);
};

#endif // !__LIST_H