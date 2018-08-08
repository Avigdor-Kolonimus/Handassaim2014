#include "Htree.h"
/*Makes mirror tree*/
Tree* ex3(Tree* t, Tree* m)
{
	if (!t)
		return NULL;
	m = (Tree*)malloc(sizeof(Tree));
	if (!m)
		return NULL;
	m->info = t->info;
	m->left = ex3(t->right, m->left);
	m->right = ex3(t->left, m->right);
	return m;
}
void main()
{
	int num, flag;
	Tree *a, *mirror;
	a = mirror = NULL;
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
	printf("Tree A: ");
	preorder(a);
	printf("\nTree mirror: ");
	mirror = ex3(a, mirror);
	preorder(mirror);
	_flushall();
	if (a)
		del(a);
	if (mirror)
		del(mirror);
	getchar();
}