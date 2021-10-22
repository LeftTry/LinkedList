#include <iostream>
#include "Node.h"
#include "LinkedList.h"

int main() {
    LinkedList<int> list(3);
    Node<int> b(4);
    list.addNodeToBegin(b);
    Node<int> a(5);
    list.addNode(a, 3);
    cout << list;
    return 0;
}
