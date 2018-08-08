#include <stdio.h>
#include <stdlib.h>

extern int scnt;

#define GRDL 5
#define NAML 10
#define ADDRL 40

typedef struct{
	char name[NAML];
	char addr[ADDRL];
	int grd[GRDL];
} stud;

/*Compute average grade and print*/
void studallavg(stud *stdb);

/*Compute average and print for each student*/
void studavg(stud *stdb);

/*Print all array items*/
void studprnt(stud *stdb);

/*Free last item if parameter 0, free all array if parameter 1*/
stud* studdel(stud *stdb, int freeall);

/*Add new student to the array*/
stud* studadd(stud *stdb);