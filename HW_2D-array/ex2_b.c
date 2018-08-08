/***********************************************************************************\
* Name of program: "question 4"                                                     *
* By :                                                                              *
*     Name: SIDOROVICH DENIS                   | Titov Alexey                       *
*     ID:   ?????????                          | ?????????                          *
*     Class: 39/2                                                                   *
* Description of the program:                                                       *
*  The program creates an array of 4x4, filling it with integers numbers. After, he *
* sorts the array in ascending order, where a smallest number will be 0,0  and a    *
* highest number 3,3. The program prints a matrix array. Where the distance between *
* the numbers is equal to the number of properties in the largest number plus 1.    *
\***********************************************************************************/
#include <stdlib.h>
#define M 4 //size of the array according to the requirements of the question.
void Sort (int a[][M]) ////The procedure that sorts the array. a-is not sorted array.
{
    int i,j,k,temp; //i,k and j-variables to run through the array, temp-variable to store the number.
    int *ptr;       //*ptr-pointer to the array.
    ptr=a;
    //Sorting.
    for (i=M*M-1;i>0;i=k)
     {
       k=0;
       ptr=a;
       for (j=0;j<i;j++,ptr++)
         if (*ptr>*(ptr+1)) //comparing the current number with the following number.
          {
            //interchanged.
            temp=*ptr;
            *ptr=*(ptr+1);
            *(ptr+1)=temp;
            k=j;
          }
     }

}
void Print(int a[][M],int N) //The procedure prints the array. a- is  sorted array, N-the distance between the numbers.
{
  int *ptr,i,num,cnt=0; //i-variable to run through the array, num-numbers,
                        // cnt-variable for counting how many spaces do, *ptr -pointer to the array.
  ptr=a;
  for (i=0;i<M*M;ptr++)
   {
     num=*ptr;
     //counts how many numbers including.
     while (num!=0)
      {
       num/=10;
       cnt++;
      }
     cnt=N-cnt; //calculates the number of spaces.
     //print spices
     while (cnt!=0)
      {
        printf (" ");
        cnt--;
      }
     printf ("%d",*ptr);//print number.
     i++;
     printf ("%s",i%(M) ? "":"\n"); //to the next line.
   }
}
void main ()
{
    int mat[M][M],i,j,N=0;// mat- matrix array, i and j-variables to run through the array,
                          // N-variable distance between the numbers.
    printf ("Enter %d numbers\n",M*M);
    //Input numbers.
    for (i=0;i<M;i++)
     for (j=0;j<M;j++)
      scanf ("%d",&mat[i][j]);
    Sort(mat);//The procedure that sorts the array.
    i=mat[M-1][M-1]; // highest number.
    //counts how many numbers in the highest number.
    while(i!=0)
     {
      i/=10;
      N++;
     }
    Print (mat,N+1); //The procedure prints the array.
}
