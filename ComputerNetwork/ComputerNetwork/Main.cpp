#include "MainHeader.h"
#include "List.h"
#include "Network.h"
#include <iostream>

void initNetwork(int numOfConnections, Network &theNetwork);

using namespace std;

int main() {

    int numOfComputers;
    int numOfConnections;

    cin >> numOfComputers;
    cin >> numOfConnections;

    Network theNetwork(numOfConnections, numOfComputers);
    initNetwork(numOfConnections, theNetwork);
    cout << theNetwork;
}

void initNetwork(int numOfConnections, Network &theNetwork) {
    int computerFrom, computerTo;

    for (int i = 0; i < numOfConnections; ++i) {
        cin >> computerFrom;
        cin >> computerTo;

        Computer from(computerFrom);
        Computer to(computerTo);

        theNetwork.newConnection(from, to);
    }
}
