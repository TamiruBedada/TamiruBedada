// CIRCULAR DOUBLY LINKED LIST
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* prev;
    Node* next;
    
    // Constructor initializes node with value and null pointers
    Node(int val) : data(val), prev(NULL), next(NULL) {}
};


class CircularDoublyLinkedList {
private:
    Node* head;  // Pointer to first node (head) of the list

public:
    // Constructor initializes empty list
    CircularDoublyLinkedList() : head(NULL) {}
    
    
     // INSERT AT BEGINNING
     
     
     
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        
        if (!head) {  // Empty list case
            head = newNode;
            head->next = head;
            head->prev = head;
            cout << "SUCCESS: Created new list with head value " << val << endl;
            return;
        }
        
        // Link new node between current head and tail
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
        
        cout << "SUCCESS: Inserted " << val << " at beginning. New head updated." << endl;
    }
    
    
      // INSERT AT END 

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        
        if (!head) {  // Empty list case
            head = newNode;
            head->next = head;
            head->prev = head;
            cout << "SUCCESS: Created new list with head value " << val << endl;
            return;
        }
        
        // Link new node between tail and head
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        
        cout << "SUCCESS: Inserted " << val << " at end. Tail updated." << endl;
    }
    
    void insertAtPosition(int val, int pos) {
        if (pos < 0) {
            cout << "ERROR: Invalid position " << pos << ". Position must be >= 0." << endl;
            return;
        }
        
        if (pos == 0) {  // Handle head insertion
            insertAtBeginning(val);
            return;
        }
        
        Node* newNode = new Node(val);
        Node* current = head;
        int currentPos = 0;
        
        // Traverse to node before insertion point
        while (currentPos < pos - 1 && current->next != head) {
            current = current->next;
            currentPos++;
        }
        
        // Validate position
        if (currentPos != pos - 1) {
            cout << "ERROR: Position " << pos << " exceeds list size. Current size: " << currentPos + 1 << endl;
            delete newNode;
            return;
        }
        
        // Insert new node
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
        
        cout << "SUCCESS: Inserted " << val << " at position " << pos << endl;
    }
    
    
    //  DELETE FROM BEGINNING
     
    void deleteFromBeginning() {
        if (!head) {
            cout << "ERROR: List is empty - nothing to delete." << endl;
            return;
        }
        
        int deletedValue = head->data;
        
        if (head->next == head) {  // Single node case
            delete head;
            head = NULL;
            cout << "SUCCESS: Deleted " << deletedValue << ". List is now empty." << endl;
            return;
        }
        
        // Update links to bypass current head
        Node* temp = head;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        delete temp;
        
        cout << "SUCCESS: Deleted head value " << deletedValue << ". New head is " << head->data << endl;
    }
    
    void deleteFromEnd() {
        if (!head) {
            cout << "ERROR: List is empty - nothing to delete." << endl;
            return;
        }
        
        Node* tail = head->prev;
        int deletedValue = tail->data;
        
        if (head->next == head) {  // Single node case
            delete head;
            head = NULL;
            cout << "SUCCESS: Deleted " << deletedValue << ". List is now empty." << endl;
            return;
        }
        
        // Update links to bypass tail
        tail->prev->next = head;
        head->prev = tail->prev;
        delete tail;
        
        cout << "SUCCESS: Deleted tail value " << deletedValue << ". New tail is " << head->prev->data << endl;
    }
    
    
   //  DELETE FROM POSITION
     
    void deleteFromPosition(int pos) {
        if (!head) {
            cout << "ERROR: List is empty - nothing to delete." << endl;
            return;
        }
        
        if (pos == 0) {  
            deleteFromBeginning();
            return;
        }
        
        Node* current = head;
        int currentPos = 0;
        
        // Traverse to node to delete
        while (currentPos < pos && current->next != head) {
            current = current->next;
            currentPos++;
        }
        
        // Validate position
        if (currentPos != pos) {
            cout << "ERROR: Position " << pos << " exceeds list size. Current size: " << currentPos + 1 << endl;
            return;
        }
        
        int deletedValue = current->data;
        
        // Bypass node to be deleted
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        
        cout << "SUCCESS: Deleted value " << deletedValue << " from position " << pos << endl;
    }
    
    
     //  DISPLAY LIST
     
    void display() {
        if (!head) {
            cout << "LIST: Empty" << endl;
            return;
        }
        
        cout << "LIST: ";
        Node* current = head;
        
        do {
            cout << current->data;
            if (current->next != head) {
                cout << " ? ";  // Circular connection symbol
            }
            current = current->next;
        } while (current != head);
        
        cout << " [Head: " << head->data << ", Tail: " << head->prev->data << "]" << endl;
    }
};

 // MAIN MENU INTERFACE
 
int main() {
    CircularDoublyLinkedList list;
    int choice, value, position;
    
    cout << "\nCIRCULAR DOUBLY LINKED LIST MANAGER\n";
    
    do {
        cout << "\n------------ MENU ------------\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete from position\n";
        cout << "7. Display list\n";
        cout << "8. Exit\n";
        cout << "------------------------------\n";
        cout << "Enter choice (1-8): ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
                
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
                
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position (0-based): ";
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
                cout << "Enter position (0-based): ";
                cin >> position;
                list.deleteFromPosition(position);
                break;
                
            case 7:
                list.display();
                break;
                
            case 8:
                cout << "Exiting program. Goodbye!\n";
                break;
                
            default:
                cout << "INVALID CHOICE! Please enter 1-8.\n";
        }
    } while(choice != 8);
    
    return 0;
}
