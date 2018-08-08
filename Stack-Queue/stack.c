#include <stdio.h>
#define MAX_MEMBERS 100
typedef struct
{
    int num;
}ITEM;
typedef struct
{
    ITEM a [MAX_MEMBERS];
    int top;
}STACK;
void create_stack(STACK *s)
{
    s->top=-1;
}
int is_empty_stack(STACK *s)
{
    return s->top==-1;
}
int is_full (STACK *s)
{
    return s->top==MAX_MEMBERS-1;
}
ITEM pop (STACK *s)
{
    return s->a[s->top--];
}
void push (STACK *s, ITEM *item)
{
    s->a[++s->top]=*item;
}
ITEM top (STACK *s)
{
    return s->a[s->top];
}
void main (void)
{
    STACK s;
    int choose=0;
    ITEM i;
    create_stack(&s);
    while (choose!=5)
    {
        printf ("1-is the stack empty&\n"
                "2-pop\n"
                "3-push\n"
                "4-top\n"
                "5-quite\n");
       scanf ("%d",&choose);
       switch (choose)
       {
           case 1: if (is_empty_stack(&s))
                    printf("The stack is empty\n");
                   else
                    printf("The stack is not empty\n");
                   break;
           case 2: i=pop(&s);
                   printf("Pop operation succeded num=%d\n",i.num);
                   break;
           case 3: printf("Enter number\n");
                   scanf("%d",&i.num);
                   push(&s,&i);
                   break;
           case 4: i=top(&s);
                   printf("Pop operation succeded num=%d\n",i.num);
                   break;
          case 5: break;
          default: printf("There are no operation with this number\n");
       }
    }
}
