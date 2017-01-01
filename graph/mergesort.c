#include "mergesort.h"

//performs mergesort 
void mergesort(edge **ar){
	if(!(*ar)->next)
		return;

	//two initial edges which will be dropped at the end
	edge tmpLeft, tmpRight;
	edge* tmp=(*ar);
	edge* left=&tmpLeft;
	edge* right=&tmpRight;
	edge* leftHead=left;
	edge* rightHead=right;
	int count=0;

	//go through the list and split it in half
	while(tmp){
		if(count%2){
			right->next=tmp;
			right=right->next;
		}
		else{
			left->next=tmp;
			left=left->next;
		}
	
		count++;
		tmp=tmp->next;
	}

	left->next=NULL;
	right->next=NULL;
	leftHead=leftHead->next;
	rightHead=rightHead->next;

	//recurse on the two sub lists
	mergesort(&leftHead);
	mergesort(&rightHead);

	//merge the lists
	(*ar)=merge(leftHead, rightHead);
}

//merges the linked lists into one sorted list
edge* merge(edge* left, edge* right){
	//set an initial useless edge which will be dropped at the end
	edge tmp;
	edge* sorted=&tmp;
	edge* sortHead=sorted;

	//go through the left and right sub lists and sort them into one
	while(left&&right){
		if(left->weight>=right->weight){
			sorted->next=left;
			sorted=sorted->next;
			left=left->next;
		}
		else{
			sorted->next=right;
			sorted=sorted->next;
			right=right->next;
		}
	}

	sorted->next=NULL;

	//attach the remainder of any non empty the list
	if(left)
		sorted->next=left;
	else if(right)
		sorted->next=right;

	return sortHead->next;
}
