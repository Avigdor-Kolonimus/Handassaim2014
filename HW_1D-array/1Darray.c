#include <stdio.h>
#define TEN 10
FILE *infile;
int NumTeam()
 {
   int cnt=1;
   char ch;
   infile=fopen("tex.txt","r");
   fscanf (infile,"%c",&ch);
   while (ch!='\n')
    {
      if (ch==':')
        cnt++;
      fscanf (infile,"%c",&ch);
    }
   fclose(infile);
   return cnt;
 }
void WorkWithArr (int *point[],int *goal[],int *win[],int *defeat[],int n)
{
    int i=0,flag=1,a=0,b=0;
    infile=fopen("tex.txt","r");
    char ch;
    fscanf (infile,"%c",&ch);
    while (i<n)
     {
       if (ch != '\n')
        {
         if (ch==':')
          flag=0;
         else
		  if ((ch>='0')&&(ch<='9'))
           {
            if (flag)
             a=ch-'0'+a*TEN;
            else
             b=ch-'0'+b*TEN;
           }
           else
             if ((ch==' ')&&(flag==0))
              {
                  if (a>b)
                  {
                    point[i]+=2;
                    win[i]++;
                  }
                  else
                    if (a==b)
                     point[i]+=1;
                    else
                     defeat[i]++;
                  goal[i]+=a;
                  a=b=0;
                  flag=1;
              }
        }
      else
      {
       if (i<n-2)
        {
          if (a>b)
           {
            point[i]+=2;
            win[i]++;
           }
           else
            if (a==b)
             point[i]+=1;
            else
             defeat[i]++;
          goal[i]+=a;
          a=b=0;
          flag=1;
        }
       i++;
      }
      fscanf (infile,"%c",&ch);
     }
    fclose(infile);
}
int Search(int a[],int n,int flag)
{
    int i,srh;
    srh=a[0];
    for (i=1;i<n;i++)
     {
       if ((srh<a[i])&&(flag))
        srh=a[i];
       else
        if ((srh>a[i])&&(flag==0))
         srh=a[i];
     }
    return srh;
}
void Winer(int win[],int n)
{
    int pnt_max,i;
    pnt_max=Search(win,n,1);
    for (i=0;i<n;i++)
     if (pnt_max==win[i])
       printf ("Team %d win\n",i+1);
}
void Goals(int goal[],int n)
{
    int goal_max,i;
    goal_max=Search(goal,n,1);
    for (i=0;i<n;i++)
     if (goal_max==goal[i])
       printf ("Team %d scored %d goals\n",i+1,goal[i]);
}
void BigLoser (int los[],int n)
{
    int los_max,i;
    los_max=Search(los,n,1);
    for (i=0;i<n;i++)
     if (los_max==los[i])
       printf ("Team %d with the highest number of losing.\n",i+1);
}
void TeamLos(int los[],int n)
{
    int pnt_min,i;
    pnt_min=Search(los,n,0);
    for (i=0;i<n;i++)
     if (pnt_min==los[i])
       printf ("Team %d with the fewest points\n",i+1);

}
void Average(int w[],int l[],int n)
{
  int i;
  for (i=0;i<n;i++)
   printf ("For Team %d, the average number of losses=%.2f and wins=%.2f\n",i+1,(float)l[i]/(n-1),(float)w[i]/(n-1));

}
void main (void)
{
    int n=NumTeam();
    int a=0,b=0,i;
    int points[n],goals[n],wins[n],defeats[n];
    for (i=0;i<n;i++)
    {
      points[i]=0;      goals[i]=0;
      wins[i]=0;        defeats[i]=0;
    }
    WorkWithArr (points,goals,wins,defeats,n);
    Winer(points,n);
    TeamLos(points,n);
    BigLoser (defeats,n);
    Goals(goals,n);
    Average(wins,defeats,n);
}
