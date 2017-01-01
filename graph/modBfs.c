#include "modBfs.h"

//perform a modified bfs to simulate strong triadic closure
edge* bfs(int source, map hashMap){
	int size=hashMap.mapSize;
	int parent=0;
	int child=0;
	int index=0;
	int friends[size];
	queue q;
	dict* tempDict;
	edge* cached[size];
	edge* ranks=NULL;
	edge* head;
	double relation=0;
	double strength=0;

	//set all vertexs to not visited
	for(int i=0; i<size; i++){
		friends[i]=NOT_VISITED;
		cached[i]=NULL;
	}

	setupQueue(&q, size);

	//get the edgeset for the source node
	tempDict=lookup(hashMap, source, hash(source));
	if(!tempDict)
		return ranks;

	friends[tempDict->index]=0;
	head=tempDict->edges;

	while(head){
		child=head->vertex;

		index=lookup(hashMap, child, hash(child))->index;

		//if the vertex wasnt already visited add it to the queue
		if(friends[index]==NOT_VISITED){
			friends[index]=head->weight;
			enqueue(&q, child);
		}

		head=head->next;
	}

	//while the queue is not empty
	while(!isEmpty(q)){
		parent=front(q);
		dequeue(&q);

		//get the new edge set
		tempDict=lookup(hashMap, parent, hash(parent));
		index=tempDict->index;
		head=tempDict->edges;
		relation=friends[index];

		//go through the edge set and process any unique vertices
		while(head){
			child=head->vertex;		
			index=lookup(hashMap, child, hash(child))->index;	

			if(friends[index]==NOT_VISITED){
				strength=head->weight*relation;
				//update the list depending on if it is cached the list already
				
				if(!cached[index]){
					insertEdgeList(&ranks, child, strength);
					cached[index]=ranks;
				}
				else if(strength>cached[index]->weight)
					cached[index]->weight=strength;
			}

			head=head->next;
		}
	}

	//delete the queue
	delQueue(&q);

	return ranks;
}
