#include<iostream>
using namespace std;


int partition(int arr[], int low, int high){

int pivot = high;
int i = low;

	while (i != pivot){


		if(pivot > i){
			if(arr[i] > arr[pivot]){
				int j = arr[i];
				arr[i] = arr[pivot];
				arr[pivot] = j;
				int k = pivot;				
				pivot = i;
				i = k-1;
			}
			else i++;
		}
		

		else if(pivot < i){
			if(arr[i] < arr[pivot]){
				int j = arr[i];
				arr[i] = arr[pivot];
				arr[pivot] = j;
				int k = pivot;
				pivot = i;
				i = k+1;
			}
			else i--;
		}

	}
return pivot;
}


void quickSort(int arr[], int low, int high){


	if(low < high){	// Ending condition
	
		int pivot = partition(arr, low, high);

		// Recursion
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);

	}

	
}










int main(){

	int arr[] = {2, 4, 5, 1, 3, 10, 8, 46, 53, 78 ,0, 46, 5, 0 ,0};
	int noE = sizeof(arr)/sizeof(arr[0]);

	 quickSort(arr, 0, noE - 1);


	// Diplay array
	for(int i = 0; i < noE; i++){
		cout << arr[i] << "   ";
	}
	cout << "\n";

	return 0;
}











