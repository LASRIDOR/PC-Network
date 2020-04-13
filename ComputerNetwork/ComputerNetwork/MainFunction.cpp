#include "MainHeader.h"

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

void accessibleGroup(Network& theNetwork,int numOfComputers,int computerID, StaticList& StackAccessibleGroup,
	StaticList& RecAccessibleGroup, ColorArray& colorArrayStack, ColorArray& colorArrayRec) {


	makeAccessibleGroupStackVersion(theNetwork, computerID, colorArrayStack, StackAccessibleGroup);
	findAccessible(theNetwork, colorArrayRec, computerID, RecAccessibleGroup);

}

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
			CurrDetailsForRec.ComputerID = CurrNodeInListComputerPoint->getComputerID();
			CurrDetailsForRec.line = ++line;
			S.Push(CurrDetailsForRec);
			CurrNodeInListComputerPoint = CurrNodeInListComputerPoint->getNext();
		}
	}
}

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