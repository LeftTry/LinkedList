#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include "Node.h"
#include "iostream"

using namespace std;

template <typename T>
class LinkedList{
    Node<T>* head;
    Node<T>* tail;
public:
    LinkedList();
    LinkedList(int);

    bool isNull();

    void addNodeToBegin(Node<T>&);
    void addNodeToEnd(Node<T>&);
    void addNode(Node<T>&, int);

    void deleteFirstNode();
    void deleteLastNode();
    void deleteNodeByIndex(int);
    void deleteNodeByValue(T);

    T findIndexByValue(T);

    T operator[](int);

    template<class Type> friend std::ostream & operator<<(std::ostream&, LinkedList<Type>);
};

template<typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

template<typename T>
LinkedList<T>::LinkedList(int size){
    T a;
    cin >> a;
    Node<T> node(a);
    addNodeToBegin(node);
    tail = &node;
    for(int i = 0;i < size - 1;i++){
        T a1;
        cin >> a1;
        Node<T> *node1 = new Node<T>(a1);
        //cout << node1 << endl;
        addNodeToEnd(*node1);
        //cout << "None";
    }
}

template<typename T>
bool LinkedList<T>::isNull() {
    if(head == nullptr)
        return true;
    return false;
}

template<typename T>
void LinkedList<T>::addNodeToBegin(Node<T> & node){
    node.set_next(head);
    head = &node;
    //cout << head;
}

template<typename T>
void LinkedList<T>::addNodeToEnd(Node<T> & node) {
    node.set_next(nullptr);
    tail->set_next(&node);
    tail = &node;
}

template<typename T>
void LinkedList<T>::deleteFirstNode() {
    auto node = head->get_next();
    delete head;
    head = &node;
}

template<typename T>
void LinkedList<T>::addNode(Node<T> & node, int index) {
    auto next_ = head->get_next();
    auto prev_ = head->get_next();
    for(int i = 0;i < index - 1;i++){
        prev_ = next_;
        next_ = next_->get_next();
        if(next_ == nullptr){
            cout << "Index out of range" << endl;
            return;
        }
    }
    prev_->set_next(&node);
    node.set_next(next_);
}

template<typename T>
void LinkedList<T>::deleteLastNode() {
    auto next_ = head->get_next();
    auto prev_ = head->get_next();
    while(next_ != nullptr){
        prev_ = next_;
        next_ = next_->get_next();
    }
    prev_->set_next(nullptr);
    tail = prev_;
}

template<typename T>
void LinkedList<T>::deleteNodeByIndex(int index) {
    auto next_ = head->get_next();
    auto prev_ = head->get_next();
    for(int i = 0;i < index - 1;i++) {
        prev_ = next_;
        next_ = next_->get_next();
        if (next_ == nullptr) {
            cout << "Index out of range" << endl;
            return;
        }
    }
    delete prev_->get_next();
    prev_->set_next(next_);
}

template<typename T>
void LinkedList<T>::deleteNodeByValue(T el) {
    auto next_ = head->get_next();
    auto prev_ = head->get_next();
    while(prev_->get_next()->get_el() != el) {
        prev_ = next_;
        next_ = next_->get_next();
        if (next_ == nullptr) {
            cout << "Value out of range" << endl;
            return;
        }
    }
    delete prev_->get_next();
    prev_->set_next(next_);
}

template<typename T>
T LinkedList<T>::operator[](int index) {
    auto next_ = head->get_next();
    auto prev_ = head->get_next();
    for(int i = 0;i < index - 1;i++) {
        prev_ = next_;
        next_ = next_->get_next();
        if (next_ == nullptr) {
            cout << "Index out of range" << endl;
            return;
        }
    }
    return prev_->get_next()->get_el();
}

template<class Type>
std::ostream &operator<<(std::ostream & out, LinkedList<Type> ll) {
    Node<Type> node = *ll.head;
    if(node.get_next() == nullptr) cout << node.get_el() << " ";
    while(node.get_next() != nullptr){
        cout << node.get_el() << " ";
        node = *node.get_next();
    }
    cout << node.get_el() << " ";
    return out;
}

template<typename T>
T LinkedList<T>::findIndexByValue(T el) {
    auto next_ = head->get_next();
    auto prev_ = head->get_next();
    while(prev_->get_next()->get_el() != el) {
        prev_ = next_;
        next_ = next_->get_next();
        if (next_ == nullptr) {
            cout << "Value out of range" << endl;
            return;
        }
    }
    return prev_->get_next()->get_el();
}

#endif //LINKEDLIST_LINKEDLIST_H
