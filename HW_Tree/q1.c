#include "Htree.h"
/*Checks that the trees A AND B are similar.*/
int ex1(Tree* A, Tree* B)
{
	if (!A && !B)
		return 1;
	if ((!A && B) || (A && !B))
		return 0;
	if (A->info != B->info)
		return 0;
	return ex1(A->left, B->left) && ex1(A->right, B->right);
}
void main()
{
	int num, flag;
	Tree *a, *b;
	a = b = NULL;
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
	system("cls");
	printf("If you want to enter the info into a tree B? 0-No, another-Yes ");
	flag = checkinfo();
	while (flag)
	{
		system("cls");
		printf("Enter number for tree B: ");
		num = checkinfo();
		b = add_nodetosimpletree(b, num);
		printf("If you want to enter the info into a tree B? 0-No, another-Yes ");
		flag = checkinfo();
	}
	preorder(a);
	printf("\n");
	preorder(b);
	printf("\n");
	if (ex1(a, b))
		printf("YES\n");
	else
		printf("NO\n");
	_flushall();
	if (a)
		del(a);
	if (b)
		del(b);
	getchar();
}