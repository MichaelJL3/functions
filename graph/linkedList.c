#include "linkedList.h"

//DEBUG FUNCTION
#ifdef DEBUG

//prints the set of edge connections
void printEdgeList(edge* edgeList){
    edge* head=edgeList;

    if(edgeList)
    	printf("e: ");

    while(head){
        printf("%d(%0.4f) ", head->vertex, head->weight);
        head=head->next;
    }

    puts("");
}

#endif 

//delete the edgeSets stored in the dictionary
void delEdgeList(edge** edgeList){
    edge* temp=(*edgeList);

    while(temp){
        (*edgeList)=(*edgeList)->next;
        free(temp);
        temp=(*edgeList);
    }
}

//insert new node into the edge set
void insertEdgeList(edge** edgeList, int vertex, double weight){
    edge* oldList=(*edgeList);
    
    (*edgeList)=(edge*)malloc(sizeof(edge));
    (*edgeList)->vertex=vertex;
    (*edgeList)->weight=weight;
    (*edgeList)->next=oldList;
}
