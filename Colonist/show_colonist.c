#include <stdio.h>
#include <string.h>
#include "Colonist_structure.h"
#include "show_colonist.h"

void show_colonist(create* temp)
{
	for(int i= 0; i <70*2;i++)
	{
		if(i == 70) printf ("\n");
		printf("/");
	}
	printf("\n");
	printf("               XNWWWWWNN\n");
	printf("              WMMMMMMMMMW		ID:\t%s\n", temp->Id);
	printf("             WMMMMMMMMMMMW\n");
	printf("            NWMMMMMMMMMMMMN		NAME:\t%s %s\n", temp->Name, temp->Surname);            
	printf("            NWMMMMMMMMMMMMN\n");
	printf("            XNMMMMMMMMMMMWX		AGE:\t%d\n", temp->Age);            
	printf("             KNWMMMMMMMMNX\n");
	printf("              KKXNNNNNXXK		SEX:\t%s\n", temp->gender == 1? "MALE":"FEMALE");
	printf("                         \n");              
	printf("        XNWWWMMMMMMMMMMMMMWWWNXK	HEIGHT:\t%d\n", temp->Height);        
	printf("       NWMMMMMMMMMMMMMMMMMMMMMMWN\n");
	printf("      WMMMMMMMMMMMMMMMMMMMMMMMMMMW	JOB:\t%s", temp->Job);
	printf("     WMMMMMMMMMMMMMMMMMMMMMMMMMMMMN\n");
	printf("     MMMMMMMMMMMMMMMMMMMMMMMMMMMMMN	HOBBY:\t%s", temp->Hobby);
	printf("     MMMMMMMMMMMMMMMMMMMMMMMMMMMMMN\n");
	printf("     MMMMMMMMMMMMMMMMMMMMMMMMMMMMMW\n");
}
