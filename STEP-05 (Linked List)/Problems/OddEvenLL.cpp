// 	Segrregate odd and even nodes in LL

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
};

class Solution {
    public:
        ListNode* oddEvenList(ListNode* head) {
            if(!head || !head->next || !head->next->next) return head;
            
            ListNode *odd = head;
            ListNode *even = head->next;
            ListNode *even_start = head->next;
            
            while(odd->next != NULL && even->next != NULL ){
                odd->next = even->next;  // odd link
                even->next = odd->next->next;   // even link
                odd = odd->next;
                even = even->next;
            }
            odd->next = even_start; //Connect them back
            return head; 
        }
    };

void printList(Node* n) {
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
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

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

    Solution obj;
    obj.oddEvenList(head);
    printList(head);
}

// Time Complexity: O(N)
// Space Complexity: O(1)