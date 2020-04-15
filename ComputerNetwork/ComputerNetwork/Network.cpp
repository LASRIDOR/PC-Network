//
// Created by Nadav Suliman on 10/4/20.
//

#include "Network.h"

/**
 * Constructs a new network - Size of array is numOfComputers.
 * @param numOfConnections
 * @param numOfComputers - size of the array.
 */
Network::Network(int numOfConnections, int numOfComputers) : numOfConnections(numOfConnections),
                                                             numOfComputers(numOfComputers) {
    connections = new List[this->numOfComputers + 1];
}

//Copy constructor
Network::Network(const Network& other) {
    this->numOfComputers = other.numOfComputers;
    this->numOfConnections = other.numOfConnections;
    this->connections = new List[this->numOfComputers + 1];
    for (int i = 0; i < numOfComputers; ++i) {
        connections[i] = other.connections[i];
    }
}

//Move constructor
Network::Network(Network&& other) {
    this->connections = other.connections;
    this->numOfComputers = other.numOfComputers;
    this->numOfConnections = other.numOfConnections;

    other.connections = nullptr;
}

//Destructor
Network::~Network() {
    delete[] this->connections;
}

/**
 * Creates a new connection from computer 'from' to computer 'to' by adding a new node in the relevant place in the
 * data structure.
 * @param from - the computer to connect from - the cell in the array where the node will be added.
 * @param to - the computer to connect to - a node is created from this computer and added to the end of the list in the
 *             relevant place.
 */
void Network::newConnection(Computer from, Computer to) {
    if (from > numOfComputers ) {
        cout << "no such computer " << from;
        exit(1);
    }
    if (to > numOfComputers) {
        cout << "no such computer " << to;
        exit(1);
    }
    if (from == to) {
        cout << "connection to the same computer";
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

/**
 * [] operator
 * @param index
 * @return the list in the index-th place.
 */
const List& Network::operator[](int index) const {
    return this->connections[index];
}

ostream &operator<<(ostream &os, const Network &network) {
    for (int i = 1; i <= network.numOfComputers; ++i) {
        os << i << ": " << network[i] << endl;
    }
    return os;
}
