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
/**
插入排序
	时间复杂度O(n^2) 空间复杂度O(1)
	最好情况,有序 O(n) 最差情况,逆序:比较 n/2*(n-1)  交换(n+3)*(n-2)/2
**/
void InsertionSort(int *data,int n){
	for(int i = 1; i < n; i++){
		int temp = data[i];
		int j = i;
		for( ; j > 0; j--){
			if(temp<data[j-1]){
				data[j]=data[j-1];
			}else{
				break;
			}
		}
		data[j] = temp;
	}
}

/**

**/
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
/**
希尔排序（缩小增量排序）
	平均时间复杂度O(n^1.3)
**/
// void HillSort(int *data,int n){
// 	int helpArray = [5,3,1];
// 	for(int i = 0; i < 3; i++){
// 		int increment = helpArray;
// 	}

// }
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
