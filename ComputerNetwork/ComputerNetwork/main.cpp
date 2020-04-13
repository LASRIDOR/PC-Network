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
        cout << "Computer not found!";
        exit(1);
    }

    StaticList StackAccessibleGroup;
    StaticList RecAccessibleGroup;

    accessibleGroup(theNetwork, numOfComputers, computerToFindAccessible,StackAccessibleGroup, RecAccessibleGroup, colorArrayStack, colorArrayRec);
    colorArrayRec.printAccessibles();
    colorArrayStack.printAccessibles();
}