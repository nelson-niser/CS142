#include "pch.h"
#include <iostream>
#include "C:\Users\Nelson Kshetrimayum\Desktop\C++\Linked-list\Linked-list\Linked-list.cpp"

class Stack {
public:
	Node * top;
	LinkedList l1;
	Stack() {
		top = l1.head;
	}

	// push
	void push(int value){
		l1.insertAt(1, value);
	}

	// pop
	void pop(){
		l1.deleteAt(1);
	}

	// isEmpty
	bool isEmpty() {
		if (top == NULL) return true;
		return false;
	}

	// size
	int size() {
		return l1.count();

	}

	// topDisplay
	void topDisplay() {

	}
	// display
	void display(){
		l1.display();
	}
};



int main()
{
	Stack s1;
	for (int i = 0; i < 6; i++) {
		s1.push(i);
	}

	s1.display();
	for (int i = 0; i < 9; i++) {
		s1.pop();
		s1.display();
	}
	

	return 0;
}
