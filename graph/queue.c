#include "queue.h"

//allocate memory for queue/initialize default values
void setupQueue(queue *q, int n){
	q->front=0;
	q->rear=-1;
	q->arr=(int*)malloc(sizeof(int)*n);
}

//free allocated memory
void delQueue(queue *q){
	free(q->arr);
}

//push new element to the queue
void enqueue(queue *q, int n){
	q->arr[++q->rear]=n;
}

//remove element from the queue
void dequeue(queue *q){
	q->front++;
}

//get the element in front of the queue
int front(queue q){
	return q.arr[q.front];
}

//check if queue is empty
short isEmpty(queue q){
	if(q.front-(q.rear+1))
		return FALSE;
	return TRUE;
} 
