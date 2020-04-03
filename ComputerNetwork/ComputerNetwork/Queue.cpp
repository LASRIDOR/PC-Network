#include "Queue.h"

Queue::Queue(int size_of_data) {
	head = 1;
	tail = 0;
	data = new Square[size_of_data];
	MAX_SIZE = size_of_data;
}
Queue::~Queue() {
	delete []data;
}
int Queue::AddOne(int x) {
	return ((1 + x) % MAX_SIZE);
}
void Queue::MakeEmpty(void) {
	head = 1;
	tail = 0;
}
int Queue::IsEmpty(void) {
	return (AddOne(tail) == head);
}
Square Queue::Front(void) {
	if (IsEmpty()) {
		cout << "Error: QUEUE EMPTY\n";
		exit(1);
	}
	return (data[head]);
}
void Queue::EnQueue(Square item) {
	if (AddOne(AddOne(tail)) == head) {
		cout << "Error: QUEUE IS FULL\n";
	}
	tail = AddOne(tail);
	data[tail] = item;
}
Square Queue::DeQueue(void) {
	if (IsEmpty()) {
		cout << "Error: QUEUE EMPTY\n";
		exit(1);
	}
	Square item = data[head];
	head = AddOne(head);
	return (item);
}