#include <iostream>
using namespace std;

/**
 * Node class for Doubly Linked List
 * Contains data, pointer to previous node, and pointer to next node
 */
class Node {
public:
    int data;       // Data stored in the node
    Node* prev;     // Pointer to previous node
    Node* next;     // Pointer to next node

    // Constructor initializes node with given value and null pointers
    Node(int val) : data(val), prev(NULL), next(NULL) {}
};

/**
 * Doubly Linked List class
 * Supports insertion/deletion at beginning, end, and specific positions
 */
class DoublyLinkedList {
private:
    Node* head;     // Pointer to first node in the list

public:
    // Constructor initializes empty list with null head pointer
    DoublyLinkedList() : head(NULL) {}

    /**
     * Insert new node at beginning of list
     * @param val Value to be inserted
     */
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);  // Create new node
        
        // If list not empty, set current head's previous to new node
        if (head) {
            head->prev = newNode;
        }
        
        newNode->next = head;  // New node points to current head
        head = newNode;        // Update head to new node
        
        cout << "SUCCESS: " << val << " inserted at beginning of list.\n";
    }

    /**
     * Insert new node at end of list
     * @param val Value to be inserted
     */
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        
        // Handle empty list case
        if (!head) {
            head = newNode;
            cout << "SUCCESS: " << val << " inserted at end (list was empty).\n";
            return;
        }
        
        // Traverse to last node
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        
        // Link new node to end of list
        temp->next = newNode;
        newNode->prev = temp;
        
        cout << "SUCCESS: " << val << " inserted at end of list.\n";
    }

    /**
     * Insert new node at specific position (0-based index)
     * @param val Value to be inserted
     * @param pos Position index (0 = beginning)
     */
    void insertAtPosition(int val, int pos) {
        // Validate position
        if (pos < 0) {
            cout << "ERROR: Invalid position (" << pos << "). Must be >= 0.\n";
            return;
        }
        
        // Handle insertion at beginning
        if (pos == 0) {
            insertAtBeginning(val);
            return;
        }
        
        Node* newNode = new Node(val);
        Node* temp = head;
        
        // Traverse to node before insertion point
        for (int i = 0; i < pos - 1 && temp; i++) {
            temp = temp->next;
        }
        
        // Check if position is valid
        if (!temp) {
            cout << "ERROR: Position " << pos << " is out of range.\n";
            return;
        }
        
        // Link new node into position
        newNode->next = temp->next;
        newNode->prev = temp;
        
        // Update next node's previous pointer if not inserting at end
        if (temp->next) {
            temp->next->prev = newNode;
        }
        
        temp->next = newNode;
        cout << "SUCCESS: " << val << " inserted at position " << pos << ".\n";
    }

    /**
     * Delete first node from list
     */
    void deleteFromBeginning() {
        if (!head) {
            cout << "ERROR: Cannot delete - list is empty.\n";
            return;
        }
        
        Node* temp = head;
        int deletedValue = temp->data;
        
        // Update head pointer
        head = head->next;
        
        // If list not empty after deletion, update new head's previous pointer
        if (head) {
            head->prev = NULL;
        }
        
        delete temp;
        cout << "SUCCESS: " << deletedValue << " deleted from beginning of list.\n";
    }

    
     //  Delete last node from list
     
    void deleteFromEnd() {
        if (!head) {
            cout << "ERROR: Cannot delete - list is empty.\n";
            return;
        }
        
        // Handle single node case
        if (!head->next) {
            int deletedValue = head->data;
            delete head;
            head = NULL;
            cout << "SUCCESS: " << deletedValue << " deleted (list is now empty).\n";
            return;
        }
        
        // Traverse to last node
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        
        int deletedValue = temp->data;
        temp->prev->next = NULL;  // Update previous node's next pointer
        delete temp;
        
        cout << "SUCCESS: " << deletedValue << " deleted from end of list.\n";
    }

    /**
     * Delete node from specific position (0-based index)
     * @param pos Position index (0 = beginning)
     */
    void deleteFromPosition(int pos) {
        if (!head) {
            cout << "ERROR: Cannot delete - list is empty.\n";
            return;
        }
        
        // Handle deletion from beginning
        if (pos == 0) {
            deleteFromBeginning();
            return;
        }
        
        Node* temp = head;
        
        // Traverse to node to be deleted
        for (int i = 0; i < pos && temp; i++) {
            temp = temp->next;
        }
        
        // Check if position is valid
        if (!temp) {
            cout << "ERROR: Position " << pos << " is out of range.\n";
            return;
        }
        
        int deletedValue = temp->data;
        
        // Update surrounding nodes' pointers
        temp->prev->next = temp->next;
        if (temp->next) {
            temp->next->prev = temp->prev;
        }
        
        delete temp;
        cout << "SUCCESS: " << deletedValue << " deleted from position " << pos << ".\n";
    }

    /**
     * Display all elements in the list (forward traversal)
     * Shows both data and link structure
     */
    void display() {
        if (!head) {
            cout << "List status: Empty\n";
            return;
        }
        
        cout << "List contents: NULL <- ";
        Node* temp = head;
        
        while (temp) {
            cout << temp->data;
            if (temp->next) {
                cout << " <-> ";  // Middle nodes
            } else {
                cout << " -> ";   // Last node
            }
            temp = temp->next;
        }
        
        cout << "NULL\n";
    }
};
// Main function with menu-driven interface
int main() {
    DoublyLinkedList list;
    int choice, val, pos;
    
    cout << "\nDOUBLY LINKED LIST IMPLEMENTATION\n";
    
    do {
        // Display menu
        cout << "\n------------------------------\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete from position\n";
        cout << "7. Display list\n";
        cout << "8. Exit\n";
        cout << "------------------------------\n";
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
                cout << "ERROR: Invalid choice. Please enter 1-8.\n";
        }
    } while (choice != 8);
    
    return 0;
}
