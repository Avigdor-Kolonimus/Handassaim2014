#include <stdio.h>
#include <string.h>
unsigned int fibch(unsigned int n)
{
    if (n<2)
     return n;
    else
     return fibch(n-1)+fibch(n-2);
}
int sum_array (int a[],int n)
{
    if (n==1)
     return a[0];
    else
     return sum_array(a,n-1)+a[n-1];
}
int occur(char *s,char c)
{
  if (*s=='\0')
   return 0;
  else
    if (*s==c)
     return occur (++s,c)+1;
    else
     return occur (++s,c);
}
void reverse (int a[],int n)
{
    if (n/2==0 && n%2==1)
     {

        return  ;
     }
    else
     {
       a[0]+=a[n-1];
       a[n-1]=a[0]-a[n-1];
       a[0]=a[0]-a[n-1];
       return reverse (++a,--n);
     }
}
void main ()
{
    system("cls");
    unsigned int a;
    scanf ("%d",&a);
    a=fibch(a);
    printf ("\nfibonacci=%d",a);
    int b[]={1,2,3,4};
    printf ("\nSum array= %d",sum_array(b,4));
    char str[]={"Hello world"};
    char ch='o';
    printf ("\nNumber o in Hello world %d",occur(&str,ch));
    reverse (b,4);
    for (a=0;a<4;a++)
     printf ("\n%d ",b[a]);
}
