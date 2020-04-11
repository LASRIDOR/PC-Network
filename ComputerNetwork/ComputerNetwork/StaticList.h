
#ifndef __STATICLIST_H
#define __STATICLIST_H

#include "Computer.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

#pragma warning (disable: 4996)
#define StaticListSize 2
#define DATAPLACE 0
#define NEXTPLACE 1

typedef int Type;

class StaticList {
private:
	Type** data;
	int headlist,headfree;
	int taillist, tailfree;
	int MAX_SIZE;

public:
	StaticList(int size_of_data = 100);
	~StaticList();
	void MakeEmpty(void);
	int IsEmpty(void);
	Type Front(void);
	void InsertToTail(Type item);
	Type DeleteFromTail(void);
private:
};

#endif // !__STATICLIST_H