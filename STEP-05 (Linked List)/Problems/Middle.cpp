// Middle of linked list 

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

int middleElement(Node* n) {
    Node* slow = n;
    Node* fast = n;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
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

    cout << middleElement(head) << endl;

    return 0;
}

