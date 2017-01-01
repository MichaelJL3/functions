/*
	modBfs.h

	Author: Michael Laucella
	language: c
	last modified: 10/24/2016

	performs a modified breadth first search
	only checks the nodes 2 levels away from the source
	and returns a linked list of the strongest connections
	to simulate the strong triadic closure property
*/

//include guards
#ifndef BFS
#define BFS

#include "queue.h"
#include "linkedList.h"
#include "hashMap.h"

#define NOT_VISITED -1

//perform a modified bfs on the graph 
edge* bfs(int source, map hashMap);

#endif
