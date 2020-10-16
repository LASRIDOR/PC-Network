# PC Network

# Goal
A program in C ++ that contains two key functions that implement the FindAccessible algorithm described below. One function will implement the algorithm as described (recursively) and the other will implement it without using recursion.

# Problem Description
A computer network is given, with different computers connected in one-way communication lines between them. Not all computers are connected to everyone.

A computer that has a message in its hands - can transmit it to the computers to which it is connected, and they can transmit it in the same way.
For a given computer on the network, we would like to find the group of computers that can receive the message from it.
We will use the following settings:

Focus - A computer that receives an external message and can transmit it to anyone who accesses it
Hotline Accessibility Group - The group of computers that can receive the message from the hotline.

For example, in the drawing - if computer 1 has a message it can pass it to 4 and 4 will also pass it to 5.
That is, for a computer 1 that is a focal point - its accessibility group is {1,4,5}
Another example - for HaMoked 3 its accessibility group is {3,2,4,5}

You need to write a plan that will get the computers on the network and the connections between them, then you will get a call center, and you will find its accessible group.

# Detailed description of the program

1. Input: The program will receive as input the number of computers,, n For simplicity let's say they are numbered from 1 to n. The program will then pick up the number of pairs that make up connections, and then the pairs themselves.
For example, for the above drawing the following input will be obtained:
5 5
1 4 3 2 3 5 2 4 4 5
This means that the network has 5 computers with the following 5 connections:
1-> 4 3-> 2 3-> 5 2-> 4 4-> 5
Finally, the focus number will be absorbed, which is any number between 1 and n.
2. Output: The program will print the center's accessibility list as obtained from the recursive function and as obtained from the function using the stack.

3. The structure of the network: The network will be stored in an array of linked lists as follows: The array will be of size n and each cell i in the array will contain a linked list of the computers to which computer i is connected. This is called "Network structure."

4. Accessibility list: The accessibility list will be stored in a static array of size n as taught in class "(Implementation of chained lists without voters.)"

5. Algorithm for creating the call center's accessibility group:

• We will create a group accessible to the center and initial it as an empty list.
• We will create a color scheme for all computers - each computer can be white or black.
• We will initialize all the computers in the network structure as "bricks."
• We will enable the FindAccessible recursive function which is described below.
• At the end we will return the list of accessible.

Function Description: FindAccessible

Purpose: The function receives a x-axis computer (in the first reading x is the call center itself and adds x and the group of accessible ones from it to the center's accessible list.

Parameters: the network, the computer on duty, the color scheme and the list of accessibility.

# algorithm: 

• We will make x black and add it to the list of accessible.
• We will loop through all the computers to which x is connected in order and for each of them, y, if it is white, is called recursively to the FindAccessible function when this time y is the on-duty computer.
