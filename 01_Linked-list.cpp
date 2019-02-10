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
		// Create a node
		Node * temp = new Node;
		temp->data = value;

		if (pos == 1) {
			if (head != NULL) {
				temp->next = head;
			}
			head = temp;
			if (tail != NULL) {
				tail = temp;
			}
		}
		else {
			for (int i = 1; i < pos - 1; i++) {
				current = current->next;
			}

			temp->next = current->next;
			current->next = temp;
		}
	}

	// Deletion
	void delet() {
		// store the tail in temp
		Node * temp = tail;
		// tail should point to NULL before deletion (eliminating connections)
		Node * current = head;
		// Empty LinkedList
		if (current == NULL) {
			cout << "Doesn't have that many Nodes \n";
			return;
		}
		// LinkedList having 1 Node
		else if (current == tail) {
			head = NULL;
			tail = NULL;
			delete current;
		}

		// Else
		else if (current != tail) {
			while (current->next != tail) {
				current = current->next;
			}
			current->next = NULL;

			// update tail
			tail = current;
			// delete temp
			delete temp;
		}

	}

	// Delete at a position
	void deleteAt(int pos){
		Node * current = head;
		if (pos==1) {
			if (head != NULL) {
				head = current->next;
				current->next = NULL;
				delete current;
			}
			else
			{
				cout << "Linked List does no have that many elements" << "\n";
			}
		}
		else {
			for (int i = 1; i < pos - 1; i++) {
				current = current->next;
			}

			if (current->next != NULL) {
				Node * deletenode = current->next;

				if (current->next->next != NULL) {
					Node * temp = current->next->next;
					current->next = temp;
				}
				else {
					current->next = NULL;
				}

				delete deletenode;
			}

			else
			{
				cout << "Linked List does no have that many elements" << "\n";
			}
		}
		
	}

	// Count
	int count() {
		Node * current = head;
		int count = 0;	/********************* Count number of Nodes ***********************/
		while (current != NULL) {
			current = current->next;
			count++;
		}
		return count;
	}
	// Display
	void display() {
		Node * current = head;

		while (current != NULL) {
			cout << current->data << "->";
			current = current->next;
		}
		cout << "NULL" << "\n" ;
		
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


	// Displaying Linked List in reverse order
	int RevDisplay(Node *current){
		if (current == NULL) {
			return 0;
		}
		else {
			RevDisplay(current->next);
			cout << current->data << "->";
			if(current == head) cout << "END\n";
			return 0;
		}
	
	}

	// Reverse the Linked List
	void revLL(Node * current, Node * pre) {
		if (current == NULL) {
			return;
		}
		else if (current->next == NULL) {
			head = current;
			current->next = pre;
			return;
		}
		else {
			revLL(current->next, current);
			current->next = pre;
			return;
		}
	}
};

/*
int main()
{
	LinkedList l1;

	l1.insert(1);	// 1->NULL
	l1.insert(2);	// 1->2->NULL
	l1.insert(4);	// 1->2->4->NULL
	l1.insert(1);	// 1->2->4->1->NULL
	l1.insert(2);	// 1->2->4->1->2->NULL
	l1.insert(4);	// 1->2->4->1->2->4->NULL
	l1.insert(1);	// 1->2->4->1->2->4->1->NULL
	l1.insert(2);	// 1->2->4->1->2->4->1->2->NULL
	l1.insert(4);	// 1->2->4->1->2->4->1->2->4->NULL

	l1.display();	// 1->2->4->1->2->4->1->2->4->NULL *********DISPLAYED**********


	l1.insertAt(3, 3);	// 1->2->3->4->1->2->4->1->2->4->NULL
	l1.delet();		// 1->2->3->4->1->2->4->1->2->NULL
	l1.deleteAt(5);	// 1->2->3->4->2->4->1->2->NULL
	l1.display();	// 1->2->3->4->2->4->1->2->NULL	*************DISPLAYED**********

	
	l1.delRepeat();	// 1->2->3->4->NULL
	l1.display();	// 1->2->3->4->NULL	*********DISPLAYED************
	l1.RevDisplay(l1.head);	//	4->3->2->1	***********DISPLAYED***********
	l1.revLL(l1.head, NULL);	// 4->3->2->1->NULL	~~~~~~~~~CONVERTED~~~~~~~~~
	l1.display();	// 4->3->2->1->NULL	*********DISPLAYED***********

	return 0;
}
*/
