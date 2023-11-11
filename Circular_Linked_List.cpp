#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
};

// Display all the nodes;
void DisplayList(Node* head) {
    if (head == nullptr) {
        cout << "Empty circular list" << endl;
        return;
    }

    Node* current = head;

/*
in a circular linked list, you always need to execute the loop at least once 
to print the first node (starting node). The condition for exiting the loop 
is then checked after the first iteration.
*/

    do {
        cout << current->value << " -> ";
        current = current->next;
    } while (current != head);

    cout << "(head)" << endl;
}

// Insert a Node at the beginning of CLL;
void InsertAtBeginning(Node*& head, int newValue) {
    Node* newNode = new Node();
    newNode->value = newValue;

    if (head == nullptr) {
        head = newNode;
        head->next = head;  // Point to itself in a circular list
    } else {
        newNode->next = head->next;
        head->next = newNode;
    }

/*
A"head" -> B -> C -> {A}
A"head" -> NEW -> B -> C -> {A}
*/
}

// Insert a node after another node in CLL;
void InsertInBetween(Node*& head, int newValue, int afterValue) {
    if (head == nullptr) {
        cout << "List is empty, cannot insert in between" << endl;
        return;
    }

    Node* newNode = new Node();
    newNode->value = newValue;
    Node* current = head;

    // Find the node with the specified value
    while (current->value != afterValue) {
        current = current->next;

        // Check if we have traversed the entire list without finding the specified value
        if (current == head) {
            cout << "Node with value " << afterValue << " not found in the list" << endl;
            delete newNode;
            return;
        }
    }

    // Insert the new node after the found node
    newNode->next = current->next;
    current->next = newNode;
}


// Insert a node at the end of CLL;
void InsertAtEnd(Node*& head, int newValue) {
    if (head == nullptr) {
        cout << "List is empty, cannot insert at end" << endl;
        return;
    }

    Node* newNode = new Node();
    newNode->value = newValue;
    newNode->next = head->next;  
    // Point the new node to the first node
    head->next = newNode;        
    // Update the next pointer of the current last node to point to the new node
    head = newNode;              
    // Update the head to the newly added node for it to be the new end
}

// Delete the first node of CLL;
void DeleteFirstNode(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty, cannot delete first node" << endl;
        return;
    }

    Node* toDelete = head->next;

    if (toDelete == head) {
        // Only one node in the list
        delete toDelete;
        head = nullptr;
    } else {
        head->next = toDelete->next;
        delete toDelete;
    }
}

// Delete the last node of CLL;
void DeleteLastNode(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty, cannot delete last node" << endl;
        return;
    }

    Node* current = head;

    // Traverse the list until the second-to-last node
    while (current->next != head) {
        current = current->next;
    }

    // Handle the case where there is only one node in the list
    if (current == head) {
        delete head;
        head = nullptr;
    } else {
        Node* toDelete = current->next;
        current->next = toDelete->next;
        delete toDelete;
    }
}

// Delete a node with a specific value in CLL;
void deleteNode(Node*& head, int targetValue) {
    if (head == nullptr) {
        cout << "List is empty, cannot delete node with value " << targetValue << endl;
        return;
    }

    Node* current = head;
    Node* toDelete = nullptr;

    // Find the node with the specified value
    while (current->next != head) {
        if (current->next->value == targetValue) {
            toDelete = current->next;
            break;
        }
        current = current->next;
    }

    if (toDelete == nullptr) {
        // Node with the specified value not found
        cout << "Node with value " << targetValue << " not found in the list" << endl;
    } else {
        // Delete the node with the specified value
        current->next = toDelete->next;
        delete toDelete;

        // Update head if the deleted node was the head
        if (head->value == targetValue) {
            head = current->next;
        }
    }
}


int main(){

    // Initializing Nodes
    Node* head;
    Node* one = new Node();
    Node* two = new Node();
    Node* three = new Node();

    // Giving them values
    one->value = 1;
    two->value = 2;
    three->value = 3;
    head = one;

    // Linking all the nodes in cicular way;
    one->next = two;
    two->next = three;
    three->next = one;

    //cout << "\n#############\n";
    //DisplayList(head); // Output: 1 -> 2 -> 3 -> (head)
    cout << "\n#############\n";

    InsertAtBeginning(head, 99);
    InsertAtEnd(head, 988);
    InsertInBetween(head,55, 988);
    DisplayList(head); // Output: 988 -> 55 -> 99 -> 2 -> 3 -> 1 -> (head)
    cout << "\n#############\n";
    
    deleteNode(head, 55);
    DisplayList(head); // Output: 988 -> 99 -> 2 -> 3 -> 1 -> (head)

    return 0;
}