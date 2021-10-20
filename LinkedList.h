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

    bool isNull();

    void addNodeToBegin(Node<T>&);
    void addNodeToEnd(Node<T>&);
    void addNode(Node<T>&, int);

    void deleteFirstNode();
    void deleteLastNode();
    void deleteNodeByIndex(int);
    void deleteNodeByValue(T);

    void findIndexByValue(T);

    LinkedList<T> operator[]();

    template<class Type> friend std::ostream & operator<<(std::ostream&, LinkedList<Type>);
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
void LinkedList<T>::addNodeToBegin(Node<T> & node){
    node.set_next(head)
    head = *node;
}

template<typename T>
void LinkedList<T>::addNodeToEnd(Node<T> & node) {
    tail->set_next(*node)
    node.set_next(tail)
}

template<typename T>
void LinkedList<T>::deleteFirstNode() {
    auto node = head->get_next();
    delete head;
    head = node;
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
    prev_->set_next(*node);
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
    tail =
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

}

template<typename T>
LinkedList<T> LinkedList<T>::operator[]() {
    return LinkedList<T>();
}

template<class Type>
std::ostream &operator<<(std::ostream &, LinkedList<Type>) {
    return <#initializer#>;
}

template<typename T>
void LinkedList<T>::findIndexByValue(T el) {

}

#endif //LINKEDLIST_LINKEDLIST_H
