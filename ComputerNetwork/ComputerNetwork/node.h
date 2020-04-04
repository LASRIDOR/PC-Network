#ifndef __NODE_H
#define __NODE_H

#include <iostream>
#include <stdlib.h>
using namespace std;
#pragma warning (disable: 4996)

class Node {
	friend class List;
public:
	Node() = default;
	Node(int num,Node* next);
	~Node();

	void setNum(int num);
	void setNext(Node* nextnode);

	int getNum();
	Node* GetNext();

	void printNodeNum();
private:
	int m_num;
	Node* next;
};

#endif // !__NODE_H