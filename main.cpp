#include <iostream>
#include "Node.h"
#include "LinkedList.h"

int main() {
    LinkedList<int> list;
    cout << list.isNull();
    int size;
    cin >> size;
    int a;
    cin >> a;
    Node<int> node(a);
    list.addNodeToBegin(node);
    for(int i = 0;i < size - 1;i++){
        int a1;
        cin >> a1;
        auto *node1 = new Node<int>(a1);
        list.addNodeToEnd(*node1);
    }
    Node<int> b(4);
    list.addNodeToBegin(b);
    Node<int> n(5);
    list.addNode(n, 3);
    cout << list << endl;
    list.deleteFirstNode();
    list.deleteLastNode();
    list.deleteNodeByIndex(2);
    list.deleteNodeByValue(1);
    cout << list << endl;
    int index = list.findIndexByValue(2);
    cout << index << endl;
    cout << list[0] << endl;
    return 0;
}
