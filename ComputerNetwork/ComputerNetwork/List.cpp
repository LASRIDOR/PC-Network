#include "List.h"

List::List(int size_of_data) {
	head = 1;
	tail = 0;
	data = new Square[size_of_data];
	MAX_SIZE = size_of_data;
}
List::~List() {
	delete []data;
}
int List::AddOne(int x) {
	return ((1 + x) % MAX_SIZE);
}
void List::MakeEmpty(void) {
	head = 1;
	tail = 0;
}
int List::IsEmpty(void) {
	return (AddOne(tail) == head);
}
Square List::Front(void) {
	if (IsEmpty()) {
		cout << "Error: LIST EMPTY\n";
		exit(1);
	}
	return (data[head]);
}
void List::EnQueue(Square item) {
	if (AddOne(AddOne(tail)) == head) {
		cout << "Error: LIST IS FULL\n";
	}
	tail = AddOne(tail);
	data[tail] = item;
}
Square List::DeQueue(void) {
	if (IsEmpty()) {
		cout << "Error: LIST EMPTY\n";
		exit(1);
	}
	Square item = data[head];
	head = AddOne(head);
	return (item);
}