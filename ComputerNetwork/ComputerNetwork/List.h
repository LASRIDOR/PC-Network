
#ifndef ECOMMERCE_ITEMLIST_H
#define ECOMMERCE_ITEMLIST_H

#include <ostream>
#include "Computer.h"
#include "Node.h"

class List {
private:
    Node* head;
    Node* tail;

public:
    void addToTail(Node* NewNodeToAdd);
    void addToTail(Computer computer);
    //bool DeleteNodeFromList(Type TypeToDeleteFromList);
    void deleteNode(Node *toDelete);
    bool isEmpty()   const;
    void printList() const;
    Node *getHead()  const;
    Node *find(Computer computerToFind);
    //bool TypeIsInList(const Node& NewNode);

public:
    List();
    ~List();
    List(const List& other);
    List(List&& other);

    const List& operator=(const List& other);
    friend ostream &operator<<(ostream &os, const List &list);
};


#endif //ECOMMERCE_ITEMLIST_H
