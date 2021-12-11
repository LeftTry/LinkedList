#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include "Node.h"
#include "iostream"

using namespace std;

template <typename T>
class LinkedList{
        Node<T>* head = nullptr;
        Node<T>* tail = nullptr;
public:
    LinkedList();

    bool isNull();

    void addNodeToBegin(T);
    void addNodeToEnd(T);
    void addNode(T, int);

    void deleteFirstNode();
    void deleteLastNode();
    void deleteNodeByIndex(int);
    void deleteNodeByValue(T);

    T findIndexByValue(T);

    T operator[](int);

    template<class Type> friend std::ostream & operator<<(std::ostream&, LinkedList<Type>&);

    Node<T>* get_head();
    Node<T>* get_tail();
    void set_head(Node<T>*);
    void set_tail(Node<T>*);
};

template<typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

template<typename T>
bool LinkedList<T>::isNull() {
    if(head == nullptr)
        return true;
    return false;
}

template<typename T>
void LinkedList<T>::addNodeToBegin(T a){
    Node<int>* node = new Node(a);
    node->set_next(head);
    head = node;
    //cout << head;
}

template<typename T>
void LinkedList<T>::addNodeToEnd(T a1) {
    Node<int>* node = new Node(a1);
    if(tail == nullptr) tail = head;
    node->set_next(nullptr);
    tail->set_next(node);
    tail = node;
}

template<typename T>
void LinkedList<T>::deleteFirstNode() {
    auto node = head->get_next();
    //delete head;
    head = node;
}

template<typename T>
void LinkedList<T>::addNode(T val, int index) {
    Node<T>* node = new Node(val);
    auto next_ = head;
    auto prev_ = head;
    for(int i = 0;i < index;i++){
        prev_ = next_;
        next_ = next_->get_next();
        if(next_ == nullptr){
            cout << "Index out of range" << endl;
            return;
        }
    }
    auto ptr1 = prev_->get_next();
    prev_->set_next(node);
    node->set_next(ptr1);
}

template<typename T>
void LinkedList<T>::deleteLastNode() {
    auto next_ = head;
    auto prev_ = head;
    while(next_->get_next() != nullptr){
        prev_ = next_;
        next_ = next_->get_next();
    }
    prev_->set_next(nullptr);
    //delete tail;
    tail = prev_;
}

template<typename T>
void LinkedList<T>::deleteNodeByIndex(int index) {
    auto next_ = head;
    auto prev_ = head;
    for(int i = 0;i < index;i++) {
        prev_ = next_;
        next_ = next_->get_next();
        if (next_ == nullptr) {
            cout << "Index out of range" << endl;
            return;
        }
    }
    //delete prev_->get_next();
    prev_->set_next(next_->get_next());
    //delete next_;
}

template<typename T>
void LinkedList<T>::deleteNodeByValue(T el) {
    auto next_ = head->get_next();
    auto prev_ = head;
    auto preprev_ = head;
    while(prev_->get_el() != el) {
        preprev_ = prev_;
        prev_ = next_;
        next_ = next_->get_next();
        if (next_ == nullptr) {
            cout << "Value out of range" << endl;
            return;
        }
    }
    //delete prev_->get_next();
    if(prev_ != head)
        preprev_->set_next(next_);
    else{
        head = next_;
    }
    //delete prev_;
}

template<typename T>
T LinkedList<T>::operator[](int index) {
    auto next_ = head;
    auto prev_ = head;
    for(int i = 0;i < index;i++) {
        prev_ = next_;
        next_ = next_->get_next();
        if (next_ == nullptr) {
            cout << "Index out of range" << endl;
            return -1;
        }
    }
    return prev_->get_el();
}

template<class Type>
std::ostream &operator<<(std::ostream & out, LinkedList<Type>& ll) {
    Node<Type> node = *ll.head;
    while(node.get_next() != nullptr){
        cout << node.get_el() << " ";
        node = *node.get_next();
    }
    cout << node.get_el() << " ";
    return out;
}

template<typename T>
T LinkedList<T>::findIndexByValue(T el) {
    auto next_ = head;
    auto prev_ = head;
    int q = 0;
    while(prev_->get_el() != el) {
        q++;
        prev_ = next_;
        next_ = next_->get_next();
        if (next_ == nullptr) {
            cout << "Value out of range" << endl;
            return -1;
        }
    }
    return q;
}

template<typename T>
Node<T> *LinkedList<T>::get_head() {
    return head;
}

template<typename T>
Node<T> *LinkedList<T>::get_tail() {
    return tail;
}

template<typename T>
void LinkedList<T>::set_head(Node<T> * node) {
    head = node;
}

template<typename T>
void LinkedList<T>::set_tail(Node<T> * node) {
    tail = node;
}

#endif //LINKEDLIST_LINKEDLIST_H
