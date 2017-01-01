#include <stdio.h>
#include <stdlib.h>
#include "hashMap.h"
#include "modBfs.h"
#include "linkedList.h"
#include "mergesort.h"

//get recommendation list
int main(){
    map hashMap;
    dict* dictSearch;
    double strength=0;
    int source=0;
    int index=0;
    int from=0;
    int to=0;

    //setup an empty map
    clearMap(&hashMap);

    //source node for recommendations
    scanf("%d", &source);

    //stdin the graph
    while(scanf("%d", &from)!=EOF){
        scanf("%d", &to);
        scanf("%lf", &strength);
        
        index=hash(from);
        dictSearch=lookup(hashMap, from, index);
        if(!dictSearch)
            dictSearch=insert(&hashMap, from, index);

        //insert edge
        insertEdgeList(&dictSearch->edges, hash(to), strength); 

        index=hash(to);
        dictSearch=lookup(hashMap, to, index);
        if(!dictSearch)
            dictSearch=insert(&hashMap, to, index);
    }

    //get the rankings from the graph
    edge* ranks = bfs(source, hashMap);
        if(!ranks){
	   puts("No rankings available");
	   exit(0);
    }

    //debug print out the unsorted rankings
    #ifdef DEBUG
    puts("====UNSORTED====");
    printEdgeList(ranks);
    #endif

    mergesort(&ranks);

    //debug print the hashmap
    #ifdef DEBUG
    puts("=====SORTED=====");
    printEdgeList(ranks);
    puts("======MAP======");
    printMap(hashMap);
    #endif

    //deallocation
    delEdgeList(&ranks);
    delMap(&hashMap);
}
