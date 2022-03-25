# C-Iterator

This repository contains a program to simulate an iterator in C.

The elements to be travsersed are first stored in a binary search tree. In this program, the binary search tree stores integers, but the tree can be modified to store any data type by altering the definition of the structure "node_t" in tree.h.

There are 2 essential steps to build an iterator:
1. Check if there is another element to be traversed.
2. If yes, fetch the element.

The in-order traversal of a tree can be exploited to simulate an iterator. The iterator is initialised to the node containing the minimum value. The iterator then prints the value of the element if the node is not NULL, before moving on to the in-order successor. If the in-order successor is not NULL, then the value of the next node is fetched. Thus, the in-order successor plays a key role in checking if there is a subsequent element and fetching its value. 

To compile the code run "gcc tree.c client_tree.c". 
