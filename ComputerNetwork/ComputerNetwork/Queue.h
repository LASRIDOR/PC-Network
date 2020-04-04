
#ifndef __QUEUE_H
#define __QUEUE_H

#include <iostream>
#include <stdlib.h>
using namespace std;

#pragma warning (disable: 4996)

typedef int Type;

class Queue {
private:
	Type* data;
	int head, tail;
	int MAX_SIZE;
	int AddOne(int x);
public:
	Queue(int size_of_data);
	~Queue();
	void MakeEmpty(void);
	int IsEmpty(void);
	Type Front(void);
	void EnQueue(Type item);
	Type DeQueue(void);
};

#endif // !__QUEUE_H