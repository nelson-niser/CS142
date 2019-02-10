#include "pch.h"
#include <iostream>
#include "C:\Users\Nelson Kshetrimayum\Desktop\C++\Linked-list\Linked-list\Linked-list.cpp"


class queue {
public:
	Node * first;
	LinkedList l1;

	queue() {
		first = l1.head;
	}

	// enqueue
	void enqueue(int value) {
		l1.insertAt(1, value);
	}
	// dequeue
	void dequeue() {
		/*
		int i=1;
		Node * current = l1.head;
		while (current->next != l1.tail) {
			current = current->next;
			i++;
		}
		l1.deleteAt(i);
		*/
		l1.delet();
	}
	// isEmpty
	bool isEmpty() {
		if (first == NULL) return true;
		return false;
	}
	// size
	int size() {
		return l1.count();
	}
	//display
	void display() {
		l1.display();
	}



};



int main()
{
	queue q1;
	for (int i = 0; i < 5; i++) {
		q1.enqueue(i);
	}
	q1.display();
	for (int i = 0; i < 7; i++) {
		q1.dequeue();
		q1.display();
	}
	
	

	return 0;
}
