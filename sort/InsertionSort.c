/**
* author OPmatrix
* Insertion Sort
**/
#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void InsertionSort(int *data,int n){
	for(int i = 1; i < n; i++){
		for(int j = i; j > 0; j--){
			if(data[j]<data[j-1]){
				printf("%d\n",j);
				swap(&data[j],&data[j-1]);
			}
		}
	}
}

int main(){
	int data[11] = {3,5,95,56,8,5,1,8,5,3,3};
	InsertionSort(data,11);
	for(int i = 0; i < 11; i++){
		printf("%d ", data[i]);
	}
	printf("\n");
}
