#include "Node.h"

Node::Node(int num, Node* nextnode) {
	this->m_num = num;
	this->next = nextnode;
}

Node::~Node() {
	delete[]this->next;
}

void Node::setNum(int num) {
	this->m_num = num;
}

int Node::getNum() {
	return this->m_num;
}

void Node::printNodeNum() {
	cout << this->m_num << " ";
	if(this->next != nullptr)
	this->next->printNodeNum();
}