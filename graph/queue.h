/*
	queue.h

	Author: Michael Laucella
	language: c
	last modified: 10/24/2016

	creates a basic queue without any safety checks
*/

//include guards
#ifndef QUEUE
#define QUEUE

//needed for malloc operations
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

//queue struct
struct queue{
	int front;	//points to front of queue
	int rear;	//points to end of queue
	int *arr;	//holds all the values in the queue
}typedef queue;

//intialize and destroy queue
void setupQueue(queue *q, int n);
void delQueue(queue *q);

//add and remove data from the queue
void enqueue(queue *q, int n);
void dequeue(queue *q);

//return front element of queue
int front(queue q);

//check if queue is empty
short isEmpty(queue q);

#endif