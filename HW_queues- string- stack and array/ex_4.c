/***********************************************************************************\
* Name of program: "question 3"                                                     *
* By :                                                                              *
*     Name: Titov Alexey                                                            *
*     ID:   ?????????                                                               *
*     Class: 39/2                                                                   *
* Description of the program:                                                       *
*  The program gets two queues of integers Q1 and Q2. The program checks that all   *
*  the numbers from the queue Q1 are also in the queue Q2.                          *
*  O(n), n-number of numbers in Q2.                                                 *
\***********************************************************************************/
#include <stdio.h>
#define N 5 //size of Q2 queue.
#define M 2 //size of Q1 queue.
#define MAX_MEMBERS 100 //maximum length of the queue.
typedef struct
{
    int a [MAX_MEMBERS];
    int first,last;
}QUEUE;
void create(QUEUE *q)
{
    q->first=q->last=0;
}
int is_empty(QUEUE *q)
{
    return q->first==q->last;
}
int remove_q(QUEUE *q)
{
    int x;
    x=q->a[q->first];
    q->first=(q->first+1)%MAX_MEMBERS;
    return x;
}
void add (QUEUE *q,int item)
{
    q->a[q->last]=item;
    q->last=(q->last+1)%MAX_MEMBERS;
}
int check (QUEUE *Q1, QUEUE *Q2)
{
    int x; //x-the number of Q1 queue.
    x=remove_q(Q1);
    //check that Q1 part Q2.
    while (!is_empty (Q2))
     if (remove_q(Q2)==x) //check that x is in Q2.
      if (is_empty (Q1))  //check that Q1 is empty.
       return 1;
      else
       x=remove_q(Q1);
   return 0;
}
void init (QUEUE *Q1, QUEUE *Q2)
{
   int i,a;
    //fill Q2 queue.
    printf ("Enter %d numbers:\n",N);
    for (i=0;i<N;i++)
     {
       scanf ("%d",&a);
       add (Q2,a);
     }
    //fill Q1 queue.
    printf ("Enter %d numbers:\n",M);
    for (i=0;i<M;i++)
     {
       scanf ("%d",&a);
       add (Q1,a);
     }
}
void main ()
{
    QUEUE Q1,Q2;
    create (&Q1);
    create (&Q2);
    init (&Q1,&Q2); //initialization procedure.
    if (check (&Q1,&Q2)) //check that Q1 part Q2.
      printf ("Yes");
    else
      printf ("No");
}
