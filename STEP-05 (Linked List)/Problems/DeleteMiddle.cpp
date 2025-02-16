#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:
    int data;
    ListNode* next;
};

ListNode* deleteMiddle(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = NULL; 

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Remove the middle node
    if (prev != NULL && prev->next != NULL) {
        prev->next = prev->next->next;
    }

    return head;
}

void printList(ListNode* n) {
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

int main() {
    ListNode* head = new ListNode();
    ListNode* second = new ListNode();
    ListNode* third = new ListNode();
    ListNode* fourth = new ListNode();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

    cout << "Original List: ";
    printList(head);

    head = deleteMiddle(head);

    cout << "\nList after deleting middle element: ";
    printList(head);

    return 0;
}