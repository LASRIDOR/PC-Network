

#include "List.h"

List::List() {
    head = tail = nullptr;
}

List::List(const List& other) {
    head = tail = nullptr;
    Node* other_item = other.head;
    while(other_item) {
        Node* curr_item = new Node(*other_item);
        curr_item->next = nullptr;
        addToTail(curr_item);
        other_item = other_item->next;
    }
}

List::List(List&& other) {
    head = other.head;
    tail = other.tail;

    other.head = nullptr;
    other.tail = nullptr;
}

List::~List() {
    Node*temp = head;
    Node*next_temp;
    while(temp) {
        next_temp = temp->next;
        delete temp;
        temp = next_temp;
    }
}

const List& List::operator=(const List& other) {
    if (this != &other) {
        if (this->head != nullptr) {
            this->~List();
        }
        Node* curr_other = other.head;
        while (curr_other != nullptr) {
            Node* temp = new Node(*curr_other);         // check goes to copy
            temp->next = nullptr;
            addToTail(temp);
            curr_other = curr_other->next;
        }
    }
    else {
        return *this;
    }
}

bool List::isEmpty() const {
    return head == nullptr;
}

void List::addToTail(Node* new_item) {
    if(!itemIsInList(*new_item)) { // add quantity to exist item
        if (isEmpty()) {
            head = tail = new_item;
        } else {
            tail->next = new_item;
            tail = new_item;
        }
    }
}

bool List::deleteItem(const char *item_name) {
    Node*prev = nullptr;
    Node *curr = head;

    if(isEmpty()) {
        return false;
    } else {
        while(curr) {
            if(strcmp(item_name, curr->next) == 0) {
                if(!prev) {
                    head = curr->next;
                    delete curr;
                } else if(!curr->next) {
                    prev->next = curr->next;
                    tail = prev;
                    delete curr;
                } else {
                    prev->next = curr->next;
                    delete curr;
                }
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    return false;
}

bool List::itemIsInList(const Node& new_item) { // remeber he add to quantity already
    Node* temp = head;
    while (temp) {
        if (strcmp(temp->name, new_item.name) == 0) {
            temp->quantity += new_item.quantity;
            return true;
        }
        temp = temp->getNext();
    }
    return false;
}

Node*List::findItem(const char *item_name) {
    Node *temp = head;
    while (temp) {
        if(strcmp(temp->name, item_name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void List::printList() const {
    Node*curr = head;
    while(curr) {
        curr->printItem();
        curr = curr->next;
    }
}

Node *List::getHead() {
    return head;
}