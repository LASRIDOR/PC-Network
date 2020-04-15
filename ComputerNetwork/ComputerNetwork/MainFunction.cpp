#include "MainHeader.h"

/**
 * Initializes a network from user inputs.
 * @param theNetwork - the network to initialize
 * @param numOfConnections - the number of connections there are in the network.
 */
void initNetwork(Network& theNetwork, int numOfConnections) {
    int computerFrom, computerTo;

    for (int i = 0; i < numOfConnections; ++i) {
        cin >> computerFrom;
        cin >> computerTo;

        Computer from(computerFrom);
        Computer to(computerTo);

        theNetwork.newConnection(from, to);
    }
}

/**
 * Calls makeAccessibleGroupStackVersion and findAccessible (recursive version) usese the following paramaters:
 * @param theNetwork - The network to find the accessible groups on.
 * @param computerID - The ID of the computer whose accessible group we want.
 * @param StackAccessibleGroup - The returned (by ref) static list for the iterative version.
 * @param RecAccessibleGroup - The returned (by ref) static list for the recursive version.
 * @param colorArrayStack - Color array for the recursive and stack version.
 * @param colorArrayRec
 */
void accessibleGroup(Network& theNetwork, int computerID, StaticList& StackAccessibleGroup,
                     StaticList& RecAccessibleGroup, ColorArray& colorArrayStack, ColorArray& colorArrayRec) {


    makeAccessibleGroupStackVersion(theNetwork, computerID, colorArrayStack, StackAccessibleGroup);
    findAccessible(theNetwork, colorArrayRec, computerID, RecAccessibleGroup);

}

/**
 * Finds the accessible group of computerID on the network theNetwork and adds it to the static list StackAccessibleGroup
 * @param theNetwork - The network where the computer is found
 * @param computerID - Computer whose accessible group we want
 * @param Colors - Color array to fill
 * @param StackAccessibleGroup - The static list to fill.
 */
void makeAccessibleGroupStackVersion(Network& theNetwork, int computerID, ColorArray& Colors, StaticList& StackAccessibleGroup) {
    Stack S;
    Data CurrDetailsForRec;

    int line = 0;

    CurrDetailsForRec.ComputerID = computerID;
    CurrDetailsForRec.line = START;
    S.Push(CurrDetailsForRec);
    while (!S.IsEmpty()) {
        CurrDetailsForRec = S.Pop();
        Colors.setBlack(CurrDetailsForRec.ComputerID);
        StackAccessibleGroup.InsertToTail(CurrDetailsForRec.ComputerID);
        Node* CurrNodeInListComputerPoint = theNetwork[CurrDetailsForRec.ComputerID].getHead();
        while (CurrNodeInListComputerPoint != nullptr) {
            if (Colors.isWhite(CurrNodeInListComputerPoint->getComputerID())) {
                CurrDetailsForRec.ComputerID = CurrNodeInListComputerPoint->getComputerID();
                CurrDetailsForRec.line = ++line;
                S.Push(CurrDetailsForRec);
            }
            CurrNodeInListComputerPoint = CurrNodeInListComputerPoint->getNext();
        }
    }
}

/**
 * Finds recursively the accessible group of computerID on network theNetwork using colorArray and inputting the group
 * members into the static list accessibleGroup.
 * @param network - The network where the computer is found
 * @param computerID - Computer whose accessible group we want
 * @param colorArray - Color array to fill
 * @param accessibleGroup - The static list to fill.
 */
void findAccessible(Network& network, ColorArray& colorArray, int computerID, StaticList& accessibleGroup) {
    colorArray.setBlack(computerID);
    accessibleGroup.InsertToTail(computerID);
    Node* connectedComputerNode = network[computerID].getHead();

    while (connectedComputerNode) {
        int connectedComputerNodeID = connectedComputerNode->getComputer().getID();
        if (colorArray[connectedComputerNodeID] == WHITE) {
            findAccessible(network, colorArray, connectedComputerNodeID, accessibleGroup);
        }
        connectedComputerNode = connectedComputerNode->getNext();
    }
}