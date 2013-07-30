#include <stdlib.h>
#include <limits.h>
void Dijkstra(int matrix[6][6], int source, int n){
	int *pre = (int *)malloc(n*sizeof(int));
	int *roadLength = (int *)malloc(n*sizeof(int));
	int *S = (int *)malloc(n*sizeof(int));
	int *T = (int *)malloc(n*sizeof(int));
	int tLength = n-1;
	int i = 0;

	for( ; i<n; i++){
		if(i == source){
			S[source] = 1;
			T[source] = 0;
			roadLength[source] = 0;
		}else{
			roadLength[i] = INT_MAX;
			T[i] =  1;
			S[i] =  0;
		}
	}
	while(tLength>0){
		int temp = INT_MAX;
		int shortest = -1;
		int j ;
		//T中的每个点到V0的最短路径
		for( i = 0; i < n; i++){
			if(T[i] == 0){
				continue;
			}else{
				for(j = 0; j<n; j++){
					if(S[j] == 0){
						continue;
					}else{
						if(roadLength[j]!=INT_MAX&&matrix[j][i]!=INT_MAX&&temp > matrix[j][i]+roadLength[j]){
							temp = matrix[j][i]+roadLength[j];
							roadLength[i] = temp;
							pre[i] = j;
						}
					}
				}
				printf("\n");
			}
		}
		temp = INT_MAX;
		//找出最短的那个
		for( i = 0; i < n; i++){
			if(T[i] == 0){
				continue;
			}else{
				if(temp>=roadLength[i]){
					temp =roadLength[i];
					shortest = i;
				}
			}
		}
		S[shortest] = 1;
		T[shortest] = 0;
		tLength--;
	}
}

int main(int argc,char *argv){
	int matrix[6][6] = {{INT_MAX, INT_MAX, 	   100,      30, INT_MAX,      10},
						{INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX,       5},
						{INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
						{INT_MAX, INT_MAX,  	60, INT_MAX,      20, INT_MAX},
						{INT_MAX, INT_MAX,  	10, INT_MAX, INT_MAX, INT_MAX},
						{INT_MAX, INT_MAX, INT_MAX, INT_MAX,      50, INT_MAX}};

	Dijkstra(matrix, 0, 6);
}