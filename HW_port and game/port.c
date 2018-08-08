#include <stdio.h>
#include <string.h>
#define NAME 31           //maximum permissible length of ship
#define ID 10             //the number of digits in id of ship
#define DATE 7            //length date
#define CLASS 3           //number of classes of ships
#define DAY() "080614"    //date of entry into port
typedef struct
{
    char name[NAME];
    char id[ID];
    char date[DATE];
    int visit;
}Ship;
typedef struct node
{
    Ship info;
    struct node *next;
}NODE;
typedef struct
{
    NODE *head,*fail;
}Queue;
typedef Queue array [CLASS];
void init (array a)
{
    a[0].head=a[0].fail=NULL;
    a[1].head=a[1].fail=NULL;
    a[2].head=a[2].fail=NULL;
}
/*----------------end of function init-------------------*/
int check_sort ()
{
   int i,flag;
   printf ("Enter bearing capacity of ship\n");
   flag=scanf ("%d",&i);
   while (i<=0 || !flag)         //check input
    {
       printf("No correct!\n");
       _flushall();
       flag=scanf ("%d",&i);
    }
   if (i<=10000)                //check that the first class
    return 0;
   if (i<=20000)                //check that the second class
    return 1;
   return 2;                    //the third class
}
/*----------------end of function check_sort-------------------*/
void add_ship (array a, Ship s)
{
    int i;
    i=check_sort ();
    NODE *temp;
    temp=(NODE*) malloc (sizeof(NODE));
    if (!temp)
      {
          printf ("not create ship");
          return ;
      }
    temp->info=s;
    temp->next=NULL;
    if (!a[i].head)              //check that it is not empty queue
     {
       a[i].head=temp;
       a[i].fail=temp;
     }
    else                           //entering data to the end
     {
       a[i].fail->next=temp;
       a[i].fail=temp;
     }
}
/*----------------end of function add_ship-------------------*/
NODE* unload_ship (array a,int i)
{
    NODE *temp;
    if (a[i].head)                  //check that it is not empty queue
     {
       temp=a[i].head;
       if (a[i].head==a[i].fail)    //check that first and last identical
        {
          a[i].head=NULL;
          a[i].fail=NULL;
        }
       else
        a[i].head=a[i].head->next;  //the second is the first
      return temp;
    }
   return NULL;
}
/*----------------end of function unload_ship-------------------*/
int print_first (array a,int i)
{
    int cnt=0;
    NODE *temp;
    if (!a[i].head)                //check that it is not empty queue
     {
        printf("havent\n");
        return 0;
     }
    temp=a[i].head;
    while (temp)
     {
       if (temp->info.visit)      //check that the ship for the first time
        {
           printf("Ship %s\n",temp->info.name);
           cnt++;
        }
       temp=temp->next;
     }
    return cnt;                  //sends the number of ships that first time
}
/*----------------end of function print_first-------------------*/
void input_id (char *a[ID])
{
    char ch[ID];
    int i,cnt=0;
    while (cnt!=9)                      //check that user entered 9 numbers
     {
       cnt=0;
       printf ("Enter id of ship\n");
       gets (ch);
       for (i=0;i<ID-1;i++)
         if (ch[i]>='0' && ch[i]<='9')  //count the number of digits.
          cnt++;
       if (cnt!=9)
        printf ("No correct!\n");
     }
    strcpy(a,ch);
}
/*----------------end of function input_id-------------------*/
int input_first()
{
    char ch;
    printf ("Enter if this first time of ship? y-yes\n");
    _flushall();
    ch=getche();
    printf ("\n");
    if (ch=='y')  //check the answer to question
     return 1;    //the first time
    return 0;     //not the first time
}
/*----------------end of function input_first-------------------*/
void input (array a)
{
    Ship temp;
    system("cls");
    printf ("Enter name of ship\n");
    gets (temp.name);          //Enter name for ship
    input_id (temp.id);        //Enter id for ship
    strcpy(temp.date,DAY());   //Enter arrival date "today"
    temp.visit=input_first();  //Enter first visit
    add_ship (a,temp);         //adding the ship to queue
}
/*----------------end of function input-------------------*/
void main ()
{
  array S;        //queue of ship
  init (S);
  NODE *help;
  char ch;
  int i,flag;
  printf ("If you want enter data? y-yes\n");
  _flushall();
  ch=getche();
  while (ch=='y')  //check that they want to add ship to queue
   {
     input (S);    //input data of ship
     printf ("If you want enter data? y-yes\n");
     _flushall();
     ch=getche();
   }
  printf ("\nEnter sort of ship\n");
  flag=scanf ("%d",&i);
  while (i<=0 || !flag || i>3)        //check that you have entered one of the platforms for the ship.
   {
     printf("No correct!\n");
     _flushall();
     flag=scanf ("%d",&i);
   }
  printf ("Ships that firts time in Port Haifa %d \n",print_first (S,i-1));  //task bet
  help=unload_ship (S,i-1); //task gimel
  free (help);
  free (S);
}
/* N0, O(n + k + m) where n length of the first queue, k length of the second queue and m length of  third queue.
   Add to ship number of arrival in queue (separate for each queue). Number of last minus number of first will be number of ships in the queue.*/
