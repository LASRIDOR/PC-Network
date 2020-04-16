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
    Data nextDetailsForRec;
    int line = START;
    Node* CurrNodeInListComputerPoint;

    CurrDetailsForRec.ComputerID = computerID;
    CurrDetailsForRec.line = START;
    CurrNodeInListComputerPoint = theNetwork[CurrDetailsForRec.ComputerID].getHead();
    S.Push(CurrDetailsForRec);
    while (!S.IsEmpty()) {
        CurrDetailsForRec = S.Pop();
        if (CurrDetailsForRec.line == 0) {
            if (Colors.isWhite(CurrDetailsForRec.ComputerID)) {
                Colors.setBlack(CurrDetailsForRec.ComputerID);
                StackAccessibleGroup.InsertToTail(CurrDetailsForRec.ComputerID);
                CurrDetailsForRec.line = AFTER_START;
                CurrNodeInListComputerPoint = theNetwork[CurrDetailsForRec.ComputerID].getHead();
                if (CurrNodeInListComputerPoint) {
                    if (CurrNodeInListComputerPoint->getNext()) {
                        CurrDetailsForRec.NextNodeInListComputerPoint = CurrNodeInListComputerPoint->getNext();
                    }
                    else {
                        CurrDetailsForRec.NextNodeInListComputerPoint = nullptr;
                    }
                }
                else {
                    CurrDetailsForRec.NextNodeInListComputerPoint = nullptr;
                }
                S.Push(CurrDetailsForRec);

                if (CurrNodeInListComputerPoint) {
                    if (Colors.isWhite(CurrNodeInListComputerPoint->getComputerID())) {
                        nextDetailsForRec.ComputerID = CurrNodeInListComputerPoint->getComputerID();
                        nextDetailsForRec.line = START;
                        nextDetailsForRec.NextNodeInListComputerPoint = nullptr;
                        S.Push(nextDetailsForRec);
                    }
                }
            }
        }
        else if (CurrDetailsForRec.line == 1) {
            if (CurrDetailsForRec.NextNodeInListComputerPoint) {
                CurrDetailsForRec.line = AFTER_START;
                nextDetailsForRec.ComputerID = CurrDetailsForRec.NextNodeInListComputerPoint->getComputerID();
                CurrDetailsForRec.NextNodeInListComputerPoint = CurrDetailsForRec.NextNodeInListComputerPoint->getNext();
                S.Push(CurrDetailsForRec);
                nextDetailsForRec.line = START;
                nextDetailsForRec.NextNodeInListComputerPoint = nullptr;
                S.Push(nextDetailsForRec);
            }
            else {
                CurrDetailsForRec.line = AFTER_SECOND;
                S.Push(CurrDetailsForRec);
            }
        }
        else {
            //do nothing
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


/*
void makeAccessibleGroupStackVersion(Network& theNetwork, int computerID, ColorArray& Colors, StaticList& StackAccessibleGroup) {
    Stack S; // Stack which simulates the recursion. Item Curr; // Values of current “recursive call” Item Next; // Values of next “recursive call”.
    Data CurrDetailsForRec;
    Data nextDetailsForRec;
    int line = START;

    CurrDetailsForRec.ComputerID = computerID;
    CurrDetailsForRec.line = START;
    S.Push(CurrDetailsForRec);
    //Colors.setBlack(CurrDetailsForRec.ComputerID);
    //StackAccessibleGroup.InsertToTail(CurrDetailsForRec.ComputerID);
    while (!S.IsEmpty()) {
        CurrDetailsForRec = S.Pop();
        Node* CurrNodeInListComputerPoint = theNetwork[CurrDetailsForRec.ComputerID].getHead();
        if (CurrDetailsForRec.line == 0) {
            if (Colors.isWhite(CurrDetailsForRec.ComputerID)) {
               // Colors.setBlack(CurrDetailsForRec.ComputerID);
               // StackAccessibleGroup.InsertToTail(CurrDetailsForRec.ComputerID);
                CurrDetailsForRec.line = ++line;
                S.Push(CurrDetailsForRec);
                while (CurrNodeInListComputerPoint != nullptr) {
                    nextDetailsForRec.ComputerID = CurrNodeInListComputerPoint->getComputerID();
                    nextDetailsForRec.line = START;
                    S.Push(nextDetailsForRec);
                    CurrNodeInListComputerPoint = CurrNodeInListComputerPoint->getNext();
                }
                //Colors.setBlack(CurrDetailsForRec.ComputerID);
                //StackAccessibleGroup.InsertToTail(CurrDetailsForRec.ComputerID);
            }
        }
        else if (CurrDetailsForRec.line != 0) {
            if (Colors.isWhite(CurrDetailsForRec.ComputerID)) {
                Colors.setBlack(CurrDetailsForRec.ComputerID);
                StackAccessibleGroup.InsertToTail(CurrDetailsForRec.ComputerID);
            }
        }
    }
}
*/

/*
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
                S.Push(CurrDetailsForRec);
                CurrDetailsForRec.ComputerID = CurrNodeInListComputerPoint->getComputerID();
                CurrDetailsForRec.line = ++line;
                S.Push(CurrDetailsForRec);
            }
            CurrNodeInListComputerPoint = CurrNodeInListComputerPoint->getNext();
        }
    }
}
*/