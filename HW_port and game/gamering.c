#include <stdio.h>
#include <string.h>
#define MAX 16     //maximum length of name
typedef struct node
{
    char info[MAX];
    struct node *next;
}NODE;
void init (NODE **h)
{
    *h=(NODE*) malloc (sizeof(NODE));
    if (!*h)     //check that it create  place in memory
     {
         printf ("\nNo create\n");
         return ;
     }
    (*h)->next=*h;
}
char add_first (NODE *h)
{
  char ch[MAX];
  system("cls");
  printf ("Enter name of children that play\n");
  gets(ch);
  strcpy(h->info,ch);
  printf ("Children want to play? y-yes\n");
  _flushall();
  return getche();
}
void add (NODE *h,char ch[])
{
    NODE *temp=h,*help;
    help=(NODE*) malloc (sizeof(NODE));
    if (!help)        //check that it create  place in memory
      {
         printf ("\nNo create\n");
         return ;
      }
    strcpy (help->info,ch);
    help->next=h;
    while (temp->next!=h)   //move to the last
     temp=temp->next;
    temp->next=help;
}
void out (NODE *h)
{
    NODE *temp,*help;
    if (h==h->next)    //check that one player
     {
       printf ("WINNER %s\n", h->info);
       return ;
     }
    temp=help=h;
    while (help!=help->next)    //process drop out of the game
     {
       temp=temp->next;         //second
       help->next=temp->next;
       printf ("Out %s\n",temp->info);
       free(temp);
       temp=help=help->next;    //first
     }
    printf ("WINNER %s\n", help->info);
}
void main ()
{
    NODE *game;
    char ch, str[MAX];
    printf ("Children want to play? y-yes\n");
    _flushall();
    ch=getche();
    if (ch=='y')             // check that want to play
     {
        init (&game);        //initialization
        ch=add_first(game);  //adding the first player
        while (ch=='y')      // check that want to play
         {
            system("cls");
            printf ("Enter name of children that play\n");
            gets(str);
            add (game,str);  //adding player
            printf ("Children want to play? y-yes\n");
            _flushall();
            ch=getche();
         }
       system("cls");
       printf ("Start game\n");
       out(game);            //game
       free (game);
    }
   else
    printf ("\nChildren didn't play");
}
