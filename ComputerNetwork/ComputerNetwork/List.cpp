
#include "List.h"

List::List() {
    head = tail = nullptr;
}

List::List(const List& other) {
    head = tail = nullptr;
    Node* itemToCopyFromList = other.head;
    while(itemToCopyFromList) {
        Node* CopiedNode = new Node(*itemToCopyFromList);
        CopiedNode->next = nullptr;
        addToTail(CopiedNode);
        itemToCopyFromList = itemToCopyFromList->next;
    }
}

List::List(List&& other) {
    head = other.head;
    tail = other.tail;

    other.head = nullptr;
    other.tail = nullptr;
}

List::~List() {
    Node* itemToDeleteInList = head;
    Node* nextItem;
    while(itemToDeleteInList) {
        nextItem = itemToDeleteInList->next;
        delete itemToDeleteInList;
        itemToDeleteInList = nextItem;
    }
}

const List& List::operator=(const List& other) {
    if (this != &other) {
        Node* itemInListOther = other.head;
        while (itemInListOther) {
            Node* copyOfItemInListOther = new Node(*itemInListOther);
            copyOfItemInListOther->next = nullptr;
            addToTail(copyOfItemInListOther);
            itemInListOther = itemInListOther->next;
        }
    }
    else {
        return *this;
    }
}

bool List::isEmpty() const {
    return head == nullptr;
}

void List::addToTail(Node* newNodeToAdd) {
    if (isEmpty()) {
        head = tail = newNodeToAdd;
    } else {
        tail->next = newNodeToAdd;
        tail = newNodeToAdd;
    }
}

void List::addToTail(Computer computer) {
    Node* newNode = new Node(computer, nullptr);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}


Node*List::find(Computer computerToFind) {
    Node *NodeInList = head;
    while (NodeInList) {
        if(NodeInList->computer == computerToFind) {
            return NodeInList;
        }
        NodeInList = NodeInList->next;
    }
    return nullptr;
}

void List::printList() const {
    if (head != nullptr) {
        head->printNode();
    }
}

Node *List::getHead() const {
    return head;
}

ostream &operator<<(ostream &os, const List &list) {
    Node *currentNode = list.head;
    while (currentNode) {
        os << currentNode->getComputer() << "->";
        currentNode = currentNode->getNext();
    }
    return os;
}
