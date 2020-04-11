#include "ItemTypeNode.h"

ItemTypeNode::ItemTypeNode(int line, int ComputerPoint, ItemTypeNode* nextnode) {
	this->data.ComputerID = ComputerPoint;
	this->data.line = line;
}
ItemTypeNode::ItemTypeNode(Data data, ItemTypeNode* next) {
	this->data = data;
	this->next = next;
}
ItemTypeNode::~ItemTypeNode() {
}

void ItemTypeNode::setData(int ComputerPoint, int line) {
	this->data.ComputerID = ComputerPoint;
	this->data.line = line;
}
void ItemTypeNode::setNext(ItemTypeNode* next) {
	this->next = next;
}
Data ItemTypeNode::getData()const {
	return this->data;
}
ItemTypeNode* ItemTypeNode::getNext() const {
	return this->next;
}
void ItemTypeNode::printNode() {
	cout << this->data.line << " " << this->data.ComputerID << endl;
	this->next->printNode();
}