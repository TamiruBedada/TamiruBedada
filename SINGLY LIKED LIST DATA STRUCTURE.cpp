// Singly linked list
#include<iostream>
using namespace std;

// Node class for singly linked list
// Contains data and pointer to next node
class Node {
public:
    int data;  // Stores the node value
    Node* next; // Points to next node in list
    
    // Constructor initializes node with value and null next pointer
    Node(int val) : data(val), next(NULL) {}
};

// Singly Linked List class implementation
// Supports insertion, deletion and traversal operations
class SinglyLinkedList {
private:
    Node* head; // Pointer to first node in list (head)

public:
    // Constructor initializes empty list with null head
    SinglyLinkedList() : head(NULL) {}

    // Inserts new node at beginning of list
    
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << "Success! Value " << val << " inserted at beginning.\n";
    }

    // Inserts new node at end of list
    
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {  // If list is empty
            head = newNode;
            cout << "Success! Value " << val << " inserted at end (list was empty).\n";
            return;
        }
        Node* temp = head;
        while (temp->next) {  // Traverse to last node
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Success! Value " << val << " inserted at end.\n";
    }

    // Inserts new node at specified position (0-based index)
    
    void insertAtPosition(int val, int pos) {
        if (pos < 0) {  // Check for invalid position
            cout << "Error! Invalid position.\n";
            return;
        }
        if (pos == 0) {  // Handle insertion at beginning
            insertAtBeginning(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        // Traverse to node before insertion position
        for (int i = 0; i < pos - 1 && temp; i++) {
            temp = temp->next;
        }
        if (!temp) {  // Position out of range
            cout << "Error! Position out of range.\n";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Success! Value " << val << " inserted at position " << pos << ".\n";
    }

    // Deletes first node from list
    void deleteFromBeginning() {
        if (!head) {  // Check if list is empty
            cout << "Error! List is empty.\n";
            return;
        }
        Node* temp = head;
        int deletedValue = temp->data;
        head = head->next;
        delete temp;
        cout << "Success! Value " << deletedValue << " deleted from beginning.\n";
    }

    // Deletes last node from list
    void deleteFromEnd() {
        if (!head) {  // Check if list is empty
            cout << "Error! List is empty.\n";
            return;
        }
        if (!head->next) {  // Only one node in list
            int deletedValue = head->data;
            delete head;
            head = NULL;
            cout << "Success! Value " << deletedValue << " deleted from end (list is now empty).\n";
            return;
        }
        Node* temp = head;
        // Traverse to second last node
        while (temp->next->next) {
            temp = temp->next;
        }
        int deletedValue = temp->next->data;
        delete temp->next;
        temp->next = NULL;
        cout << "Success! Value " << deletedValue << " deleted from end.\n";
    }

    // Deletes node from specified position (0-based index)
    
    void deleteFromPosition(int pos) {
        if (!head) {  // Check if list is empty
            cout << "Error! List is empty.\n";
            return;
        }
        if (pos == 0) {  // Handle deletion from beginning
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        // Traverse to node before deletion position
        for (int i = 0; i < pos - 1 && temp->next; i++) {
            temp = temp->next;
        }
        if (!temp->next) {  // Position out of range
            cout << "Error! Position out of range.\n";
            return;
        }
        Node* toDelete = temp->next;
        int deletedValue = toDelete->data;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "Success! Value " << deletedValue << " deleted from position " << pos << ".\n";
    }

    // Displays all elements in the list
    void display() {
        if (!head) {  // Check if list is empty
            cout << "List is empty!\n";
            return;
        }
        cout << "Current List: ";
        Node* temp = head;
        while (temp) {  // Traverse through all nodes
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";  // Mark end of list
    }
};

// Main function with menu interface

int main() {
    SinglyLinkedList list;
    int choice, val, pos;

    cout << "\nSINGLY LINKED LIST OPERATIONS\n";
    
    do {
        // Display menu options
        cout << "\n-----------------------------\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete from position\n";
        cout << "7. Display list\n";
        cout << "8. Exit\n";
        cout << "-----------------------------\n";
        cout << "Enter your choice (1-8): ";
        cin >> choice;

        // Process user choice
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                list.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> val;
                list.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Enter position (0-based index): ";
                cin >> pos;
                list.insertAtPosition(val, pos);
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter position (0-based index): ";
                cin >> pos;
                list.deleteFromPosition(pos);
                break;
            case 7:
                list.display();
                break;
            case 8:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please enter 1-8.\n";
        }
    } while (choice != 8);

    return 0;
}
