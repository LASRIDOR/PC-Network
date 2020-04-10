#include "MainHeader.h"
#include "List.h"
#include <iostream>
using namespace std;

int main() {
    int numOfComputers;
    int numOfConnections;

    int computerFrom, computerTo;

    cin >> numOfComputers;
    cin >> numOfConnections;

    numOfComputers++;                                   //Adjusting for offset by 1.
    List* network = new List[numOfComputers];

    for (int i = 1; i < numOfConnections; ++i) {
        cin >> computerFrom;
        cin >> computerTo;

        if (computerFrom > numOfComputers || computerTo > numOfComputers || computerFrom == computerTo) {
            cout << "Invalid input!";
            exit(1);
        }
        network[computerFrom].addToTail(computerTo);
    }

    for (int i = 1; i < numOfComputers; ++i) {
        cout << i << ":";
        network[i].printList();
        cout << "\n";
    }
}
