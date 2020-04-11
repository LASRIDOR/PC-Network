//
// Created by Nadav Suliman on 10/4/20.
//

#ifndef PC_NETWORK_NETWORK_H
#define PC_NETWORK_NETWORK_H


#include <ostream>
#include "List.h"

class Network {
private:
    List* connections;

private:
    int numOfConnections;
    int numOfComputers;

public:
    Network(int numOfConnections, int numOfComputers);
    Network(const Network& other);
    Network(Network&& other);
    virtual ~Network();

    List *getConnections() const;
    int getNumOfConnections() const;
    int getNumOfComputers() const;

    void newConnection(Computer from, Computer to);

    const List& operator[](int index) const;
    friend ostream &operator<<(ostream &os, const Network &network);
};


#endif //PC_NETWORK_NETWORK_H
