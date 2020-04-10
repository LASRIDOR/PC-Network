//
// Created by Nadav Suliman on 10/4/20.
//

#include "Network.h"

Network::Network(int numOfConnections, int numOfComputers) : numOfConnections(numOfConnections),
                                                             numOfComputers(numOfComputers) {
    connections = new List[this->numOfComputers + 1];
}

const List& Network::operator[](int index) const {
    return this->connections[index];
}

void Network::newConnection(Computer from, Computer to) {
    if (from > numOfComputers || to > numOfComputers || from == to) {
        cout << "Invalid input!";
        exit(1);
    }
    connections[from.getID()].addToTail(to);
}

List *Network::getConnections() const {
    return connections;
}

int Network::getNumOfConnections() const {
    return numOfConnections;
}

int Network::getNumOfComputers() const {
    return numOfComputers;
}

ostream &operator<<(ostream &os, const Network &network) {
    for (int i = 1; i <= network.numOfComputers; ++i) {
        os << i << ": " << network[i] << endl;
    }
    return os;
}
