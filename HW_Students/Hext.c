#include "Hext.h"
scnt = 0; //External variable created in Hext.h

/*Add new student to the array*/
stud* studadd(stud *stdb)
{
	int i;
	if (scnt == 0) //Create first item if array is empty
	{
		stdb = (stud*)malloc(1 * sizeof(stud));
	}
	else //If not empty, add new item.
	{
		stdb = realloc(stdb, (scnt + 1) * sizeof(stud));
	}
	printf("Please enter name of new student:");
	_flushall();
	scanf("%s", &stdb[scnt].name);
	printf("Please enter address of new student:");
	_flushall();
	scanf("%s", &stdb[scnt].addr);
	for (i = 0; i < GRDL; i++)
	{
		printf("Please enter grade %d of new student:", i + 1);
		_flushall();
		scanf("%d", &stdb[scnt].grd[i]);
	}
	scnt++;
	return stdb;
}
/*Free last item if parameter 0, free all array if parameter 1*/
stud* studdel(stud *stdb, int freeall)
{

	if (freeall)
	{
		stdb = realloc(stdb, 0 * sizeof(stud)); //Free all
		scnt = 0;
	}
	else
	if (scnt) stdb = realloc(stdb, (scnt - 1) * sizeof(stud)); //Free last
	scnt--;
	return stdb;
}

/*Print all array items*/
void studprnt(stud *stdb)
{
	int i, j,avg;
	for (i = 0; i < scnt; i++)
	{
		avg = 0;
		for (j = 0; j < GRDL; j++)
		{
			avg += stdb[i].grd[j];
		}
		printf("Student #%2d %s have average grade %3d.\n", i + 1, stdb[i].name, avg / 5);
	}
}

/*Compute average and print for each student*/
void studavg(stud *stdb)
{
	int i, j;
	int avg;
	for (i = 0; i < scnt; i++)
	{
		avg = 0;
		for (j = 0; j < GRDL; j++)
		{
			avg += stdb[i].grd[j];
		}
		printf("Average grade of student %s is: %3d.\n", stdb[i].name, avg / 5);
	}
}

/*Compute average grade and print*/
void studallavg(stud *stdb)
{
	int i, j;
	int avg = 0;
	for (i = 0; i < scnt; i++)
	{
		for (j = 0; j < GRDL; j++)
		{
			avg += stdb[i].grd[j];
		}
	}
	printf("Average grade of all students:%3d.\n", avg / (5 * scnt));
}