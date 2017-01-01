
#include "hashmap.h"

template<typename T>
Hashmap<T>::Hashmap(){
    elements=0;
}

template<typename T>
Hashmap<T>::~Hashmap(){
    deleteMap();
}

template<typename T>
void Hashmap<T>::deleteMap(){
    for(int i=0; i<MAP_SIZE; i++){
        map[i].deleteList();
    }
}

template<typename T>
void Hashmap<T>::printMap(){
    for(int i=0; i<MAP_SIZE; i++){
        map[i].printList();
    }
    printf("Size of map: %d\n", elements);
}

template<typename T>
void Hashmap<T>::printList(int indx){
    map[indx].printList();
}

template<typename T>
int Hashmap<T>::hash(int n){
    return n%MAP_SIZE;
}

template<typename T>
int Hashmap<T>::get(int key){
    Node<T>* mapNode=map[hash(key)].find(key);
    if(mapNode)
        return mapNode->val;
    
    return NOT_FOUND;
}

template<typename T>
void Hashmap<T>::del(int key){
    if(map[hash(key)].deleteNode(key))
        elements--;
}

template<typename T>
void Hashmap<T>::set(int key, T val){
    map[hash(key)].addNodeHead(key, val);
    elements++;
}

template<typename T>
Hashlist<T>::Hashlist(){
    head=NULL;
    size=0;
}

template<typename T>
bool Hashlist<T>::empty(){
    return (size?false:true);
}

template<typename T>
void Hashlist<T>::printList(){
    Node<T>* temp=head;
    while(temp){
        printf("%d ", temp->val);
        temp=temp->next;
    }
    printf("\nList Size: %d\n", size);
}

template<typename T>
void Hashlist<T>::deleteList(){
    Node<T>* temp;
    while(head){
        temp=head;
        head=head->next;
        free(temp);
    }
    head=NULL;
    size=0;
}

template<typename T>
bool Hashlist<T>::deleteNode(int key){
    Node<T>* prev=head;
    Node<T>* erase;

    if(!empty()){
        if(head->key==key){
            head=head->next;
            free(prev);
            size--;
            return true;
        }
        while(prev->next){
            if(prev->next->key==key){
                erase=prev->next;
                prev->next=erase->next;
                free(erase);
                size--;
                return true;
            }
            prev=prev->next;
        }
        if(prev->key==key){
            free(prev);
            prev=NULL;
            size--;
            return true;
        }

        return false;
    }

    return false;
}

template<typename T>
void Hashlist<T>::addNodeHead(int key, T val){
    Node<T>* newnode=(Node<T>*)malloc(sizeof(Node<T>));
    newnode->val=val;
    newnode->key=key;
    newnode->next=head;
    head=newnode;

    size++;
}

template<typename T>
Node<T>* Hashlist<T>::find(int key){
    Node<T>* found=head;
    
    while(found){
         if(found->key)
             return found;
        found=found->next;
    }

    return NULL;
}

