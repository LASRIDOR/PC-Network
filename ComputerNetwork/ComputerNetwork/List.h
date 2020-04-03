
#ifndef ECOMMERCE_ITEMLIST_H
#define ECOMMERCE_ITEMLIST_H

#include "node.h"


class List {
private:
    Node* head;
    Node* tail;

public:
    void addToTail(Node* new_item);
    bool deleteItem(const char *item_name);
    bool isEmpty()   const;
    void printList() const;
    Node *getHead();
    Node *findItem(const char *item_name);
public:

    List();
    ~List();
    List(const List& other);
    List(List&& other);
    const List& operator=(const List& other);

private:
    bool itemIsInList(const Node& new_item);

};


#endif //ECOMMERCE_ITEMLIST_H
