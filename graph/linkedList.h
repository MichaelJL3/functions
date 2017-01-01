/*
	linkedList.h

	Author: Michael Laucella
	language: c
	last modified: 10/24/2016

	Creates a basic linked list structure which contains 
	an index and a value
*/

//include guards
#ifndef LIST
#define LIST

#include <stdlib.h>

#ifdef DEBUG
#include <stdio.h>
#endif

//set of edges for a single node
struct edge{
    int vertex;
    double weight;
    struct edge* next;
}typedef edge;

//delete the list
void delEdgeList(edge** edgeList);

//insert at the head of the list
void insertEdgeList(edge** edgeList, int vertex, double weight);

//DEBUG FUNCTION
#ifdef DEBUG
void printEdgeList(edge* edgeList);
#endif

#endif
