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

	StackAccessibleGroup = makeAccessibleGroupStackVersion(theNetwork, computerID, colorArrayStack);
	RecAccessibleGroup = findAccessible(theNetwork, colorArrayRec, computerID);

}

StaticList makeAccessibleGroupStackVersion(Network& theNetwork, int computerID, ColorArray& Colors) {
	Stack S;
	Data CurrDetailsForRec;
	StaticList StackAccessibleGroup;
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
	return StackAccessibleGroup;
}

void findAccessible(Network& network, ColorArray& colorArray, int computerID) {
	colorArray.setBlack(computerID);
	Node* connectedComputerNode = network[computerID].getHead();

	while (connectedComputerNode) {
		int connectedComputerNodeID = connectedComputerNode->getComputer().getID();
		if (colorArray[connectedComputerNodeID] == WHITE) {
			findAccessible(network, colorArray, connectedComputerNodeID);
		}
		connectedComputerNode = connectedComputerNode->getNext();
	}
}

