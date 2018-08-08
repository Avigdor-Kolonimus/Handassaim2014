/***********************************************************************************\
* Name of program: "shelter for dogs"                                               *
* By :                                                                              *
*     Name: Sidorovich Denis                   | Titov Alexey                       *
*     ID:   ?????????                          | ?????????                          *
*     Class: 39/2                                                                   *
* Description of the program:                                                       *
*  The program gets data dogs and three tasks.The program prints name of dog which  *
* has most puppies, if there are several suchlike print them all.The program prints *
* names of all the dogs that have puppies adults as the program got(user enter year *
* older than what user want puppies ). The program prints names of all dogs born in *
* 2009 and have 10 puppies.                                                         *
\***********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MIN_YEAR 1995          //since when are dogs.
#define NAME_D 21              //length of name dog.
#define MAX 41                 //maximum number of pups.
#define MAX_D 21                //maximum number of dogs.
#define criterion_p 10          //criterion for the question F.
#define criterion_y 2009       //criterion for the question F.
typedef struct                 //struct of date of birth
{
    int day;
    int month;
    int year;
}born;
typedef born* arra2[MAX];
typedef struct                 //struct of data dogs.
{
   char name[NAME_D];
   born dmy;
   int cnt;
   arra2 pup;
}dog;
typedef dog arra [MAX_D];
int day (int num)
{
  switch (num)
  {
    case 2:
           printf ("day birth\n");
           scanf("%d",&num);
           while (num<0 || num>29)         //check that there is a day in the month.
            {
             printf ("No correct\n");
             scanf("%d",&num);
            }
           break;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
             printf ("day birth\n");
             scanf("%d",&num);
             while (num<0 || num>31)          //check that there is a day in the month.
              {
               printf ("No correct\n");
               scanf("%d",&num);
              }
             break;
    default:
             printf ("day birth\n");
             scanf("%d",&num);
             while (num<0 || num>30)          //check that there is a day in the month.
              {
               printf ("No correct\n");
               scanf("%d",&num);
              }
             break;
  }
 return num;
}
/*----------------end of function day-------------------*/
int month ()
{
    int a;
    printf("month of birth\n");
    scanf ("%d",&a);
    while (a>12 || a<0)          //check that there is a month.
     {
        printf("No correct\n");
        scanf("%d",&a);
     }
    return a;
}
/*----------------end of function month-------------------*/
int year (int num)
{
  int a;
  printf ("Year birth\n");
  scanf ("%d",&a);
  while (num>a || a>2014)       //check year of birth.
   {
     printf ("No correct\n");
     scanf ("%d",&a);
   }
  return a;
}
/*----------------end of function year-------------------*/
int pup ()
{
    int a;
    system("cls");
    printf("the number of puppies\n");
    scanf ("%d",&a);
    while (a>MAX || a<0)          //check that you have entered the right amount of puppies.
     {
        printf("No correct\n");
        scanf("%d",&a);
     }
    return a;
}
/*----------------end of function pup-------------------*/
int searchM (arra A)
{
    int i,max=0;
    for (i=0;i<MAX_D;i++)
      if (max<A[i].cnt)      //check a large number of puppies.
       max=A[i].cnt;
    return max;
}
/*----------------end of function searchM-------------------*/
void searchfemale(arra A)
{
    int i,max;
    max=searchM (A);                            //search a large number of puppies.
    printf("most puppies:\n");
    for (i=0;i<MAX_D;i++)
     if (max==A[i].cnt)                        //finding the right dog.
       printf("The dog %s\n",A[i].name);
    printf("\n\n");
}
/*----------------end of function searchfemale-------------------*/
void ex_E (arra A,int yr)
{
    int i,j;
    for (i=0;i<MAX_D;i++)
     for (j=0;j<A[i].cnt;j++)
      if (yr>A[i].pup[j]->year)                    //check whether the entered dog puppy over year.
       {
         printf("The dog %s has\n",A[i].name);
         j=A[i].cnt;
       }
}
/*----------------end of function ex_E-------------------*/
void ex_F (arra A)
{
    int i;
    printf("\n");
    for (i=0;i<MAX_D;i++)
      if (A[i].dmy.year==criterion_y && A[i].cnt==criterion_p)  //check criteria for dogs.
       printf("The dog %s meets the criteria\n",A[i].name);
}
/*----------------end of function ex_F-------------------*/
void Input (arra A)
{
  int i,j;
  for (i=0;i<MAX_D;i++)                              //complete data dogs.
   {
    printf ("Enter dog's name\n");
    _flushall();
    gets(A[i].name);
    A[i].dmy.month=month();
    A[i].dmy.day=day(A[i].dmy.month);
    A[i].dmy.year=year(MIN_YEAR);
    A[i].cnt=pup();
    system("cls");
    for (j=0;j<A[i].cnt;j++)                       //complete data puppies.
     {
      A[i].pup[j]=(born*) malloc (1*sizeof(born));
      if (!A[i].pup)
       exit(1);
      A[i].pup[j]->month=month();
      A[i].pup[j]->day=day(A[i].pup[j]->month);
      A[i].pup[j]->year=year(A[i].dmy.year);
      system("cls");
     }
   }
}
/*----------------end of function Input-------------------*/
void main ()
{
    arra A;                            //array of data dogs.
    int i,j;                           //variables for assistance.
    Input (A);                         //procedure for entering data.
    system("cls");
    searchfemale(A);                   //procedure to find dog with most pups.
    printf ("Enter year older than what you want puppies\n");
    scanf("%d",&i);
    ex_E (A,i);
    ex_F (A);
    for (i=0;i<MAX_D;i++)             //printing data dog.
     {
       printf("\nname %s\n",A[i].name);
       printf("date of birth %d/%d/%d\n",A[i].dmy.day,A[i].dmy.month,A[i].dmy.year);
       printf("the number of puppies %d\n",A[i].cnt);
       for (j=0;j<A[i].cnt;j++)       //printing data puppy of the dog.
         printf ("puppies %d: %d/%d/%d\n",j+1, A[i].pup[j]->day, A[i].pup[j]->month, A[i].pup[j]->year);
     }
    for (i=MAX_D-1;i>=0;i--)          //free of dynamic memory.
     free (A[i].pup);
}
/*----------------end of main-------------------*/

