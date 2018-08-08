#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int info;
	struct node *left, *right;
}Tree;
/*Add new node to the simple tree*/
Tree* add_nodetosimpletree(Tree *t, int x);
/*Add new node to the binary search tree*/
Tree* add_nodetobinarysearchtree(Tree *t, int x);
/*Print all tree nodes*/
void preorder(Tree *t);
/*Free all tree*/
void del(Tree *t);
/*check that user have entered the number of */
int checkinfo();