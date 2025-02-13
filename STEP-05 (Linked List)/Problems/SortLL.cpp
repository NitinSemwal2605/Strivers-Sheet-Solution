// Sort Linked List using merge Sort

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
};

class Solution {
    public:
        ListNode* merge(ListNode* left, ListNode* right) {
            ListNode* dummy = new ListNode(0);
            ListNode* curr = dummy;
    
            // Merge the two lists
            while (left && right) {
                if (left->val < right->val) {
                    curr->next = left;
                    left = left->next;
                } else {
                    curr->next = right;
                    right = right->next;
                }
                curr = curr->next;
            }
    
            // Add remaining elements
            if (left) curr->next = left;
            if (right) curr->next = right;
    
            return dummy->next;
        }
    
        ListNode* mergeSort(ListNode* head) {
            if (!head || !head->next) return head; // Base Case
    
            //middle of list
            ListNode* slow = head;
            ListNode* fast = head->next;
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
    
            ListNode* right = mergeSort(slow->next); 
            slow->next = nullptr; 
            ListNode* left = mergeSort(head); 
    
            return merge(left, right);
        }
    
        ListNode* sortList(ListNode* head) {
            return mergeSort(head);
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

    return 0;
}

