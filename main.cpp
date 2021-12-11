#include <iostream>
#include "Node.h"
#include "LinkedList.h"

int main() {
    LinkedList<int> list;
    if(list.isNull()) cout << "List is empty" << endl;
    else cout << "List is not empty" << endl;
    int size;
    cout << "Please enter list size:" << endl;
    cin >> size;
    int a;
    cout << "Please enter elements of the list:" << endl;
    cin >> a;
    list.addNodeToBegin(a);
    for(int i = 0;i < size - 1;i++){
        int a1;
        cin >> a1;
        list.addNodeToEnd(a1);
    }
    cout << "Please enter the element to add to begin:" << endl;
    int b;
    cin >> b;
    list.addNodeToBegin(b);
    cout << "Please enter value and index of element to insert into the list:" << endl;
    int val, ind;
    cin >> val >> ind;
    list.addNode(val, ind);
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
