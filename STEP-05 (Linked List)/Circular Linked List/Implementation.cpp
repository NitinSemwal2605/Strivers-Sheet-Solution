// Implementation of Circular Linked List

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty" << endl;
        } else {
            Node* temp = head;
            Node* prev = NULL;
            while (temp->next != head) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = head;
            delete temp;
        }
    }

    void deleteAtBeginning() {
        if (head == NULL) {
            cout << "List is empty" << endl;
        } else {
            Node* temp = head;
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = head->next;
            head = head->next;
            delete temp;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty" << endl;
        } else {
            Node* temp = head;
            do {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != head);
            cout << endl;
        }
    }
};