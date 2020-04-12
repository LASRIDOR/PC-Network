#include "Node.h"

Node::Node(Computer computer, Node* nextnode) : computer(computer){
	this->next = nextnode;
}

Node::~Node() {
	delete[] this->next;
}

Computer Node::getComputer() const {
	return this->computer;
}
int Node::getComputerID() {
	return this->computer.getID();
}

void Node::printNode() {
	cout << this->computer.getID() << "->";
	if(this->next != nullptr)
        this->next->printNode();
}

Node *Node::getNext() const {
    return next;
}
