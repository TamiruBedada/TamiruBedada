// CIRCULAR LINKED LIST
#include <iostream>
using namespace std;

// Node class for Circular Singly Linked List
class Node {
public:
    int data;    // Data stored in the node
    Node* next;  // Pointer to next node
    
     
    Node(int val) : data(val), next(NULL) {}
};

// Circular Singly Linked List class
class CircularSinglyLinkedList {
private:
    Node* head;  // Pointer to the first node
    Node* tail;  // Pointer to the last node

public:
    // Constructor initializes empty list
    CircularSinglyLinkedList() : head(NULL), tail(NULL) {}

    // Check if list is empty
    bool isEmpty() {
        return head == NULL;
    }

    // Insert at beginning of list
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            head = tail = newNode;
            newNode->next = head;  // Circular reference
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;  // Maintain circularity
        }
        cout << val << " inserted at beginning.\n";
    }

    // Insert at end of list
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            head = tail = newNode;
            newNode->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;  // Point back to head
        }
        cout << val << " inserted at end.\n";
    }

    // Insert at specific position (0-based)
    void insertAtPosition(int val, int pos) {
        if (pos < 0) {
            cout << "Invalid position!\n";
            return;
        }
        
        if (pos == 0) {
            insertAtBeginning(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* current = head;
        int currentPos = 0;

        // Traverse to position-1
        while (currentPos < pos - 1 && current->next != head) {
            current = current->next;
            currentPos++;
        }

        if (currentPos != pos - 1) {
            cout << "Position out of range!\n";
            delete newNode;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
        
        // Update tail if inserting at end
        if (newNode->next == head) {
            tail = newNode;
        }
        cout << val << " inserted at position " << pos << ".\n";
    }

    // Delete from beginning
    void deleteFromBeginning() {
        if (isEmpty()) {
            cout << "List is empty!\n";
            return;
        }

        int deletedValue = head->data;
        
        if (head == tail) {  // Only one node
            delete head;
            head = tail = NULL;
        } else {
            Node* temp = head;
            head = head->next;
            tail->next = head;  // Maintain circularity
            delete temp;
        }
        cout << deletedValue << " deleted from beginning.\n";
    }

    // Delete from end
    void deleteFromEnd() {
        if (isEmpty()) {
            cout << "List is empty!\n";
            return;
        }

        int deletedValue = tail->data;
        
        if (head == tail) {  // Only one node
            delete head;
            head = tail = NULL;
        } else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = head;  // Maintain circularity
        }
        cout << deletedValue << " deleted from end.\n";
    }

    // Delete from specific position (0-based)
    void deleteFromPosition(int pos) {
        if (isEmpty()) {
            cout << "List is empty!\n";
            return;
        }

        if (pos == 0) {
            deleteFromBeginning();
            return;
        }

        Node* current = head;
        Node* prev = NULL;
        int currentPos = 0;

        // Traverse to position
        while (currentPos < pos && current->next != head) {
            prev = current;
            current = current->next;
            currentPos++;
        }

        if (currentPos != pos) {
            cout << "Position out of range!\n";
            return;
        }

        int deletedValue = current->data;
        prev->next = current->next;
        
        // Update tail if deleting last node
        if (current == tail) {
            tail = prev;
        }
        
        delete current;
        cout << deletedValue << " deleted from position " << pos << ".\n";
    }

    // Display the list
    void display() {
        if (isEmpty()) {
            cout << "List is empty!\n";
            return;
        }

        Node* current = head;
        cout << "Circular List: ";
        
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != head);
        
        cout << "(head)\n";
    }

    // Destructor to clean up memory
    ~CircularSinglyLinkedList() {
        if (isEmpty()) return;
        
        Node* current = head;
        Node* nextNode;
        
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
    }
};

// Main menu function
int main() {
    CircularSinglyLinkedList list;
    int choice, value, position;

    do {
        cout << "\nCIRCULAR SINGLY LINKED LIST MENU\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete from position\n";
        cout << "7. Display list\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                list.insertAtPosition(value, position);
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> position;
                list.deleteFromPosition(position);
                break;
            case 7:
                list.display();
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 8);

    return 0;
}
