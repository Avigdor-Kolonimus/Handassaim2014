/***********************************************************************************\
* Name of program: "question 1"                                                     *
* By :                                                                              *
*     Name: Titov Alexey                                                            *
*     ID:   ?????????                                                               *
*     Class: 39/2                                                                   *
* Description of the program:                                                       *
*  The program consists of two arrays A and B. The A-array of numbers, B-array      *
*  indexes. The program sorts the array A through array B and prints initial array A*
*  and then it sort the array A (through array B) from smallest to largest.         *
*  O(N),N-length array (in the best case).O(N^2),N-length array (in other cases).   *
\***********************************************************************************/
#include <stdio.h>
#define N 10 //length array
void init (int A[],int B[])
{
    int i;
    printf("Enter %d numbers:\n",N);
    //entering data into the array A.
    //initialization of the array B.
    for (i=0;i<N;i++)
     {
         scanf ("%d",&A[i]);
         B[i]=i;
     }
}
void sort_arr (int A[],int B[])
{
  int i,j,k,temp;
  //sorting
  for (i=N-1;i>0;i=k)
   {
    k=0;
    for(j=0;j<i;j++)
     if (A[B[j]]>A[B[j+1]])
      {
          temp=B[j];
          B[j]=B[j+1];
          B[j+1]=temp;
          k=j;
      }
   }
}
void main (void)
{
    int A[N],B[N]; //B-sorted array.A-array of numbers no sorted.
    int i;
    init (&A,&B); //initialization procedure.
    sort_arr (&A,&B); //sorting procedure.
    //print of the array A.
    printf ("Array before sorting:\n");
    for (i=0;i<N;i++)
     printf ("%d ",A[i]);
    printf ("\nArray after sorting:\n");
    //print of the sorted array A.
    for (i=0;i<N;i++)
     printf ("%d ",A[B[i]]);
}
