#include "linkedlist.h"

List::List(){
    head=NULL;
    tail=NULL;
    size=0;
}

List::List(int val){
    head=NULL;
    size=0;
    addNodeHead(val);
}

List::List(int* vals, int arrSize){
    head=NULL;
    size=0;

    for(int i=0; i<arrSize; i++){
       addNodeHead(vals[i]);
    }
}

List::~List(){
    deleteList();
}

bool List::empty(){
    return (size?false:true);
}

void List::mergeLists(const List &a){
    if(!empty())
        tail->next=a.head;
    else{
        tail=a.tail;
        head=a.head;
    }
    size+=a.size;
}

void List::cloneList(List &a){
    a.tail=tail;
    a.head=head;
    a.size=size;
}

void List::deleteNodesFrom(int start, int n){
    Node* prev=head;
    Node* erase;
    int diff=start+n;

    if(empty()||diff>=size||start<0)
        return;

    diff=n;
    if(!diff)
        deleteNodeAt(start);

    if(start)
        prev=at(start-1);
    else 
        diff--;

    for(int i=0; i<diff; i++){
        erase=prev->next;
        prev->next=erase->next;
        free(erase);
    }

    if(!start){
        erase=head;
        head=head->next;
        free(erase);
    }

    size-=n;
}

void List::deleteNodeAt(int pos){
    Node* prev=head;
    Node* erase;

    if(empty()||pos>=size)
        return;

    if(!pos){
        head=head->next;
        free(prev);
        size--;
        return;
    }

    for(int i=0; i<pos-1; i++){
        prev=prev->next;
    }

    erase=prev->next;
    prev->next=erase->next;
    free(erase);
}

void List::deleteNodes(int val){
    Node* prev=head;
    Node* erase;

    if(!empty()){
        if(head->val==val){
            head=head->next;
            free(prev);
            prev=head;
            size--;
        }
        while(prev->next){
            if(prev->next->val==val){
                erase=prev->next;
                prev->next=erase->next;
                free(erase);
                size--;
            }
            prev=prev->next;
        }
        if(tail->val==val){
            free(tail);
            tail=prev;
            tail->next=NULL;
            size--;
        }
    }
}

void List::deleteNode(int val){
    Node* prev=head;
    Node* erase;

    if(!empty()){
        if(head->val==val){
            head=head->next;
            free(prev);
            size--;
            return;
        }
        while(prev->next){
            if(prev->next->val==val){
                erase=prev->next;
                prev->next=erase->next;
                free(erase);
                size--;
                return;
            }
            prev=prev->next;
        }
        if(tail->val==val){
            free(tail);
            tail=prev;
            tail->next=NULL;
            size--;
            return;
        }
    }
}

void List::addNodeHead(int val){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->val=val;
    newnode->next=head;
    head=newnode;

    if(empty())
        tail=head;

    size++;
}

void List::addNodeTail(int val){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->val=val;
    newnode->next=NULL;

    if(empty()){
        head=tail;
        tail=newnode;
    }
    else{
        tail->next=newnode;
        tail=tail->next;
    }

    size++;
}

void List::printList(){
    Node* temp=head;
    while(temp){
        printf("%d ", temp->val);
        temp=temp->next;
    }
    printf("\nlist size: %d\n", size);
}

void List::deleteList(){
    Node* temp;
    while(head){
        temp=head;
        head=head->next;
        if(head)
            printf("%p\n", head);
        free(temp);
    }
    head=NULL;
    tail=NULL;
    size=0;
}

Node* List::find(int val){
    Node* found=head;

    if(tail->val==val)
        return tail;

    while(found!=tail){
        if(found->val)
            return found;
        found=found->next;
    }

    return NULL;
}

Node* List::at(int pos){
    Node* found=head;

    if(pos==size-1)
        return tail;
    else if(pos>=size)
        return NULL;

    for(int i=0; i<pos; i++){
        found=found->next;
    }

    return found;
}
