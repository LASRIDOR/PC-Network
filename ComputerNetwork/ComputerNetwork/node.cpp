#include "node.h"

Node::Node(int num, Node* nextnode) {
	setNum(num);
	setNext(nextnode);
}
Node::~Node() {

}

void Node::setNum(int num) {
	this->m_num = num;
}
void Node::setNext(Node* nextnode) {
	this->next = nextnode;
}

int Node::getNum() {
	return this->m_num;
}
Node* Node::GetNext() {
	return this->next;
}