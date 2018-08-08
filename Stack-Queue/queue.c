#include <stdio.h>
#define MAX_MEMBERS 100
typedef struct
{
    int num;
}ITEM;
typedef struct
{
    ITEM a [MAX_MEMBERS];
    int first,last;
}QUEUE;
void create_queue(QUEUE *q)
{
    q->first=q->last=0;
}
int is_empty_queue(QUEUE *q)
{
    return q->first==q->last;
}
int is_full (QUEUE *q)
{
    return q->first==(q->last+1)%MAX_MEMBERS;
}
ITEM remove_q(QUEUE *q)
{
    ITEM x=q->a[q->first];
    q->first=(q->first+1)%MAX_MEMBERS;
    return x;
}
void add (QUEUE *q,ITEM *item)
{
    q->a[q->last]=*item;
    q->last=(q->last+1)%MAX_MEMBERS;
}
void main(void)
{
  QUEUE q;
  int choose=0;
  ITEM i;
  create_queue(&q);
    while (choose!=4)
    {
        printf ("1-is the queue empty\n"
                "2-remove\n"
                "3-add\n"
                "4-quite\n");
       scanf ("%d",&choose);
       switch (choose)
       {
           case 1: if (is_empty_queue(&q))
                    printf("The queue is empty\n");
                   else
                    printf("The queue is not empty\n");
                   break;
           case 2: i=remove_q(&q);
                   printf("Remove operation succeded num=%d\n",i.num);
                   break;
           case 3: printf("Enter number\n");
                   scanf("%d",&i.num);
                   add(&q,&i);
                   break;
           case 4: break;
           default: printf("There are no operation with this number\n");
       }
    }
}


