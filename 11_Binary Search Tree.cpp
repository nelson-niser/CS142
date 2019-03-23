#include "pch.h"
#include<iostream>

using namespace std;

class Node {
public:
	// Define 'data' and 'left','right' pointers (edges).
	int data;
	Node * left, *right, *parent;

	// Class constructor.
	Node(int value) {

		data = value;
		left = NULL;
		right = NULL;
		parent = NULL;

	}

};

class BST {
public:
	// Define root.
	Node * root;

	// Class constructor.
	BST() {
		root = NULL;
	}

	// Insert
	void insert(int value) {

		// Search the right place.
		// Case 1: Root is NULL.
		if (root == NULL) {
			// Make a Node.
			root = new Node(value);

		}
		// Case 2: Otherwise.
		else {
			// Call insertHelper
			insertHelper(root, value);
		}



	}

	// Insert helper.
	void insertHelper(Node * current, int value) {

		// Check data inequality.
		// Case 1: value < current->data.
		if (value < current->data) {
			// Check if current->left is empty or not.
			// Case 1: Empty.
			if (current->left == NULL) {
				current->left = new Node(value);
				current->left->parent = current;
				return;
			}

			// Case 2: Not empty.
			else {
				insertHelper(current->left, value);
			}

		}
		// Case 2: value >= current->data.
		else {
			// Check if current->right is empty or not.
			// Case 1: Empty.
			if (current->right == NULL) {
				current->right = new Node(value);
				current->right->parent = current;
				return;
			}

			// Case 2: Not empty.
			else {
				insertHelper(current->right, value);
			}

		}

	}

	// Display.
	void display() {
		// Case 1: Empty tree.
		if (root == NULL) {
			cout << "The tree is empty.\n";
		}

		// Case 2: Otherwise.
		else {
			displayHelper(root, 0);
		}
	}


	// DisplayHelper
	void displayHelper(Node * current, int levelCount) {
		// Case 1: current->right is NULL.
		if (current == NULL) {
			return;
		}

		// Case 2: Otherwise.
		else {
			levelCount++;
			displayHelper(current->right,levelCount);
		}

		// Print data.
		for (int i = 1; i < levelCount; i++) {
			cout << "    ";							/*************  FANCY DISPLAY **************/
		}
		cout << current->data << "|\n";
		levelCount--;

		// Case 1: current->left is NULL.
		if (current->left == NULL) {
			return;
		}

		// Case 2: Otherwise.
		else {
			levelCount++;
			displayHelper(current->left,levelCount);

		}
		levelCount--;
		return;
	}


	// Search.
	Node * search(int value) {
		return searchHelper(value, root);
	}

	Node * searchHelper(int value, Node * current) {
		if (current == NULL) {
			return current;
		}
		else if(value == current->data){
			return current;
		}

		else {

			// case 1: Value < current->data.
			if (value < current->data) {
				return searchHelper(value, current->left);
			}
			// Case 2: Value >= current->data.
			else {
				return searchHelper(value, current->right);
			}

		}
	}

	// Find minimum
	Node * findMin(int value) {
		return findMinHelper(search(value));
	}

	Node * findMinHelper(Node * current) {
		if (current->left == NULL) {
			return current;
		}
		else {
			return findMinHelper(current->left);
		}
	}

	// Count total nodes
	int count(){
		return countHelper(root, 0);
	}

	int countHelper(Node * current, int i) {
		if (current == NULL) {
			return i;
		}

		else {
			i++;

			if (current->right != NULL) {
				i = countHelper(current->right, i);
			}
			if (current->left != NULL) {
				i = countHelper(current->left, i);
			}

			return i;
		}

	}


	// Replace A with B at parent of A
	void replaceAtParent(Node * A, Node * B){
		if (A->parent->left == A) {
			A->parent->left = B;
		}
		else {
			A->parent->right = B;
		}
		delete A;
	}

	// Delete
	void del(int value) {
		delHelper(search(value));
	}

	void delHelper(Node * temp) {
		// Case 1: Have no child.
		if (temp->left == NULL and temp->right == NULL) {
			if (temp->parent->left == temp) {
				temp->parent->left = NULL;
			}
			else {
				temp->parent->right = NULL;
			}
			delete temp;
		}
		// Case 2: Have one child.
		else if (temp->left == NULL and temp->right != NULL) {
			replaceAtParent(temp, temp->right);
		}
		else if (temp->left != NULL and temp->right == NULL) {
			replaceAtParent(temp, temp->left);
		}
		// Case 3: Have two child.
		else {
			int min = findMin(temp->right->data)->data;
			del(min);
			temp->data = min;
			
		}

	}

};





int main() {

	BST b1;

	b1.insert(3);

	b1.insert(6);
	b1.insert(7);
	//b1.insert(4);
	b1.insert(1);
	b1.insert(5);
	b1.insert(2);

	b1.display();
	cout << "\n";

	for (int i = 1; i < 10; i++) {
		if (b1.search(i) != NULL) {
			cout << b1.search(i)->data << " : Search Found." << endl;
		}
		else {
			cout << "'" << i << "' " << "Not Found.\n";
		}
	}

	cout << "Count: " << b1.count() << "\n\n";
	cout <<"Min 3: " << b1.findMin(3)->data << "\n";
	cout <<"Min 6: " << b1.findMin(6)->data << "\n";
	//cout << "Min 4: " << b1.findMin(4)->data << "\n";

	b1.del(1);
	b1.del(3);

	b1.display();
	cout << "\n";

	return 0;
}