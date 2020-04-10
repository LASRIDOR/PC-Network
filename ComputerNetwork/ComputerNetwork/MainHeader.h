#include "StaticList.h"
#include "Stack.h"
#include "List.h"
#include "Computer.h"
#include "List.h"
#include "Network.h"
#include "ColorArray.h"
#include <iostream>

void initNetwork(Network &theNetwork, int numOfConnections);
void findAccessible(Network& network, ColorArray& colorArray, int computerID);