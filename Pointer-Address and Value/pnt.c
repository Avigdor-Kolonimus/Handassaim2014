#include <stdio.h>
void main (void)
{
    int i=9;
    char c='a';
    int *pi=NULL;
    char *pc=NULL;
    printf ("Address of i (&i): %p. Value of i (i): %d\n",&i,i);
    printf ("Address of c (&c): %p. Value of c (c): %c\n",&c,c);
    putchar ('\n');
    printf ("Address of pi (&pi): %p. Value of pi (pi): %d\n",&pi,pi);
    printf ("Address of pc (&pc): %p. Value of pc (pc): %p\n",&pc,pc);
    putchar ('\n');
    pi=&i;
    pc=&c;
    *pi=2;
    *pc='b';
    ++i;
    ++c;
    putchar ('\n');
    printf ("Address of i (&i): %p. Value of i (i): %d\n",&i,i);
    printf ("Address of c (&c): %p. Value of c (c): %c\n",&c,c);
    putchar ('\n');
    printf ("Address of pi (&pi): %p. Value of pi (pi): %d\n",&pi,pi);
    printf ("Address of pc (&pc): %p. Value of pc (pc): %c\n",&pc,pc);
    putchar ('\n');
    printf ("Address of pi (*pi): %d\n",*pi);
    printf ("Address of pc (*pc): %c\n",*pc);
}
