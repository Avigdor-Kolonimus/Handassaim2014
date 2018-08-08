/***********************************************************************************\
* Name of program: "Cinema"                                                         *
* By :                                                                              *
*     Name: SIDOROVICH DENIS                   | Titov Alexey                       *
*     ID:   ?????????                          | ?????????                          *
*     Class: 39/2                                                                   *
* Description of the program:                                                       *
*  The program handle assigning seats in a movie theater. The hall is built in      *
* rectangular: it contains M rows and N seats. When a customer wants to purchase    *
* movie tickets, the program finds for the vacant seats best. The best places are   *
* located in the ranks of the central hall, each line instead of using the line     *
* better than others. Therefore, as you move away in the center row, narrated places*
* less better. Program which will be managed by the action menu action will ask what*
* the next action (purchasing tickets or printing a list).                          *
* Computational operations:                                                         *
* 1. O (M*N);                                                                       *
* 2. O (cnt*M*N);                                                                   *
\***********************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define M 7   //Rows.
#define N 9   //Seats.
#define X 10  //string maximum length (as required).
#define MAX 5 //maximum opportunity to book seats (as required).
typedef struct
{
    char name[X]; //name of customer
    int number;   //number of order
}List_customer;

int Seat_customer (char ch[X]) //The function determines the number of seats are ordered.
{
 int cnt=0,i;
 /* --------------------- */
 for (i=0;i<X;i++)
  if ((ch[i]>='0')&& (ch[i]<='9'))  //check what number is contained in string.
   cnt=ch[i]-'0'+cnt*10;
 return cnt; //returns the number of are ordered seats.
}  /* -----  end of function Seat_customer  ----- */

void List(List_customer a[],char ch[X],int flag) //The function sorts the list by A-Z.
 {
   char temp[X];
   int i,temp_n1,temp_n2=flag;
/* --------------------- */
   for (i=0;i<flag;i++)
    {
      if (i==(flag-1)) //check this place empty list.
       {
        strcpy(a[i].name,ch);
        a[i].number=temp_n2;
       }
      else
       if (strcmp(ch,a[i].name)<0) //checks by abc where permission to shove string.
        {
         strcpy(temp,a[i].name);
         temp_n1=a[i].number;
         strcpy(a[i].name,ch);
         a[i].number=temp_n2;
         strcpy(ch,temp);
         temp_n2=temp_n1;
        }
    }
 }  /* -----  end of function List  ----- */

 void map ( int th[][N]) //The function prints map. X-employed, O-free.
{
	int i,j;
/* --------------------- */
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			th[i][j]?putchar('X'):putchar('O');
		}
		putchar('\n');
	}
	return ;
}		/* -----  end of function map  ----- */

void init ( int th[][N] ) //The function initializes array to '0'
{
	int i,j;
/* ---------------------- */
	for(i=0; i<M; i++)
		for(j=0; j<N; j++)
			th[i][j]=0;
	return ;
}		/* -----  end of function init  ----- */

int is_full ( int array[][N], int Ln ) //The function ckecks if line is full
{
	int i;
	int flag=0;
/* -------------------- */
	for(i=0; i<N; i++)
		flag=!array[Ln][i]?1:flag;
	return flag;
}		/* -----  end of function is_full  ----- */

int is_empty ( int array[][N], int Ln ) //The function ckecks  if line is empty.
{
	int i;
	int flag=1;
/* -------------------------- */
	for (i=0; i<N; i++)
		flag=array[Ln][i]?0:flag;
	return flag;
}		/* -----  end of function is_empty  ----- */

int empty_seats ( int array[][N], int Ln )////The function returns count of empty seats in line.
{
	int i;
	int count=0;
/* ---------------------- */
	for(i=0; i<N; i++)
		!array[Ln][i]?count++:1;
	return count;
}		/* -----  end of function empty_seats  ----- */

int jump ( int *num, int pos ) //the function needed for jumping
{
	*num+=pos%2?-pos:pos; // jump from center to both left and right sides
	return *num;
}		/* -----  end of function jump  ----- */

int cntr_l ( int axis ) //Length of center (can replace cntr_xp / cntr_yp)
{
	int tmp=axis/2;
	int rslt;
/* ------------------------ */
	if(axis%2)
		return tmp + !(tmp%2); // (length/2 +!((length/2)%2)
	return tmp - tmp%2;
}		/* -----  end of function cntr_l  ----- */

int fill ( int array[][N], int Ln , int pos, int count, int cnt_customer) //Fills number of seats from selected position
{
	int i;
/* ----------------- */
	for(i=0; i<count; i++, jump(&pos, i))
		if(array[Ln][pos]==0 && pos < N && pos >= 0)
			array[Ln][pos]=cnt_customer;
		else return count-i;
	return count-i;
}		/* -----  end of function fill  ----- */

int filler ( int array[][N], int count, int cnt_customer) //Fills line by line empty seats from middle
{
	int i,j;
	int yaxis, xaxis;
/* ----------------------------- */
	yaxis=M/2+!M%2;
	xaxis=N/2+!N%2;
	for(i=0; i<M && count>0; jump(&yaxis,i+1), i++)
	{
		for(j=yaxis; j<N && count>0; j++)
		{
			if(array[yaxis][j] == 0) { array[yaxis][j] = cnt_customer; count--;} //fill to the right
		}

		for(j=yaxis; j>=0 && count>0; j--)
		{
			if(array[yaxis][j] == 0) { array[yaxis][j] = cnt_customer; count--;} //fill to the left
		}
	}
	return count;
}		/* -----  end of function filler  ----- */

void sell ( int array[][N], int count, int cnt_customer) //Main sorting function
{
	int i,j;
	int yaxis, xaxis;
	int tmp=0;
/* -------------------------------- */
	yaxis=M/2+!M%2;
	xaxis=N/2+!N%2;

	for(i=0; i<M && count>0; jump(&yaxis,i+1), i++) //Jump on lines
	{
		if(is_empty ( array, yaxis ))
		{
			count = fill(array, yaxis, xaxis, count,cnt_customer); // Jumping by rows is in "fill" function
		}
	}
	if(count>0) //If all best seats are not empty find less good seats
		count = filler(array, count,cnt_customer); //calling to filler function
}		/* -----  end of function sell  ----- */
void Print_List (List_customer a[],int hall[][N],int cnt) //the function prints list by A-Z
{
  int i,m,n;
  /* -------------------------------- */
  printf ("List of customers:\n");
  for (i=0;i<cnt;i++)
   {
     printf ("%s:",a[i].name);
     for (m=0;m<M;m++)
      for (n=0;n<N;n++)
       if (hall[m][n]==a[i].number) //check if the seat belongs to the customer.
        printf (" Row %d seat %d",m+1,n+1);
     printf ("\n");
   }
} /* -----  end of function Print_List  ----- */

void Print_menu1 () // menu
{
  printf ("  ************************************** \n");
  printf ("  * 1.Buying ticket(-s)                *\n");
  printf ("  * 2.Print list                       *\n");
  printf ("  **************************************\n");
} /* -----  end of function Print_menu1  ----- */

void Print_menu2 () //menu
{
  printf ("  ************************************** \n");
  printf ("  * 1.Print map of hall                *\n");
  printf ("  * 2.Print list                       *\n");
  printf ("  * 3.Print list and map               *\n");
  printf ("  **************************************\n");
} /* -----  end of function Print_menu2  ----- */

int check_input (char name[X],int *flag) //The function checks what entering
{
  int seat,temp=1;
  char ch_end[]="THE END";
/* -------------------------------- */
  system("cls");
  while (temp) //check that the user has entered the correct data.
   {
    gets(name);
    seat=Seat_customer (name);
    switch (seat)
     {
      case 0:
             if (strcmp(ch_end,name)==0) //checks user entered THE END (subject).
              return -1;
             else
              printf ("can't be ordered 0 seats \n");
             break;
      default:
              if ((seat<=*flag)&&(seat<=MAX)) //check that the user has entered the correct data.
               {
                *flag-=seat;
                return seat;
               }
              if (seat>*flag) //check that user entered not more seats available.
               {
                printf ("Not enough seats\n");
                break;
               }
              if (seat>MAX) //check that user have entered at least five locations (as required)
               printf ("Entered more than 5\n");
     }
   }
} /* -----  end of function check_input  ----- */

void main (void)
{
   fflush(stdin);
   char name_customer[X];
   List_customer list_data[M*N];
   int flag=M*N,seat=0,cnt_customer=0,i;
   int Theat[M][N];
/* --------------------- */
   init(Theat);
   while ((flag!=0)&&(seat!=-1)) //checks have seats available or user entered THE END (subject).
    {
      Print_menu1();
      switch (getche())
        {
         case '1':
                  seat=check_input (&name_customer,&flag);
                  if (seat>0) //check
                   {
                     cnt_customer++;
                     sell(Theat,seat,cnt_customer);
                     map(Theat); //prints the map hall (task number 1).
                     List(&list_data,name_customer,cnt_customer);
                     printf ("Vacant seats: %d\n",flag); //part task number 1.
                   }
                   break;
         case '2':
                  system("cls");
                  Print_List(list_data,Theat,cnt_customer);
                  break;
         default:
                  system("cls");
                  printf("invalid command \n");
        }
    }
   system("cls");
   if (flag==0) //checks filled the hall. Part task number 1.
    printf ("Theatre is full\n");
   Print_menu2 ();
   switch (getche())
        {
         case '1':
                  system("cls");
                  map(Theat); //prints the map hall (task number 1).
                  break;
         case '2':
                  system("cls");
                  Print_List(list_data,Theat,cnt_customer);  //Task number 2.
                  break;
         case '3':
                  system("cls");
                  map(Theat); //prints the map hall (task number 1).
                  Print_List(list_data,Theat,cnt_customer);  //Task number 2.
                  break;
         default:
                  system("cls");
                  printf("invalid command \n");
        }
}
