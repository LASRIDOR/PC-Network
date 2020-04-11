#include "StaticList.h"
#include "Stack.h"
#include "List.h"
#include "Computer.h"
#include "List.h"
#include "Network.h"
#include "ColorArray.h"
#include "ItemTypeNode.h"
#include <iostream>

#define START 0;

void initNetwork(Network &theNetwork, int numOfConnections);
void findAccessible(Network& network, ColorArray& colorArray, int computerID);
void accessibleGroup(Network& network, int numOfComputers, int computerID);
void makeAccessibleGroupStackVersion(Network& network, int computerID, ColorArray* Colors, StaticList* StackAccessibleGroup);