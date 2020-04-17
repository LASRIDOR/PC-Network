#ifndef __ITEMTYPENODE_H
#define __ITEMTYPENODE_H

#include <iostream>
#include <stdlib.h>
#include"Node.h"

using namespace std;
#pragma warning (disable: 4996)

/**
 * A Class containing struct of data to help with the replacing the rec with stack
 * as been described in the progEx1.pdf
 * Method # 1
 * the Node is for the whole list for the ComputerID
 * Indicates the next node that needs to be addressed in the list of ComputerID
 * the rules of line is as described in the pdf
 */

struct Data {
	int line, ComputerID;
	Node* NextNodeInListComputerPoint;

};

class ItemTypeNode {
	friend class Stack;
public:
	ItemTypeNode(int line, int ComputerPoint, Node* NextNodeInListComputerPoint, ItemTypeNode* nextnode);
	ItemTypeNode(Data data, ItemTypeNode* next);
	virtual ~ItemTypeNode();
	void setData(int ComputerPoint, int line, Node* NextNodeInListComputerPoint);
	void setNext(ItemTypeNode* next);
	Data getData()const;
	ItemTypeNode* getNext() const;

	void printNode();

private:
	Data data;
	ItemTypeNode* next;
};

#endif // !__ITEMTYPENODE_H