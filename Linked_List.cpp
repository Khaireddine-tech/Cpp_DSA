#include <iostream>
using namespace std;

// Initialize a Node class
class Node {
public:
	int Value;
	Node* Next;
};

// Let's create a function to display the Linked List;

void Display(Node* n) {
	// Check if the the current Node is not NULL
	while (n != NULL) {
		cout << n->Value << " -> ";
		n = n->Next;
	}
}

// now let's add a Node to the start of the Linked List;
void InsertingAtStart(Node** head, int newValue) { // we need to get the head node and the value of the new node;

	// Let's create a new Node
	Node* newNode = new Node();
	newNode->Value = newValue;
	newNode->Next = *head;

	// Point the newNode to the last head and make it the new head;
	*head = newNode;
};

// now Let's add a node after another Node;
void InsertingAfter(Node* previous, int newValue) { // we need the address of the previous node and then we need the value of the new one;
	
	// let's create a node first
	Node* newNode = new Node();
	newNode->Value = newValue;

	// now let's check if the previous node is NULL;
	if (previous->Next == NULL) {
		cout << "Please make sure that the previous node is not NULL";
		return;
	}

	// Now let's update the pointers of the previous and new node;
	newNode->Next = previous->Next;
	previous->Next = newNode;


}

// now let's add a node at the end of the Linked List;
void InsertingAtEnd(Node** head, int newValue) { // we'll need the last Node and also the value of the new Node;

	// Let's first create a Node
	Node* newNode = new Node();
	newNode->Value = newValue;
	newNode->Next = NULL;

	// Check if the Linked List is empty if so then add the newNode;
	if (*head == NULL) {
		*head = newNode;
		return;
	}

	// Now we need to find the last node;
	Node* last = *head;
	while (last->Next != NULL) {
		last = last->Next;
	}

	// After finding the last Node we can point it to the newNode;
	last->Next = newNode;

};

// Let's delete the head of the Linked List;
void deleteHead(Node*& head) {
	if (head != NULL) {
		// Create a temporary pointer to the current head node.
		Node* temp = head;

		// Update the head pointer to the next node in the list.
		head = head->Next;

		// Delete the old head.
		delete temp;
	}
}

// Delete a node at nth position;
void DeleteNth(Node*& head, int n) {
	// Check if the linked list is not empty and the position is valid (not negative).
	if (head == nullptr || n < 0) { // nullptr is the same as NULL but it's the modern C++ way and is more consistent with the language.
		cout << "Please recheck the parameters\n";
		return;
	}

	// Edge case: Delete the head node if it's the only one.
	if (n == 0) {
		Node* deletedNode = head;
		head = head->Next;
		delete deletedNode;
		return;
	}

	Node* currentNode = head;  // To track the current node.
	Node* previousNode = nullptr;  // To track the previous node.
	int position = 0;  // To track the current position.

	// Traverse the list to find the node at the nth position.
	while (currentNode != nullptr && position < n) {
		previousNode = currentNode;
		currentNode = currentNode->Next;
		position++;
	}

	// Check if the position is beyond the end of the list.
	if (currentNode == nullptr) {
		cout << "Invalid position, node not found.";
		return;
	}

	// Update the 'next' pointer of the (n-1)th node to skip the nth node.
	previousNode->Next = currentNode->Next;

	// Delete the nth node.
	delete currentNode;
}


// Let's delete the tail of the Linked List;
void DeleteTail(Node** head) {
	// Check if the linked list is empty.
	Node* current = *head;
	if (current == NULL) {
		cout << "The linked list is empty, so there's nothing to delete.";
		return;
	}

	// Create 'last' to point to the current head and 'previous' to NULL.
	Node* last = *head;
	Node* previous = NULL;

	// Check if the linked list has only one node (the head).
	if (last->Next == NULL) {
		delete last;
		*head = NULL; // Update the head to NULL as there's nothing left in the list.
		return;
	}

	// Find the last node.
	while (last->Next != NULL) {
		previous = last;
		last = last->Next;
	}

	// Update the 'next' pointer of the second-to-last node.
	previous->Next = NULL;

	// Delete the last node (not the current).
	delete last;
}

// Reverse The linked List;
void ReverseList(Node*& head){

	Node* current = head;
	Node* previous = nullptr;
	Node* nextNode = nullptr;

	while (current != nullptr) {
		nextNode = current->Next;
		current->Next = previous;
		previous = current;
		current = nextNode;
	}
	head = previous;
}



int main() {

	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();

	head->Value = 1;
	head->Next = second;

	second->Value = 2;
	second->Next = third;

	third->Value = 3;
	third->Next = NULL;


	cout << "#############\n";

	InsertingAtStart(&head, 12);
	InsertingAtEnd(&head, 99);
	InsertingAfter(head, 3333);
	DeleteTail(&head);
	
	
	Display(head); // Output: 12 -> 3333 -> 1 -> 2 -> 3 ->
	
	cout << "\n#############\n";
	DeleteNth(head, 2);
	Display(head); // Output: 12 -> 3333 -> 2 -> 3 ->
	
	cout << "\n############\n";
	ReverseList(head);
	Display(head); // Output: 3 -> 2 -> 3333 -> 12 ->
	cout << "\n#############\n";
	return 0;

	system("pause>0");
}