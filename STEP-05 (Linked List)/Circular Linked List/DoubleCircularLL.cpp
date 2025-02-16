#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int d){
        data = d;
        next = nullptr;
        prev = nullptr;
    }

    ~Node(){
        int data = this->data;
        if(next != nullptr){
            delete next;
            next = nullptr;
        }
        cout << "memory freed for node with data " << data << endl;
    }
};

void print(Node* head){
    if (head == nullptr) return;  // Avoid printing empty list
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != head);  // Keep looping until we come back to head
    cout << endl;
}

void InsertAtHead(Node* &head, Node* &tail, int d){
    Node* temp = new Node(d);
    if(head == nullptr){
        head = tail = temp;
        head->next = head;  // Point to itself (circular)
        head->prev = head;  // Point to itself (circular)
    } else {
        temp->next = head;
        temp->prev = tail;
        head->prev = temp;
        tail->next = temp;
        head = temp;
    }
}

void InsertAtEnd(Node* &head, Node* &tail, int d){
    Node* temp = new Node(d);
    if(head == nullptr){
        head = tail = temp;
        head->next = head;  // Point to itself (circular)
        head->prev = head;  // Point to itself (circular)
    } else {
        temp->prev = tail;
        temp->next = head;
        tail->next = temp;
        head->prev = temp;
        tail = temp;
    }
}

void DeleteAtHead(Node* &head, Node* &tail){
    if(head == nullptr){
        cout << "List is empty!" << endl;
        return;
    }
    if(head == tail){
        delete head;
        head = tail = nullptr;
    } else {
        Node* temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete temp;
    }
}

void DeleteAtEnd(Node* &head, Node* &tail){
    if(head == nullptr){
        cout << "List is empty!" << endl;
        return;
    }
    if(head == tail){
        delete head;
        head = tail = nullptr;
    } else {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete temp;
    }
}

void Reverse(Node* &head, Node* &tail){
    if (head == nullptr) return;
    
    Node* temp = nullptr;
    Node* current = head;
    
    // Reversing the next and prev pointers
    do {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    } while(current != head);
    
    // Swapping head and tail
    if(head != nullptr && tail != nullptr) {
        Node* tempHead = head;
        head = tail;
        tail = tempHead;
    }
}

int main(){
    Node* head = nullptr;
    Node* tail = nullptr;

    print(head);

    InsertAtHead(head, tail, 11);
    print(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    InsertAtHead(head, tail, 13);
    print(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    InsertAtEnd(head, tail, 15);
    print(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    InsertAtEnd(head, tail, 17);
    print(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    DeleteAtHead(head, tail);
    print(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    DeleteAtEnd(head, tail);
    print(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    Reverse(head, tail);
    print(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    return 0;
}
