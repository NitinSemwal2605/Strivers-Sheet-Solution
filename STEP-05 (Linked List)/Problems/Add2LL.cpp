#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
};

class Solution {
    public:
        Node* addTwoNumbers(Node* l1, Node* l2) {
            Node* dummy = new Node();
            Node* temp = dummy;
            int carry = 0;
            while (l1 || l2 || carry) {
                int sum = 0;
                if (l1) {
                    sum += l1->data;
                    l1 = l1->next;
                }
                if (l2) {
                    sum += l2->data;
                    l2 = l2->next;
                }
                sum += carry;
                carry = sum / 10;
                Node* newNode = new Node();
                newNode->data = sum % 10;
                temp->next = newNode;
                temp = temp->next;
            }
            return dummy->next;
        }
};

void printList(Node* n) {
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main() {
    Node* l1 = new Node();
    Node* l2 = new Node();
    Node* l3 = new Node();
    Node* l4 = new Node();
    Node* l5 = new Node();
    Node* l6 = new Node();
    Node* l7 = new Node();
    Node* l8 = new Node();
    Node* l9 = new Node();
    Node* l10 = new Node();
    l1->data = 2;
    l1->next = l2;
    l2->data = 4;
    l2->next = l3;
    l3->data = 3;
    l3->next = NULL;
    l4->data = 5;
    l4->next = l5;
    l5->data = 6;
    l5->next = l6;
    l6->data = 4;
    l6->next = NULL;
    l7->data = 9;
    l7->next = l8;
    l8->data = 9;
    l8->next = l9;
    l9->data = 9;
    l9->next = l10;
    l10->data = 9;
    l10->next = NULL;
    Solution s;
    Node* res1 = s.addTwoNumbers(l1, l4);
    Node* res2 = s.addTwoNumbers(l7, l4);
    printList(res1);
    printList(res2);
    return 0;
}