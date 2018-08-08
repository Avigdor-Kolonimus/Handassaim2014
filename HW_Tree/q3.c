#include "Htree.h"
/*Change the value of nodes, the sum of their direct children*/
void ex3(Tree *t)
{
	int l, r;
	l = r = 0;
	if (!t || (!t->left && !t->right))
		return;
	if (t->left)
		l = t->left->info;
	if (t->right)
		r = t->right->info;
	t->info = l + r;
	ex3(t->left);
	ex3(t->right);
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
		printf("Enter number for tree A: ");
		num = checkinfo();
		a = add_nodetosimpletree(a, num);
		printf("If you want to enter the info into a tree A? 0-No, another-Yes ");
		flag = checkinfo();
	}
	printf("Before: ");
	preorder(a);
	ex3(a);
	printf("\nAfter: ");
	preorder(a);
	_flushall();
	if (a)
		del(a);
	getchar();
}