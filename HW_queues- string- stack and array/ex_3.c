/***********************************************************************************\
* Name of program: "question 3"                                                     *
* By :                                                                              *
*     Name: Titov Alexey                                                            *
*     ID:   ?????????                                                               *
*     Class: 39/2                                                                   *
* Description of the program:                                                       *
*  The program gets stack in order consisting of the letters (A-Z) in which share *.*
*  The program should change the order of the letters on small letter (*SDR*->*D*). *
*  O(n), n-number of characters in s.                                               *
\***********************************************************************************/
#include <stdio.h>
#define MAX_MEMBERS 100
typedef struct
{
    char a [MAX_MEMBERS];
    int top;
}STACK;
void create(STACK *s)
{
    s->top=NULL;
}
int is_empty(STACK *s)
{
    return s->top==NULL;
}
char pop (STACK *s)
{
    return s->a[s->top--];
}
void push (STACK *s, char ch)
{
    s->a[++s->top]=ch;
}
void new_stack (char *s)
{
  char ch1,ch2; //ch1-character, ch2-character after ch1
  system("cls");
  STACK temp; //temp-stack to sort the stack s.
  create (&temp);
  ch1=pop(s);
  //sorted
  while (!is_empty(s))
   {
    ch2=pop(s);
    if (ch2=='*') //check that the order of characters ended.
     {
       push (&temp,ch1);
       push (&temp,ch2);
       ch1=pop(s);
     }
    else
      if (ch1>ch2) //check letters in alphabetical order
       ch1=ch2;
   }
  push (&temp,ch1);
  STACK help; //help- stack to transfer the data in the correct order.
  create (&help);
  //transfer
  while (!is_empty(&temp))
    push (&help,pop(&temp));
  while (!is_empty(&help))
    push (s,pop(&help));
}
void main ()
{
    char ch,ch2=NULL; //ch1-character, ch2-character after ch1
    STACK s;
    create (&s);
    //fill stack
    ch=getche();
    while (ch!=' ')
     {
       if ((ch>='A' && ch <='Z') || (ch=='*' && ch2!='*')) //check that is filled between the A-Z or *.
        push (&s,ch);
       ch2=ch;
       ch=getche();
     }
    if (!is_empty(&s)) //check that stack is not empty.
     new_stack(&s);
    printf ("\n");
    while (!is_empty(&s))
     printf ("%c",pop(&s));
}
