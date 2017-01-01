#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstdio>
#include <cstdlib>

//template <class T>

#ifndef NODE
struct Node{
    int val;
    Node* next;
};
#endif

class List{
protected:
    Node* head;
    Node* tail;
    int size;
public:
    List();
    List(int val);
    List(int* vals, int arrSize);
    ~List();
    bool empty();
    void printList();
    void deleteList();
    void addNodeTail(int val);
    void addNodeHead(int val);
    void deleteNode(int val);
    void deleteNodes(int val);
    void deleteNodeAt(int pos);
    void deleteNodesFrom(int start, int end);
    void mergeLists(const List &a);
    void cloneList(List &a);
    Node* find(int val);
    Node* at(int pos);
};

#endif
