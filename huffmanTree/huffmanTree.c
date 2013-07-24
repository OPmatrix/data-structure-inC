#include <stdio.h>

int MAXSIZE = 50
struct node{
	int lChild;
	int rChild;
	int parent;
	int weight;
	char ch;
} HuffmanTree[MAXSIZE*2]

int createHuffmanTree(node * HuffmanTree, char *c, int * w, int n ){
	int i = 0;
	int x,y;
	for( i = 0; i < n; i ++){
		HuffmanTree[i].weight = w[i];
		HuffmanTree[i].ch = c[i];
	}
	// initial tree node	
	for ( ; i< 2*n; i ++){
		HuffmanTree[i].rChild = 0:
		HuffmanTree[i].lChild = 0:
		HuffmanTree[i].parent = 0:
	}
	i = n;

	while ( i < 2*n ){
		select(HuffmanTree, i-1, x, y )
		HuffmanTree[x].parent = i ;
		HuffmanTree[y].parent = i ;
		HuffmanTree[i].lChild = x ;
		HuffmanTree[i].rChild = y ;
		HuffmanTree[i].weight = HuffmanTree[x].weight + HuffmanTree[x].weight;
	}

}
