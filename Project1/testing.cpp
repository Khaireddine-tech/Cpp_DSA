#include <iostream>

using namespace std;

class Node {
public:
	int Value; // holds the value of the Node;
	Node* Next; // holds the address of the next Node;
};

// PrintList function will print the value of each element in the linked list;
void PrintList(Node*n) { // first it needs to receive a node parameter
	while (n->Value != NULL) { // we need to check if the Node value is different than NULL "the last node"
		cout << n->Value << " -> "; //print out the node value
		n = n->Next; // pass n to the next node (first -> second -> third)
	}
}

// Let's insert a node as the head of the Linked List
void InsertAtTheFront(Node** head, int newValue) { 
	// since we'll need to pass the address of the head the parameter should be a pointer to a pointer
	// prepare a new node
	Node* newNode = new Node();
	newNode->Value = newValue;

	// put it in the front of the Linked List
	newNode->Next = *head;

	// Move head of the list to point to newValue
	*head = newNode;
	
};

// Let's insert a node as the end of the Linked List
void InsertAtTheEnd(Node** head, int newValue) {
	// Prepare a new Node
	Node* newNode = new Node();
	//If linked List is empty, newNode will be a head Node
	if (*head->value = NULL) {
		
	}
}


int main() {
	cout << "############\n";

	Node* head = new Node(); // here's how to create a node
	Node* second = new Node();
	Node* third = new Node();

	//and here's the structure of a node element
	head->Value = 1; // we have assigned to the head node the Value of 1;
	head->Next = second; // we have linked the head Node to the second node;

	second->Value = 2;
	second->Next = third;

	third->Value = 3;
	third->Next = NULL;

	// now let's print all the values (See function PrintList at the top)
	PrintList(head); //if we want to print all the elements we should pass head Node to it
	//Output: 1 -> 2 -> 3 ->

	// Let's insert a Node at the head
	InsertAtTheFront(&head, -1); // it needs the address of the head node and the value of the new node

	cout << "\n############\n";
	PrintList(head);
	cout << "System out";
	return 0;
}