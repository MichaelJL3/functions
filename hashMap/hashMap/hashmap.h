
#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <cstdio>
#include <cstdlib>
#include <string>

#define MAP_SIZE 20000
#define NOT_FOUND -1

template<typename T>
struct Node{
    T val;
    T key;
    Node<T>* next;
};

template<typename T>
class Hashlist{
private:
    Node<T>* head;
    int size=0;
public:
    Hashlist();
    void printList();
    void deleteList();
    void addNodeHead(int key, T val);
    bool deleteNodeByVal(T val);
    bool deleteNode(int key);
    bool empty();
    Node<T>* find(int key);
};

template<typename T>
class Hashmap{
private:
    int elements;
    Hashlist<T> map[MAP_SIZE];
public:
    Hashmap();
    ~Hashmap();
    unsigned int hash(T n);
    unsigned int hash(T &n);
    int get(int key);
    void del(int key);
    void set(int key, T val);
    void printMap();
    void printList(int indx);
    void deleteMap();
};

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
unsigned int Hashmap<T>::hash(T n){
    return n%MAP_SIZE;
}

template<typename T>
unsigned int Hashmap<T>::hash(T &n){
    return (int)n%MAP_SIZE;
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
bool Hashlist<T>::deleteNodeByVal(T val){
    Node<T>* prev=head;
    Node<T>* erase;

    if(!empty()){
        if(head->val==val){
            head=head->next;
            free(prev);
            size--;
            return true;
        }
        while(prev->next){
            if(prev->next->val==val){
                erase=prev->next;
                prev->next=erase->next;
                free(erase);
                size--;
                return true;
            }
            prev=prev->next;
        }
        if(prev->val==val){
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
         if(found->key==key)
             return found;
        found=found->next;
    }

    return NULL;
}

#endif
