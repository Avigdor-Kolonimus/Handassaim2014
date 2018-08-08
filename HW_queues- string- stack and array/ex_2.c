/***********************************************************************************\
* Name of program: "question 2"                                                     *
* By :                                                                              *
*     Name: Titov Alexey                                                            *
*     ID:   ?????????                                                               *
*     Class: 39/2                                                                   *
* Description of the program:                                                       *
*  The program checks whether the string special. Special string is string starting *
*  with a and ending b. The amount b is more than twice the amount of a.            *
*  O(n), n-length string.                                                           *
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
void NOget ()
{
    char ch;
    ch=getche();
    while (ch!=' ')
     ch=getche();
    printf ("\nNormal string");
}
void unusual_string ()
{
    char ch;
    STACK s; // s-stack of string.
    create (&s);
    ch=getche();
    if (ch==' ') //check that user entered a character.
     printf ("\nUnusal string");
    else
      if (ch!='a') //check that the first letter a.
       NOget ();
      else
       {
         //fill stack s
         while (ch=='a')
          {
             push(&s,ch);
             ch=getche();
          }
         if (ch=='b')  //check that the letter b.
          {
            while (ch=='b')
             {
              ch=getche();
              if (ch=='b')
               {
                 ch=getche();
                 if (!is_empty(&s))
                   pop(&s);
                 else
                  {
                    NOget ();
                    return ;
                  }
               }
             }
            if (ch==' ')
             printf ("\nUnusal string");
            else
             NOget ();
          }
         else
          NOget ();
      }
}
void main ()
{
    unusual_string(); //check that a string is unusual.
}

