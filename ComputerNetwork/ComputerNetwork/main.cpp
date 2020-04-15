/**
 * Data structures programming exercise 1
 * Nadav Suliman - 200041739
 * Dor Lasri -
 */

#include "MainHeader.h"

using namespace std;

int main() {

    int numOfComputers;
    int numOfConnections;
    int computerToFindAccessible;

    cin >> numOfComputers;
    cin >> numOfConnections;

    ColorArray colorArrayRec(numOfComputers);
    ColorArray colorArrayStack(numOfComputers);

    Network theNetwork(numOfConnections, numOfComputers);
    initNetwork(theNetwork, numOfConnections);

    cin >> computerToFindAccessible;
    if (computerToFindAccessible < 1 || computerToFindAccessible > numOfComputers) {
        cout << "no such computer " << computerToFindAccessible;
        exit(1);
    }

    StaticList StackAccessibleGroup;
    StaticList RecAccessibleGroup;

    accessibleGroup(theNetwork, numOfComputers, computerToFindAccessible,StackAccessibleGroup, RecAccessibleGroup, colorArrayStack, colorArrayRec);
    StackAccessibleGroup.printList();
    RecAccessibleGroup.printList();
}