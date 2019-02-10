#include "pch.h"
#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node * next = NULL;
};


class LinkedList {
public:
	Node*head = NULL;
	Node*tail = NULL;
	
	// Insert
	void insert(int value) {
		Node*temp = new Node;
		temp->data = value;
		if (head == NULL) {
			head = temp;
			tail = temp;
			tail->next = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
			tail->next = head;
		}
	}
	// InsertAt
	void insertAt(int value, int pos) {
		Node*temp = new Node;
		temp->data = value;
		Node*current = head;
		for (int i = 1; i < pos - 1; i++) {
			if (current->next == tail) {
				cout << "The Linked-list doesn't have that many Nodes.\n";
				return;
			}
			current = current->next;
		}
		if (current == head) {
			temp->next = current;
			head = temp;
			
		}
		else {
			temp->next = current->next;
			if (current->next == head)	tail = temp;
			current->next = temp;
		}
	}
	// Delete
	void del() {
		Node*current = head;
		while (current->next != tail) {
			current = current->next;
		}
		Node*temp = tail;
		tail = current;
		current->next = head;
		temp->next = NULL;
		delete temp;
	}
	// DeleteAt
	void delAt(int pos) {
		Node * current = head;
		for (int i = 1; i < pos - 1; i++) {
			if (current->next == head) {
				cout << "Doesn't have that many Nodes.\n";
				return;
			}
			current = current->next;
		}
		Node * temp = current->next;
		current->next = temp->next;
		temp->next = NULL;
		delete temp;
	}
	// Count
	void count() {
		Node * current = head;
		int i = 1;
		while (current != tail) {
			current = current->next;
			i++;
		}
		cout << "\n The no. of Nodes is " << i << ".\n";
	}
	// Display
	void display() {
		Node * current = head;
		while (current != tail) {
			cout << current->data;
			if (current != tail)	cout << "->";
			current = current->next;
		}
		cout << current->data;
	}

};







int main(){
	LinkedList l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	
	l1.insertAt(0, 1);
	l1.insertAt(3, 3);
	l1.insertAt(6, 5);
	l1.del();
	l1.delAt(3);
	l1.delAt(9);
	l1.display();
	l1.count();
	return 0;
}
