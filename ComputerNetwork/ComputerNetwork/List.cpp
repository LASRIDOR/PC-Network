
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
        if (this->head != nullptr) {
            this->~List();
        }
        Node* itemInListOther = other.head;
        while (itemInListOther != nullptr) {
            Node* copyOfItemInListOther = new Node(*itemInListOther);         // check goes to copy
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
    if(!numIsInList(*newNodeToAdd)) { // add quantity to exist item
        if (isEmpty()) {
            head = tail = newNodeToAdd;
        } else {
            tail->next = newNodeToAdd;
            tail = newNodeToAdd;
        }
    }
}

bool List::DeleteNodeFromList(Type TypeToDeleteFromList) {
    Node* PrevOfCurr = nullptr;
    Node *CurrNodeInList = head;

    if(isEmpty()) {
        return false;
    } else {
        while(CurrNodeInList) {
            if(NumToDeleteFromList == CurrNodeInList->m_num) {
                if(!PrevOfCurr) {
                    head = CurrNodeInList->next;
                    delete CurrNodeInList;
                } else if(!CurrNodeInList->next) {
                    PrevOfCurr->next = CurrNodeInList->next;
                    tail = PrevOfCurr;
                    delete CurrNodeInList;
                } else {
                    PrevOfCurr->next = CurrNodeInList->next;
                    delete CurrNodeInList;
                }
                return true;
            }
            PrevOfCurr = CurrNodeInList;
            CurrNodeInList = CurrNodeInList->next;
        }
    }
    return false;
}

bool List::TypeIsInList(const Node& NewNode) {
    Node* NodeInList = head;
    while (NodeInList) {
        if (NewNode.m_num == NodeInList->m_num)
            return true;
        NodeInList = NodeInList->next;
    }
    return false;
}

Node*List::findNode(Type TypeToFind) {
    Node *NodeInList = head;
    while (NodeInList) {
        if(NodeInList->m_num == NumToFind) {
            return NodeInList;
        }
        NodeInList = NodeInList->next;
    }
    return nullptr;
}

void List::printList() const {
    head->printNodeNum();
}

Node *List::getHead() {
    return head;
}