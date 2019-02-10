#include "pch.h"
#include <iostream>

using namespace std;

class Queue {
public:



	void enqueue(int arr[], int value) {
		int i = 0;
		while (arr[i + 1] != NULL) {
			i++;
		}
		while (i >= 0) {
			if (arr[i] != NULL) {
				arr[i + 1] = arr[i];
			}
			i--;
		}

		arr[0] = value;
	}

	void dequeue(int arr[]) {
		int i = 0;
		while (arr[i + 1] != NULL) {
			i++;
		}

		// Nothing to dequeue
		if (arr[0] == NULL) {
			cout << "There's nothing to dequeue!\n";
			return;
		}

		// ******* dequeue *******
		arr[i] = NULL;

	}

	void display(int arr[]) {

		// Empty Array
		if (arr[0] == NULL) {
			cout << "The array is empty\n";
			return;
		}



		// ****** Displaying *******
		cout << "{";
		for (int i = 0; arr[i] != NULL; i++) {
			cout << arr[i];
			if (arr[i + 1] != NULL) cout << ", ";
		}
		cout << "}\n";

	}

};









int main()
{

	int arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = NULL;
	}


	Queue q1;

	q1.enqueue(arr, 3);
	q1.display(arr);
	q1.enqueue(arr, 5);
	q1.display(arr);

	q1.enqueue(arr, 9);
	q1.display(arr);
	q1.enqueue(arr, 4);
	q1.display(arr);
	q1.enqueue(arr, 7);
	q1.display(arr);



	q1.dequeue(arr);
	q1.display(arr);
	q1.dequeue(arr);
	q1.display(arr);
	q1.dequeue(arr);
	q1.display(arr);
	q1.dequeue(arr);
	q1.display(arr);
	q1.dequeue(arr);
	q1.display(arr);
	q1.dequeue(arr);
	q1.display(arr);
	q1.dequeue(arr);
	q1.display(arr);
	q1.dequeue(arr);
	q1.display(arr);

	return 0;
}
