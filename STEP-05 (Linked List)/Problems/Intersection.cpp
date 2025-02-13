// Intersection of two linked lists

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

int getLength(Node* n) {
    int length = 0;
    while (n != NULL) {
        length++;
        n = n->next;
    }
    return length;
}

Node* getIntersection(Node* head1, Node* head2) {
    int length1 = getLength(head1);
    int length2 = getLength(head2);

    Node* temp1 = head1;
    Node* temp2 = head2;

    if (length1 > length2) {
        for (int i = 0; i < length1 - length2; i++) {
            temp1 = temp1->next;
        }
    } else {
        for (int i = 0; i < length2 - length1; i++) {
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1 == temp2) {
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return NULL;
}

int main (){
    Node* head1 = NULL; 
    Node* second1 = NULL; 
    Node* third1 = NULL;
    Node* fourth1 = NULL;
    Node* fifth1 = NULL;

    head1 = new Node(); 
    second1 = new Node();
    third1 = new Node();
    fourth1 = new Node();
    fifth1 = new Node();

    head1->data = 1; 
    head1->next = second1;

    second1->data = 2;
    second1->next = third1;

    third1->data = 3;
    third1->next = fourth1;

    fourth1->data = 4;
    fourth1->next = fifth1;

    fifth1->data = 5;
    fifth1->next = NULL;

    Node* head2 = NULL; 
    Node* second2 = NULL; 
    Node* third2 = NULL;

    head2 = new Node(); 
    second2 = new Node();
    third2 = new Node();

    head2->data = 6; 
    head2->next = second2;

    second2->data = 7;
    second2->next = third2;

    third2->data = 8;
    third2->next = fourth1;

    Node* intersection = getIntersection(head1, head2);

    if (intersection) {
        cout << "Intersection found at " << intersection->data << endl;
    } else {
        cout << "No intersection found" << endl;
    }
}

