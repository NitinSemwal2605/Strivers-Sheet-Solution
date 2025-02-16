#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* reverseLL(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node*reverseUsingRecursion(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* rest = reverseUsingRecursion(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
}

void printLL(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

    cout << "Original Linked List: ";
    printLL(head);

    head = reverseLL(head);
    cout << "\nReversed Linked List: ";
    printLL(head);

    return 0;
}