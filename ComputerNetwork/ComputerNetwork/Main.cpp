#include "MainHeader.h"

using namespace std;

int main() {

    int numOfComputers;
    int numOfConnections;
    int computerToFindAccessible;

    cin >> numOfComputers;
    cin >> numOfConnections;

    ColorArray colorArray(numOfComputers);
    Network theNetwork(numOfConnections, numOfComputers);
    initNetwork(theNetwork, numOfConnections);

    cin >> computerToFindAccessible;
    if (computerToFindAccessible < 1 || computerToFindAccessible > numOfComputers) {
        cout << "Computer not found!";
        exit(1);
    }

    findAccessible(theNetwork, colorArray, computerToFindAccessible);

    colorArray.printAccessibles();
}

void initNetwork(Network &theNetwork, int numOfConnections) {
    int computerFrom, computerTo;

    for (int i = 0; i < numOfConnections; ++i) {
        cin >> computerFrom;
        cin >> computerTo;

        Computer from(computerFrom);
        Computer to(computerTo);

        theNetwork.newConnection(from, to);
    }
}

void findAccessible(Network& network, ColorArray& colorArray, int computerID) {
    colorArray.setBlack(computerID);
    Node *connectedComputerNode = network[computerID].getHead();

    while (connectedComputerNode) {
        int connectedComputerNodeID = connectedComputerNode->getComputer().getID();
        if (colorArray[connectedComputerNodeID] == WHITE) {
            findAccessible(network, colorArray, connectedComputerNodeID);
        }
        connectedComputerNode = connectedComputerNode->getNext();
    }
}