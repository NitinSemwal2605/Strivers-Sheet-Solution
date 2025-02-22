// Search Element in a LL 

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
};

void printList(Node* n) {
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

bool searchElement(Node* n, int key) {
    while (n != NULL) {
        if (n->data == key) {
            return true;
        }
        n = n->next;
    }
    return false;
}

int main (){
    Node* head = NULL; 
    Node* second = NULL; 
    Node* third = NULL;

    head = new Node(); 
    second = new Node();
    third = new Node();

    head->data = 1; 
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printList(head);

    cout << endl;

    int key = 2;
    if (searchElement(head, key)) {
        cout << "Element found" << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}