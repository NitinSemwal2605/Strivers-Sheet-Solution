#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;
    
public:
    // Constructor
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        
        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // The new node points to itself
        } else {
            Node* temp = head;
            // Traverse to the last node
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode; // New node becomes the head
        }
    }

    // Function to insert a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        
        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // The new node points to itself
        } else {
            Node* temp = head;
            // Traverse to the last node
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Function to delete a node from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        
        if (head->next == head) {
            // Only one node in the list
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            // Traverse to the last node
            while (temp->next != head) {
                temp = temp->next;
            }
            // Make the last node's next pointer point to the second node
            temp->next = head->next;
            delete head;
            head = temp->next; // Move head to the second node
        }
    }

    // Function to delete a node from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        
        if (head->next == head) {
            // Only one node in the list
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            Node* prev = nullptr;
            
            // Traverse to the second last node
            while (temp->next != head) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = head; // The second last node's next points to head
            delete temp;
        }
    }

    // Function to traverse and print the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;

    // Insert nodes
    cll.insertAtBeginning(10);
    cll.insertAtBeginning(20);
    cll.insertAtEnd(30);
    cll.insertAtEnd(40);

    // Display the list
    cout << "Circular Linked List: ";
    cll.display();

    // Deleting nodes
    cll.deleteFromBeginning();
    cout << "After deletion from beginning: ";
    cll.display();

    cll.deleteFromEnd();
    cout << "After deletion from end: ";
    cll.display();

    return 0;
}
