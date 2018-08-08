/*Authors:
* Denis Sidorovich & Titov Alexey
*/
#include "Hext.h"
extern int scnt;
void main(void)
{
	stud* stdb = NULL;
	int flag;
	printf("Choose operation:\n1-addition\n2-remove\n3-printout list of student\n");
	printf("4-average grade for each student\n5-average grade for all students\n");
	printf("6- exit\n");
	scanf("%d", &flag);
	system("cls");
	while (flag<1 || flag>6)
	{
		printf("Err, enter new operation\n");
		scanf("%d", &flag);
	}
	/*Operation*/
	while (flag != 6)
	{
		switch (flag)
		{
		case 1: stdb = studadd(stdb);
			break;
		case 2: stdb = studdel(stdb, 0);
			break;
		case 3: studprnt(stdb);
			break;
		case 4: studavg(stdb);
			break;
		case 5: studallavg(stdb);
			break;
		default: break;
		}
		printf("\nChoose operation:\n1-addition\n2-remove\n3-printout list of student\n");
		printf("4-average grade for each student\n5-average grade for all students\n");
		printf("6- exit\n");
		scanf("%d", &flag);
		system("cls");
	}
	studdel(stdb, 1);
}