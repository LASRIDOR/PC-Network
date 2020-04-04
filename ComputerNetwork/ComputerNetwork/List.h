
#ifndef ECOMMERCE_ITEMLIST_H
#define ECOMMERCE_ITEMLIST_H

#include "node.h"

typedef int Type;

class List {
private:
    Node* head;
    Node* tail;

public:
    void addToTail(Node* NewNodeToAdd);
    bool DeleteNodeFromList(Type TypeToDeleteFromList);
    bool isEmpty()   const;
    void printList() const;
    Node *getHead();
    Node *findNode(Type TypeToFind);
    bool TypeIsInList(const Node& NewNode);
public:

    List();
    ~List();
    List(const List& other);
    List(List&& other);
    const List& operator=(const List& other);

};


#endif //ECOMMERCE_ITEMLIST_H
