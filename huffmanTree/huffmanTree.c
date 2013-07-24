#include <stdio.h>
#include <stdlib.h>

int MAXSIZE = 50;
typedef struct {
	int lChild;
	int rChild;
	int parent;
	int weight;
	char ch;
} node;

void selectNode(node *HuffmanTree, int top, int *smallest, int *smaller ){
	int i = 0;
	*smallest = -1;
	*smaller = -1;
	for(; i<= top; i ++){	
		if(HuffmanTree[i].parent!=-1){
			continue;
		}		
		if(*smallest ==  -1){
			*smallest = i;
			continue;
		}	
		if(*smaller == -1){
			if(HuffmanTree[i].weight >= HuffmanTree[*smallest].weight){
				*smaller = i;
			}else{
				*smaller = *smallest;
				*smallest = i;
			}
			continue;
		}
		if(HuffmanTree[i].weight >= HuffmanTree[*smaller].weight){
			continue;
		}

		if (HuffmanTree[i].weight > HuffmanTree[*smallest].weight){
			*smaller = i;
		}else{
			*smaller = *smallest;
			*smallest = i;
		}
	}
}

int createHuffmanTree(node * HuffmanTree, char *c, int * w, int n ){
	
	if(n>MAXSIZE){
		 		return 0;
	}
	int i = 0;
	for( i = 0; i < n; i ++){
		HuffmanTree[i].weight = w[i];
		HuffmanTree[i].ch = c[i];
		HuffmanTree[i].parent = -1;
	}
	// initial tree node	
	for ( ; i< 2*n-1; i ++){
		HuffmanTree[i].rChild = 0;
		HuffmanTree[i].lChild = 0;
		HuffmanTree[i].parent = -1;
	}
	printf("\n");
	i = n;
	int x,y;
	while ( i < 2*n-1 ){
		selectNode(HuffmanTree, i-1, &x, &y );
		HuffmanTree[x].parent = i ;
		HuffmanTree[y].parent = i ;
		HuffmanTree[i].lChild = x ;
		HuffmanTree[i].rChild = y ;
		HuffmanTree[i].weight = HuffmanTree[x].weight + HuffmanTree[y].weight;
		i++;
	}
	for (i=0 ; i< 2*n-1; i ++){
		printf("%d ",HuffmanTree[i].weight);
	}
	return 1;
}


int main(){
	char c[9] = {'a','b','c','d','e','f','g','h','i'};
	int w[9] = {1,2,3,4,5,6,7,8,9};
	int n = 9;
	int i = 0;
	node * HuffmanTree;
	HuffmanTree = (node *)malloc((n*2-1)*sizeof(node));
	createHuffmanTree(HuffmanTree, c, w, 9);
	return 0;
} 