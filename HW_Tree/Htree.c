#include "Htree.h"
/*Add new node to the simple tree*/
Tree* add_nodetosimpletree(Tree *t, int x)
{
	int c;
	if (!t)  //Create node if node is empty
	{
		t = (Tree*)malloc(sizeof(Tree));
		if (!t)
			return NULL;
		t->info = x;
		t->right = t->left = NULL;
		return t;
	}
	//Getting to know which way to go
	printf("1-left,other-right\n");
	scanf("%d", &c);
	if (c == 1)
		t->left = add_nodetosimpletree(t->left, x);
	else
		t->right = add_nodetosimpletree(t->right, x);
	return t;
}
/*Add new node to the binary search tree*/
Tree* add_nodetobinarysearchtree(Tree *t, int x)
{
	if (!t)   //Create node if node is empty
	{
		t = (Tree*)malloc(sizeof(Tree));
		if (!t)
			return NULL;
		t->info = x;
		t->right = t->left = NULL;
		return t;
	}
	//Getting to know which way to go
	if (x<t->info)
		t->left = add_nodetobinarysearchtree(t->left, x);
	else
		t->right = add_nodetobinarysearchtree(t->right, x);
	return t;
}
/*Print all tree nodes*/
void preorder(Tree *t)
{
	if (!t)
		return;
	printf("%d ", t->info);
	preorder(t->left);
	preorder(t->right);
}
/*Free all tree*/
void del(Tree *t)
{
	if (!t->left && !t->right)
		return free(t);
	if (!t->left)
		return del(t->right);
	return del(t->left);
}
/*check that user have entered the number of */
int checkinfo()
{
	int num, flag;
	flag = scanf("%d", &num);
	while (flag==0)
	{
		printf("Err,enter new number: ");
		_flushall();
		flag = scanf("%d", &num);
	}
	return num;
}