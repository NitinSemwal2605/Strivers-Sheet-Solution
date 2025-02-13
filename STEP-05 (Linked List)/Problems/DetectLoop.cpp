// Detect Loop in a linked list

#include <iostream>
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

bool detectLoop(Node* n) {
    Node* slow = n;
    Node* fast = n;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
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
    third->next = head;

    // printList(head);

    // cout << endl;

    if (detectLoop(head)) {
        cout << "Loop found" << endl;
    } else {
        cout << "Loop not found" << endl;
    }

    return 0;
}
