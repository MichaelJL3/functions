#include "hashMap.h"

#ifdef DEBUG

//DEBUG OPTIONS

//Print the elements in the map
void printMap(map hashMap){
    dict** hashDict=hashMap.hashDict;

    for(int i=0; i<DICTSIZE; i++)
        printDictList(hashDict[i]);       
}

//prints the dictionaries name:index as well as associated edgeSet
void printDictList(dict* dictList){
    dict* head=dictList;

    while(head){
        printf("[%d] ", head->id);
	printEdgeList(head->edges);
        head=head->next;
    }
}

#endif

//HASH ALGORITHM

//place into the size of the map (simple hash)
int hash(int vertex){
    return vertex%DICTSIZE;
}

//SEARCH THE DICTIONARY

//lookup element in the array check list of list in case of collisions
dict* lookup(map hashMap, int vertex, int index){
    dict* search=hashMap.hashDict[index];
    
    while(search){
        if(search->id==vertex)
            break;
        search=search->next;    
    }

    return search;
}

//SETUP AN EMPTY INSTANCE OF A DICTIONARY

//Set all pointers in the map to NULL
//Set the number of elements in the map to 0
void clearMap(map* hashMap){
    hashMap->mapSize=0;
    dict** hashDict=hashMap->hashDict;

    for(int i=0; i<DICTSIZE; i++)
        hashDict[i]=NULL;
}

//INSERT ELEMENTS INTO THE DICTIONARY

//insert element into the dictionary
dict* insert(map* hashMap, int vertex, int index){
    dict** tempDict=&hashMap->hashDict[index];

    if(!*tempDict||vertex!=(*tempDict)->id)
        insertDictList(tempDict, vertex, hashMap->mapSize);

    hashMap->mapSize++;
    return (*tempDict);
}

//insert element into the dictionary
void insertDictList(dict** dictList, int vertex, int counter){
    dict* oldList=(*dictList);
    
    (*dictList)=(dict*)malloc(sizeof(dict));
    (*dictList)->id=vertex;
    (*dictList)->index=counter;
    (*dictList)->next=oldList;
    (*dictList)->edges=NULL;
}

//DELETE THE MAP

//delete all allocated data in the list
void delMap(map *hashMap){
    hashMap->mapSize=0;
    dict** hashDict=hashMap->hashDict;

    for(int i=0; i<DICTSIZE; i++)
        delDictList(&hashDict[i]);
}

//delete the allocated space for dictionary entries
void delDictList(dict** dictList){
    dict* temp=(*dictList);

    while(temp){
	delEdgeList(&(*dictList)->edges);
        (*dictList)=(*dictList)->next;
        free(temp);
        temp=(*dictList);
    }
}
