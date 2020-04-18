/**
 * Data structures programming exercise 1
 * Nadav Suliman - 200041739
 * Dor Lasri - 313426975
 */

#include "MainHeader.h"

using namespace std;

int main() {

    int numOfComputers;
    int numOfConnections;
    int computerToFindAccessible;

    cin >> numOfComputers;
    cin >> numOfConnections;

    ColorArray colorArrayRec(numOfComputers);       //Creating a colorArray for each version of the findAccessible function
    ColorArray colorArrayStack(numOfComputers);

    Network theNetwork(numOfConnections, numOfComputers);   //Allocating a new array of lists with size of numOfComputers.
    initNetwork(theNetwork, numOfConnections);          //Initiating the network.

    cin >> computerToFindAccessible;                        //Testing if the computer is in the right range.
    if (computerToFindAccessible < 1 || computerToFindAccessible > numOfComputers) {
        cout << "no such computer " << computerToFindAccessible;
        exit(1);
    }

    StaticList StackAccessibleGroup;
    StaticList RecAccessibleGroup;


    accessibleGroup(theNetwork, computerToFindAccessible,StackAccessibleGroup, RecAccessibleGroup, colorArrayStack, colorArrayRec);
    StackAccessibleGroup.printList();       //printing results.
    RecAccessibleGroup.printList();
}

/**
 * Tests which we've fucked up on:
 *
 * 5 5 1 4 3 2 3 5 2 4 4 5 3
 * 7 8 1 4 1 5 2 3 4 6 4 7 6 4 6 3 7 5 1
 */