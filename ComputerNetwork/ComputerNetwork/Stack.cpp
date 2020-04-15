#include "Stack.h"

Stack::Stack() {
    top = NULL;
}
Stack::Stack(const Stack& other) {
    Stack tempUpsideDownStack;
    ItemTypeNode* currUpsideDownStack = other.top;
    while (currUpsideDownStack != nullptr) {
        ItemTypeNode* copyNodeToTUDS = new ItemTypeNode(*currUpsideDownStack);
        tempUpsideDownStack.Push(copyNodeToTUDS);
        currUpsideDownStack = currUpsideDownStack->next;
    }
    ItemTypeNode* currThisStack = tempUpsideDownStack.top;
    while (currThisStack!= nullptr) {
        ItemTypeNode* copyNodeToThisStack = currThisStack;
        tempUpsideDownStack.Push(copyNodeToThisStack);
        currThisStack = currThisStack->next;
    }
}
Stack::Stack(Stack&& other) {
    this->top = other.top;

    other.top = nullptr;
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
void Stack::Push(int line, int ComputerPoint) {
    top = new ItemTypeNode(line, ComputerPoint, top);
}
void Stack::Push(ItemTypeNode* item) {
    top = new ItemTypeNode(item->data, top);
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