//
// Created by Nadav Suliman on 10/4/20.
//

#include "Network.h"

Network::Network(int numOfConnections, int numOfComputers) : numOfConnections(numOfConnections),
                                                             numOfComputers(numOfComputers) {
    connections = new List[this->numOfComputers + 1];
}

Network::Network(const Network& other) {
    this->numOfComputers = other.numOfComputers;
    this->numOfConnections = other.numOfConnections;
    this->connections = new List[this->numOfComputers + 1];
    for (int i = 0; i < numOfComputers; ++i) {
        connections[i] = other.connections[i];
    }
}

Network::~Network() {
    delete connections;
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

const List& Network::operator[](int index) const {
    return this->connections[index];
}

ostream &operator<<(ostream &os, const Network &network) {
    for (int i = 1; i <= network.numOfComputers; ++i) {
        os << i << ": " << network[i] << endl;
    }
    return os;
}
