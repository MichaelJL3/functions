/*
	hashMap.h

	Author: Michael Laucella
	language: c
	last modified: 10/24/2016

	creates a hash map which stores graph entities
*/

#ifndef HASHMAP
#define HASHMAP

#include <stdlib.h>
#include "linkedList.h"

#ifdef DEBUG
#include <stdio.h>
#endif

#define DICTSIZE 2500

//set of items stored in the dictionary
struct dict{
    int id;
    int index;
    struct dict* next;
    struct edge* edges; 
}typedef dict;

//container for hashmap 
struct map{
    int mapSize;
    dict* hashDict[DICTSIZE];
}typedef map;

//key to point in the map
int hash(int vertex);

//setup an empty map
void clearMap();

//search for element in the map
dict* lookup(map hashMap, int vertex, int index);

//insert elements into the dictionary
dict* insert(map* hashMap, int vertex, int index);
void insertDictList(dict** dictList, int vertex, int counter);

//deleting the items in the map
void delMap(map* hashMap);
void delDictList(dict** dictList);

#ifdef DEBUG
//display map items
void printMap(map hashMap);
void printDictList(dict* dictList);
#endif

#endif
