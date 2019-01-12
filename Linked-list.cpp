#include "pch.h"
#include <iostream>

using namespace std;

class Node {
public:
	// Data
	int data;
	// Pointer to the next Node
	Node * next;
	// Constructor that makes the pointer points to NULL ( By default)
	Node() {
		next = NULL;
	}

};

class LinkedList {
public:
	// Head
	Node * head;
	// Tail
	Node * tail;
	// Constructor for Head & Tail
	LinkedList() {
		head = NULL;
		tail = NULL;
	}

	// Circles inside linked with each other
	// Rules how circles will be linked
	// Insert
	void insert(int value){
		// If First Node is added
		Node * temp = new Node;
		
		temp->data = value;	// **** IMPORTANT **** Assign value to the data (of the new node) pointed by temp pointer

		// Insert to the LinkedList

		// For the first Node
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		// Any other node
		else {
			tail->next = temp;
			tail = temp;
		}

	}

	void insertAt(int pos, int value) {
		Node * current = head;
		for (int i = 1; i < pos-1; i++) {
			current = current->next;
		}

		// Create a node
		Node * temp = new Node;
		temp->data = value;

		temp->next = current->next;
		current->next = temp;
	}

	// Deletion
	void delet() {
		// store the tail in temp
		Node * temp = tail;
		// tail should point to NULL before deletion (eliminating connections)
		Node * current = head;
		while (current->next != tail) {
			current = current->next;
		}
		current->next = NULL;

		// update tail
		tail = current;
		// delete temp
		delete temp;

	}

	// Delete at a position
	void deleteAt(int pos){
		Node * current = head;
		for (int i = 1; i < pos-1; i++) {
			current = current->next;
		}

		if (current->next != NULL) {
			Node * deletenode = current->next;

			if (current->next->next != NULL) {
				Node * temp = current->next->next;
				current->next = temp;
			}
			else{
				current->next = NULL; 
			}
			
			delete deletenode;
		}
		
		else
		{
			cout << "Linked List does no have that many elements" << "\n";
		}
		
	}


	// Display
	void display() {
		Node * current = head;
		int count = 0;
		while (current != NULL) {
			cout << current->data << "->";
			current = current->next;
			count++;
		}
		cout << "NULL" << "\n" ;
		cout << "Numbers of nodes in the Linked List is " << count << "\n";
	}


	// Delete repeating value nodes
	void delRepeat() {
		Node * prime = head;
		int primePos = 1;
		
		while (prime != NULL) {
		
			Node * test = prime->next;
			int testPos = primePos + 1;
			
			while (test != NULL) {
			
				if (prime->data == test->data) {
					test = test->next;
					deleteAt(testPos);
				}
				
				else {
					test = test->next;
					testPos++;
				}
			}
			
			prime = prime->next;
			primePos++;
		}
	}


};

int main()
{
	LinkedList l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(4);
	l1.insert(1);
	l1.insert(2);
	l1.insert(4);
	l1.insert(1);
	l1.insert(2);
	l1.insert(4);
	l1.insertAt(3, 3);
	l1.delet();
	l1.deleteAt(5);
	l1.display();

	
	l1.delRepeat();
	l1.display();

	

	return 0;
}
