// Check if LL is palindrome or not

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

bool isPalindrome(Node* n) {
    stack<int> s;
    Node* temp = n;
    while (temp != NULL) {
        s.push(temp->data);
        temp = temp->next;
    }

    while (n != NULL) {
        int i = s.top();
        s.pop();
        if (n->data != i) {
            return false;
        }
        n = n->next;
    }

    return true;
}

int main (){
    Node* head = NULL; 
    Node* second = NULL; 
    Node* third = NULL;
    Node* fourth = NULL;

    head = new Node(); 
    second = new Node();
    third = new Node();
    fourth = new Node();

    head->data = 1; 
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 2;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = NULL;

    printList(head);

    cout << endl;

    if (isPalindrome(head)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}

