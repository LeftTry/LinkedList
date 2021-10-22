#ifndef NODE_H
#define NODE_H

template <typename T>
class Node{
    Node<T>* next;
    T element;
public:
    Node();
    Node(T);

    T get_el();
    void set_el(T);

    Node<T>* get_next();
    void set_next(Node<T>*);
};

template<typename T>
Node<T>::Node() {
    next = nullptr;
    element = 0;
}

template<typename T>
Node<T>::Node(T el) {
    next = nullptr;
    element = el;
}

template<typename T>
T Node<T>::get_el() {
    return element;
}

template<typename T>
void Node<T>::set_el(T el) {
    element = el;
}

template<typename T>
Node<T> *Node<T>::get_next() {
    return next;
}

template<typename T>
void Node<T>::set_next(Node<T> *next_) {
    next = next_;
}

#endif // NODE_H

