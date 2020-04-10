#ifndef __NODE_H
#define __NODE_H

#include <iostream>
#include <stdlib.h>
using namespace std;
#pragma warning (disable: 4996)

typedef int Type;

class Node {
	friend class List;
public:
	Node() = default;
	Node(int num, Node* nextnode);
	~Node();

	void setNum(int num);
	Type getNum();

	void printNodeNum();

private:
	Type m_num;;
	Node* next;
};

#endif // !__NODE_H