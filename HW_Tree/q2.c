#include "Htree.h"
/*finding the smallest number*/
int min_node(Tree* t)
{
	if (!t->left)
		return t->info;
	return min_node(t->left);
}
/*removal of node*/
Tree* delete_node(Tree *t, int x)
{
	Tree *temp;
	int help;
	if (!t)
		return NULL;
	if (t->info > x)
		t->left = delete_node(t->left, x);
	else
	if (t->info < x)
		t->right = delete_node(t->right, x);
	else
	if (t->left && t->right)
	{
		help = min_node(t->right);
		t->info = help;
		t->right = delete_node(t->right, help);
	}
	else
	{
		temp = t;
		if (!t->left)
			t = t->right;
		else
		if (!t->right)
			t->left;
		free(temp);
	}
	return t;
}
/*finding the second smallest number*/
int find(Tree *t, int x)
{
	if (t->left->info == x)
		return t->info;
	else
		return find(t->left, x);
}
/*Removes the second smallest number in the tree*/
void ex2(Tree *t)
{
	int min2;
	if (!t)
		return;
	if (t->left)
	{
		min2 = min_node(t->left);
		min2 = find(t, min2);
	}
	else
		min2 = min_node(t->right);
	delete_node(t, min2);
}
void main()
{
	int num, flag;
	Tree *a;
	a = NULL;
	printf("If you want to enter the info into a tree A? 0-No, another-Yes ");
	flag = checkinfo();
	while (flag)
	{
		system("cls");
		printf("Enter number for tree: ");
		num = checkinfo();
		a = add_nodetobinarysearchtree(a, num);
		printf("If you want to enter the info into a tree A? 0-No, another-Yes ");
		flag = checkinfo();
	}
	printf("Before delete: ");
	preorder(a);
	printf("\nAfter delete: ");
	ex2(a);
	preorder(a);
	_flushall();
	if (a)
	 del(a);
	getchar();
}