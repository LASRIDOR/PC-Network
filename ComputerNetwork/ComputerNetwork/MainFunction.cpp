#include "MainHeader.h"

void accessibleGroup(Network& network,int numOfComputers,int computerID) {
	StaticList* StackAccessibleGroup = new StaticList;
	StaticList* RecAccessibleGroup = new StaticList;
	ColorArray* colorArrayStack = new ColorArray(numOfComputers);

	makeAccessibleGroupStackVersion(network, computerID, colorArrayStack, StackAccessibleGroup);
	colorArrayStack->printAccessibles();
}

void makeAccessibleGroupStackVersion(Network& network, int computerID, ColorArray* Colors, StaticList* StackAccessibleGroup) {
	Stack S;
	Data CurrDetailsForRec;
	int line = 0;

	CurrDetailsForRec.ComputerID = computerID;
	CurrDetailsForRec.line = START;
	S.Push(CurrDetailsForRec);

	while (!S.IsEmpty()) {
		CurrDetailsForRec = S.Pop();
		Colors->setBlack(CurrDetailsForRec.ComputerID);
		StackAccessibleGroup->InsertToTail(CurrDetailsForRec.ComputerID);
		Node* CurrNodeInListComputerPoint = network[CurrDetailsForRec.ComputerID].getHead();
		while (CurrNodeInListComputerPoint != nullptr) {
			CurrDetailsForRec.ComputerID = CurrNodeInListComputerPoint->getComputer().getID();
			CurrDetailsForRec.line = ++line;

			S.Push(CurrDetailsForRec);

			CurrNodeInListComputerPoint = CurrNodeInListComputerPoint->getNext();
		}
	}

}

//--------------------------------------------------------------------------------------------
//                      Nadav Func
//--------------------------------------------------------------------------------------------

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