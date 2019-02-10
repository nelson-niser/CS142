#include "pch.h"
#include <iostream>

using namespace std;

class Stack {
public:
	
	

	void push(int arr[], int value) {
		int i = 0;
		while (arr[i + 1] != NULL) {
			i++;
		}
		while (i >= 0) {
			if (arr[i] != NULL) {
				arr[i+1] = arr[i];
			}
			i--;
		}
		
		arr[0] = value;
	}

	void pop(int arr[]) {
		int i = 0;
		
		// Nothing to pop
		if (arr[0] == NULL) {
			cout << "There's nothing to pop!\n";
			return;
		}

		// ******* poping *******
		while(arr[i + 1] != NULL) {
			arr[i] = arr[i + 1];
			i++;
		}
		if (arr[i + 1] == NULL) {
			arr[i] = NULL;
		}
    

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
			if(arr[i + 1] != NULL) cout << ", ";
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


	Stack s1;

	s1.push(arr, 3);
							s1.display(arr);
	s1.push(arr, 5);
							s1.display(arr);
							
	s1.push(arr, 9);
							s1.display(arr);
	s1.push(arr, 4);
							s1.display(arr);
	s1.push(arr, 7);
							s1.display(arr);



	s1.pop(arr);
							s1.display(arr);
	s1.pop(arr);
							s1.display(arr);
	s1.pop(arr);
							s1.display(arr);
	s1.pop(arr);
							s1.display(arr);
	s1.pop(arr);
							s1.display(arr);
	s1.pop(arr);
							s1.display(arr);
	s1.pop(arr);
							s1.display(arr);
	s1.pop(arr);
							s1.display(arr);
							
	return 0;
}
