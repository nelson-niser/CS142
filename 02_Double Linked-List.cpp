#include "pch.h"
#include <iostream>

using namespace std;

// Create class "Link"
class Link{
public:

	// Pre pointer
	Link * pre = NULL;
	// Data
	int data;
	// Next pointer
	Link * next = NULL;
		
};


// Linked List
class LinkedList{
public:
	// Head
	Link * head = NULL;
	// Tail
	Link * tail = NULL;

	// Insert Link at the end
	void insert(int value) {
		Link * temp = new Link;
		temp->data = value;

		// set-up head (& tail) when first Link created
		if (head == NULL) {
			head = temp;
			tail = temp;
		}

		else {
			tail->next = temp;
			temp->pre = tail;
			tail = temp;
		}
		
	}

	// Insertion of Link at a position
	void insertAt(int value, int pos) {
		Link * current = head;
		for (int i = 1; i < pos-1; i++) {
			if (current == NULL) {
				cout << "The linked-list does not have that many elements\n";
				return;
			}
			else {
				current = current->next;
			}
		}

		Link * temp = new Link;
		temp->data = value;
		if (current == head) {
			temp->next = head;
			head = temp;
		}
		else {
			temp->next = current->next;
			temp->pre = current;
			if (current->next != NULL)	current->next->pre = temp;
			current->next = temp;
		}
		
	}

	// Delete the last Link
	void del() {
		Link * temp = tail;
		tail = temp->pre;
		tail->next = NULL;
		delete temp;
	}

	// Delete at position pos
	void delAt(int pos) {
		Link * current = head;
		for (int i = 1; i < pos - 1; i++) {
			if (current == NULL) {
				cout << "The linked-list does not have that many elements\n";
				return;
			}
			else {
				current = current->next;
			}
		}
		Link * temp;
		if (current == head and pos == 1) {
			temp = head;
			if (temp->next == NULL) {
				head = NULL;
			}
			else {
				head = temp->next;
				temp->next->pre = NULL;
			}
		}
		else {
			temp = current->next;
			current->next = temp->next;
			if (temp->next != NULL)	temp->next->pre = current;
		}
		delete temp;
	}

	// count number of Link
	int count() {
		Link * current = head;
		if (head == NULL) {
			return 0;
		}
		else {
			int count = 1;
			while (current->next != NULL) {
				current = current->next;
				count++;
			}
			return count;
		}
		
	}

	// Display
	void display() {
		Link * current = head;
		while (current != NULL) {
			cout << current->data;

				// *** fancy display :-p ***
			if (current->next != NULL)	cout << " <-> ";
			else						cout << " -> ";

			current = current->next;
		}

		cout << "End\n";
	}

};

int main(){
	LinkedList l1;
	l1.insert(1);				//	1 -> End
	l1.insert(3);				// 1 <-> 3 -> End
	l1.del();					// 1 -> End
	l1.insertAt(2, 1);			// 2 <-> 1 -> End
	l1.display();
	l1.insertAt(2, 5);			//	Won't work
	l1.insertAt(2, 3);			//	2 <-> 1 <-> 2 -> End
	l1.display();
	l1.delAt(2);				//	2 <-> 2 -> End
	l1.display();
	cout << l1.count() << "\n";	// 2 Links

	return 0;
}
