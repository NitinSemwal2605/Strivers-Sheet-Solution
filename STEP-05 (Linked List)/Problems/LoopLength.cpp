// Length of Loop in LL

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

int loopLength(Node* n) {
    Node* slow = n;
    Node* fast = n;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }

    if (slow != fast) {
        return 0;
    }

    int count = 1;
    slow = slow->next;
    while (slow != fast) {
        count++;
        slow = slow->next;
    }

    return count;
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

    cout << loopLength(head) << endl;

    return 0;
}
