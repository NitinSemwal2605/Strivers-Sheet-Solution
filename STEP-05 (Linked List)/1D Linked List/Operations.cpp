#include <bits/stdc++.h>  
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    node(int data){
        this->data = data;
        this-> next = NULL;
    }

    ~node(){
        int value = this->data;
        if (this->next != NULL){
            delete this->next;
        }
        cout << "Deleting Node with value: " << value << endl;
    }
}

void printList(Node* n){
    while (n != NULL){
        cout << n->data << " ";
        n = n->next;
    }
}

void InsertAtHead(Node*head , int data){
    Node*temp = new Node(data);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node*head , int data){
    Node*temp = new Node(data);
    if (head == NULL){
        head = temp;
        return;
    }
    Node*last = head;
    while (last->next != NULL){
        last = last->next;
    }
    last->next = temp;
}

void InsertAtPosition(Node*head , int data , int position){
    Node*temp = new Node(data);
    if(position == 0){
        return InsertAtHead(head , data);
    }
    Node*current = head;
    for (int i = 0; i < position - 1; i++){
        current = current->next;
    }
    temp->next = current->next;
    current->next = temp;
}


void DeleteAtHead(Node*head){
    Node*temp = head;
    head = head->next;
    delete temp;
}

void DeleteAtTail(Node*head){
    Node*temp = head;
    while (temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void DeleteAtPosition(Node*head , int position){
    Node*temp = head;
    if (position == 0){
        return DeleteAtHead(head);
    }
    for (int i = 0; i < position - 1; i++){
        temp = temp->next;
    }
    Node*temp2 = temp->next;
    temp->next = temp2->next;
    delete temp2;
}

int main(){
    Node*head = NULL;
    InsertAtHead(head , 1);
    InsertAtTail(head , 2);
    InsertAtTail(head , 3);
    InsertAtTail(head , 4);
    InsertAtTail(head , 5);
    InsertAtPosition(head , 6 , 3);
    DeleteAtHead(head);
    DeleteAtTail(head);
    DeleteAtPosition(head , 2);
    printList(head);
    return 0;
}