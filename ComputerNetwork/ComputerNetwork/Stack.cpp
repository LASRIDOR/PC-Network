#include "Stack.h"

Stack::Stack() {
	top = NULL;
}
Stack::~Stack() {
	MakeEmpty();
}
void Stack::MakeEmpty() {
	Node* temp;
	while (top != NULL) {
		temp = top;
		top = top->getNext();
		delete temp;
	}
}
int Stack::IsEmpty() {
	return (top == nullptr);
}
void Stack::Push(Type square) {
	top = new Node(square, top);
}
Computer Stack::Pop() {
	if (IsEmpty()) {
		cout << "Error: Stack underflow\n";
		exit(1);
	}
	Node* temp = top;
	Computer item = top->getComputer();
	top = top->getNext();
	delete temp;
	return (item);
}