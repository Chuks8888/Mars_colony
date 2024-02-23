#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Person(char* name, char* surname, int *gender) 
{
	FILE *fp;

	srand(time(NULL));
	int random;
	random = rand()%2;
	*gender = random; // 1-male, 0-female
	if(random == 1) 
	{
		fp = fopen("male.txt", "r");
	}
	else 
	{
		fp = fopen("female.txt", "r");
	}

	random = rand()%1000 + 1;
	for(int i = 0; i < random; i++)
	{
		fscanf(fp, "%s", name);
	}

	random = rand()%1000 + 1;
	for(int i = 0; i < random; i++)
	{
		fscanf(fp, "%s", surname);
	}

	fclose(fp);
}
