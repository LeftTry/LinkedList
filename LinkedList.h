#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include "Node.h"

template <typename T>
class LinkedList{
    Node<T>* head;
    Node<T>* tail;
public:
    LinkedList();


};

template<typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

#endif //LINKEDLIST_LINKEDLIST_H
