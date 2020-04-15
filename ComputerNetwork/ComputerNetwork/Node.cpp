#include "Node.h"

Node::Node(Computer computer, Node* nextnode) : computer(computer){
    this->next = nextnode;
}

Computer Node::getComputer() const {
    return this->computer;
}
int Node::getComputerID() {
    return this->computer.getID();
}

Node *Node::DeleteAfter() {
    Node *temp = next;
    if (next == nullptr){
        return nullptr;
    }
    next = temp->next;
    return temp;
}

void Node::printNode() {
    cout << this->computer.getID() << "->";
    if(this->next != nullptr)
        this->next->printNode();
}

Node *Node::getNext() const {
    return next;
}
