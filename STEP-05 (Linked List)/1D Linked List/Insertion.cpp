#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    //constructor 
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

     //destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }


};

// AT HEAD...
void InsertAtHead(Node* &head, int d) {
    // new node created ...
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

// AT TAIL...
void insertAtTail(Node* &tail, int d) {
    // new node create
    Node* temp = new Node(d); // new node created
    tail = tail-> next; // tail is updated
    tail = temp; // tail is updated
}

// AT POSITION...
void insertAtPosition(Node* &head, Node* &tail, int position, int d) {
    
    // Insert at Start
    if (position == 1) {
        InsertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    // Now at Center
    while (cnt < position - 1) { // jab ( cnt < n-1 )
        temp = temp->next;
        cnt++;
    }

    // Inserting at Last Position then updating the Tail
    if (temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }

    // Creating a node for D...
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

}


void deleteNode(int position, Node* & head) { 

    //deleting first 
    if(position == 1) { 
        Node* temp = head; 
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;   //free kardiya first node ko..
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        
        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;   //free kardiya
        delete curr;
    }
}

void print(Node* &head) {
    Node* temp = head; // temp is a pointer to head

    while (temp != NULL) { // jab tak temp null nahi hota tab tak print karte raho
        cout << temp->data << "  "; 
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Created a new node
    Node* node1 = new Node(10);

    // Head and tail both point to node1
    Node* head = node1;
    Node* tail = node1;

    // insertAtTail(tail, 12);
    InsertAtHead(head,229);
    // insertAtTail(tail, 15);
    // insertAtPosition(head, tail, 4, 22);

    print(head);

    return 0;
}





