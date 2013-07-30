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

void selectNode(node *HuffmanTree, int top, int *smallest, int *smaller );
int createHuffmanTree(node * HuffmanTree, char *c, int * w, int n );
void HuffmanCoding(node * HuffmanTree, char ** HuffmanCode, int n);
void HuffmanDecoding(node * HuffmanTree,char *codes,int n,int codeLength)