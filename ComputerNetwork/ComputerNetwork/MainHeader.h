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
#define AFTER_START 1;
#define AFTER_SECOND 2;

void initNetwork(Network &theNetwork, int numOfConnections);
void accessibleGroup(Network& theNetwork, int computerID, StaticList& StackAccessibleGroup,
                     StaticList& RecAccessibleGroup, ColorArray& colorArrayStack, ColorArray& colorArrayRec);
void findAccessible(Network& network, ColorArray& colorArray, int computerID, StaticList& RecAccessibleGroup);
void makeAccessibleGroupStackVersion(Network& theNetwork, int computerID, ColorArray& Colors, StaticList& StackAccessibleGroup);