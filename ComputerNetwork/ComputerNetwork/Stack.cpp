#include "Stack.h"

Stack::Stack() {
	top = NULL;
}
Stack::~Stack() {
	MakeEmpty();
}
void Stack::MakeEmpty() {
	ItemTypeNode* temp;
	while (top != NULL) {
		temp = top;
		top = top->getNext();
		delete temp;
	}
}
int Stack::IsEmpty() {
	return (top == nullptr);
}
void Stack::Push(Data item) {
	top = new ItemTypeNode(item, top);
}
void Push(int line, int ComputerPoint) {
	top = new ItemTypeNode(line, ComputerPoint, top);
}
Data Stack::Pop() {
	if (IsEmpty()) {
		cout << "Error: Stack underflow\n";
		exit(1);
	}
	ItemTypeNode* temp = top;
	Data item = top->data;
	top = top->getNext();
	delete temp;
	return (item);
}