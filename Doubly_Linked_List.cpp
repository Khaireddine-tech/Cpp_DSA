#include <iostream>
using namespace std;

// Structure of a node in a DLL;
class Node {
public:
    int value;
    Node* next;
    Node* previous;
};

// Print out the DLL forward;
void printForward(Node*head) {
    Node* traverser = head;
    while (traverser != nullptr) {
        cout << traverser->value  << " <-> ";
        traverser = traverser->next;
    }
}

// Print out the DLL backward;
void printBackward(Node* tail) {
    Node* traverser = tail;
    while (traverser != nullptr) {
        cout << traverser->value << " <-> ";
        traverser = traverser->previous;
    }
}

// Insert a node at the front of the DLL;
void AddAtStart(Node*& head, int newValue){

    // Create a node and assign newValue to it;
    Node* newNode = new Node();
    newNode->value = newValue;

    // Point the newNode [nullptr <-> newNode <-> head];
    newNode->next = head;
    newNode->previous = nullptr;

    // Check if the head node is not empty [nullptr <-> newNode <-> head];
    if(head != nullptr){
        head->previous = newNode;
    }

    // Now update the move the head to the newNode;
    head = newNode;
}


// Insert a node after another node;
void InsertBefore(Node* head, int targetValue, int newValue) {
    // Create a node and assign newValue to it;
    Node* newNode = new Node();
    newNode->value = newValue;

    // Traverse the linked list to find the target node with the given value;
    Node* current = head;
    while (current != nullptr && current->value != targetValue) {
        current = current->next;
    }

    // Check if the target node was found;
    if (current == nullptr) {
        cout << "Target not found";
        return;
    }

    // Insert the new node before the target node;
    newNode->next = current;
    newNode->previous = current->previous;

    // Update the next pointer of the node before the target node;
    if (current->previous != nullptr) {
        current->previous->next = newNode; 
        /*
           Before Inserting: A <-> B <-> C
           After Inserting: A <-> N <-> B <-> C
           Explanation:

    current: Points to the target node B.
    current->previous: Points to the node before the target node, which is A.
    current->previous->next: Refers to the next pointer of the node before the target node (A). 
    In the original list, it initially pointed to B.
    current->previous->next = newNode;: This line updates the next pointer of the node before
    the target node to now point to the new node (N).

    So, current->previous->next = newNode; effectively "inserts" the new node (N) 
    before the target node (B) in the doubly linked list.
        */
    }

    // Update the previous pointer of the target node;
    current->previous = newNode;
}


// Insert a node at the end of the DLL;
void AddAtEnd(Node*& tail, int newValue){

    // Create a node and assign newValue to it;
    Node* newNode = new Node();
    newNode->value = newValue;

    // Point the newNode [nullptr <-> newNode <-> head];
    newNode->previous = tail;
    newNode->next = nullptr;

    // Check if the head node is not empty [nullptr <-> newNode <-> head];
    if(tail != nullptr){
        tail->next = newNode;
    }

    // Now update the move the head to the newNode;
    tail = newNode;
}

// Delete the a Node from a DLL;
void DeleteNode(Node*& head, int delValue) {
    // If head is null, the linked list is empty
    if (head == nullptr) {
        return;
    }

    // Create a pointer to traverse the linked list
    Node* current = head;

    // Search for the node with the desired value
    while (current != nullptr && current->value != delValue) {
        current = current->next;
    }

    // If the desired node is not found, exit the function
    if (current == nullptr) {
        return;
    }

    // Handle different cases based on the position of the node
    if (current == head) {
        // If the node is the head, update the head to the next node
        head = current->next;
    } else {
        // If the node is not the head, update the pointers of the previous and next nodes
        current->previous->next = current->next;

        // Check if the current node is not the last node
        if (current->next != nullptr) {
            current->next->previous = current->previous;
        }
    }

    // Free the memory of the deleted node
    delete current;
}




int main()
{
    Node* head;
    Node* tail;

    //add 1st node
    Node* node = new Node();
    node->value = 4;
    node->next = nullptr;
    node->previous = nullptr;
    head = node;
    tail = node;

    //add 2nd node
    node = new Node();
    node->value = 5;
    node->next = nullptr;
    node->previous = tail;
    tail->next = node;
    tail = node;

    //add 3rd node
    node = new Node();
    node->value = 6;
    node->next = nullptr;
    node->previous = tail;
    tail->next = node;
    tail = node;

    //add 4th node
    node = new Node();
    node->value = 7;
    node->next = nullptr;
    node->previous = tail;
    tail->next = node;
    tail = node;

    cout << "\n#############\n";
    printForward(head); // Output: 4 <-> 5 <-> 6 <-> 7 <-> 
    cout << "\n#############\n";
    printBackward(tail);// Output: 7 <-> 6 <-> 5 <-> 4 <-> 
    cout << "\n#############\n";
    AddAtStart(head, 12);
    cout << "\n#############\n";
    printForward(head); // Output: 12 <-> 4 <-> 5 <-> 6 <-> 7 <-> 
    cout << "\n#############\n";
    AddAtEnd(tail, 999);
    cout << "\n#############\n";
    printForward(head); // Output: 12 <-> 4 <-> 5 <-> 6 <-> 7 <-> 
    cout << "\n#############\n";
    InsertBefore(head,5,799);
    printForward(head); // Output: 12 <-> 4 <-> 799 <-> 5 <-> 6 <-> 7 <-> 999 <-> 
    cout << "\n#############\n";
    DeleteNode(head,5);
    printForward(head); // Output: 12 <-> 4 <-> 799 <-> 6 <-> 7 <-> 999 <-> 

}