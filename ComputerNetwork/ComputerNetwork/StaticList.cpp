#include "StaticList.h"

StaticList::StaticList(int size_of_data) {
	this->headlist = -1;
	this->taillist = -1;
	this->headfree = 0;
	this->tailfree = size_of_data-1;
	data = new Type*[StaticListSize];
	for (int i = 0; i < StaticListSize; i++) {
		data[i] = new Type[size_of_data];
	}
	for (int i = 0; i < size_of_data;i++) {
		if (i == size_of_data-1) {
			data[NEXTPLACE][i] = -1;
		}
		data[NEXTPLACE][i] = i + 1;
	}
	MAX_SIZE = size_of_data;
}
StaticList::StaticList(const StaticList& other) {
	this->headfree = other.headfree;
	this->headlist = other.headlist;
	this->MAX_SIZE = other.MAX_SIZE;
	this->tailfree = other.tailfree;
	this->taillist = other.taillist;
	data = new Type * [StaticListSize];
	for (int i = 0; i < StaticListSize; i++) {
		data[i] = new Type[MAX_SIZE];
	}
	for (int i = 0; i < StaticListSize; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			this->data[i][j] = other.data[i][j];
		}
	}
}
StaticList::StaticList(StaticList&& other) {
	this->data = other.data;
	other.data = nullptr;
	this->headfree = other.headfree;
	this->headlist = other.headlist;
	this->MAX_SIZE = other.MAX_SIZE;
	this->tailfree = other.tailfree;
	this->taillist = other.taillist;
}
StaticList::~StaticList() {
	for (int i = 0; i < StaticListSize; i++) {
		delete []data[i];
	}
	delete[]data;
}
void StaticList::MakeEmpty(void) {
	this->headlist = -1;
	this->taillist = -1;
	this->headfree = 0;
	this->tailfree = MAX_SIZE - 1;
}
int StaticList::IsEmpty(void) {
	return ((headlist == -1)&&(taillist == -1));
}
Type StaticList::Front(void) {
	if (IsEmpty()) {
		cout << "Error: QUEUE EMPTY\n";
		exit(1);
	}
	return (data[DATAPLACE][this->headlist]); // improve
}
void StaticList::InsertToTail(Type item) {
	if (headfree == -1) {
		cout << "Error: QUEUE IS FULL\n";
	}
	int locNew = headfree;
	headfree = data[NEXTPLACE][headfree];
	data[DATAPLACE][locNew] = item;
	data[NEXTPLACE][locNew] = data[NEXTPLACE][taillist];
	data[NEXTPLACE][taillist] = locNew;
	this->taillist = locNew;
} 
int StaticList::DeleteFromTail(void) {
	if (IsEmpty()) {
		cout << "Error: QUEUE EMPTY\n";
		exit(1);
	}
	int locFree = data[NEXTPLACE][taillist];
	data[NEXTPLACE][taillist] = data[NEXTPLACE][locFree];
	//data[DATAPLACE][locFree] = ;
	data[NEXTPLACE][locFree] = headfree;
	headfree = locFree;
	this->tailfree = locFree;
	return locFree;
}