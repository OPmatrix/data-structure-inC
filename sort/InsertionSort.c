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
				swap(&data[j],&data[j-1]);
			}
		}
	}
}

void BubbbleSort(int *data,int n){
	for(int i = n-1 ; i > 0; i--){
		int goFlag = 1;
		for(int j = 0; j < i ;j++){
			if(data[j]>data[j+1]){
				goFlag = 0;
				swap(&data[j],&data[j+1]);	
			}
		}
		if(goFlag==1){
			break;
		}
	}
}

void testSort(void Sort(int *,int),int *data,int n){
	
	Sort(data,n);
	for(int i = 0; i < n; i++){
		printf("%d ", data[i]);
	}
	printf("\n");
}

int main(){
	int insertionData[11] = {3,5,95,56,8,5,1,8,5,3,3};
	
	testSort(InsertionSort,insertionData,11);

	int ordered[11] = {1,3,3,3,5,5,5,8,8,56,95};
	testSort(BubbbleSort,ordered,11);

	int bubbleData[11] = {3,5,95,56,8,5,1,8,5,3,3};
	testSort(BubbbleSort,bubbleData,11);
}
