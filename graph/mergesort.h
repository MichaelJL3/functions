/*
	mergesort.h

	Author: Michael Laucella
	language: c
	last modified: 10/24/2016

	sorts node list from max-min
	doesnt perform check to see if list is empty
*/

//include guards
#ifndef MERGE
#define MERGE

#include "linkedList.h"

//mergesort algorithm
void mergesort(edge **ar);

//merges the two sorted subsets together
edge* merge(edge* left, edge* right); 

#endif
