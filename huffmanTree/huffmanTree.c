#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		HuffmanTree[i].rChild = -1;
		HuffmanTree[i].lChild = -1;
	}
	// initial tree node	
	for ( ; i< 2*n-1; i ++){
		HuffmanTree[i].rChild = -1;
		HuffmanTree[i].lChild = -1;
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
	
	return 1;
}

void HuffmanCoding(node * HuffmanTree, char ** HuffmanCode, int n){
	char * temp = (char *)malloc(n* sizeof(char));

	temp[n-1] = '\0';//termianl char
	int i = 0;
	printf("\n");
	for( ; i<n ; i++){
		int j = i;
		int start = n-2;

		while(HuffmanTree[j].parent!=-1){
			int p ;
			p =  HuffmanTree[j].parent;
			if(HuffmanTree[p].lChild==j){
				temp[start] = '0';
			}else{
				temp[start] = '1';
			}
			
			start --;
			j = p;			
		}
		HuffmanCode[i] = malloc((n-start-2)*sizeof(char));
		strcpy(HuffmanCode[i],&temp[start+1]);
	}
	
}

void HuffmanDecoding(node * HuffmanTree,char *codes,int n,int codeLength){
	int i = 0;
	int nodeIndex =2*n-2;
	for(i = 0; i< codeLength; i++){
		char code = codes[i];
		if(HuffmanTree[nodeIndex].lChild==-1){
			printf("%c",HuffmanTree[nodeIndex].ch);
			nodeIndex = 2*n-2;
		}
		if(code=='1'){
			nodeIndex = HuffmanTree[nodeIndex].rChild;
		}else{
			nodeIndex = HuffmanTree[nodeIndex].lChild;
		}
	}
}
int main(){
	char c[9] = {'a','b','c','d','e','f','g','h','i'};
	int w[9] = {1,2,3,4,5,6,7,8,9};
	int n = 9;
	int i = 0;
	node * HuffmanTree;
	HuffmanTree = (node *)malloc((n*2-1)*sizeof(node));
	createHuffmanTree(HuffmanTree, c, w, 9);
	char **HuffmanCode;
	HuffmanCode = (char **)malloc(n*sizeof(char *));
	HuffmanCoding(HuffmanTree, HuffmanCode, 9);
	for( ; i<n ; i++){
		printf("%s\n",HuffmanCode[i] );
	}
	char encodeText[27] = "10000100001001100011000100";
	HuffmanDecoding(HuffmanTree,encodeText,n,26);
	printf("\n");
	return 0;
} 


