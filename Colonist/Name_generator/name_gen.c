#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "name_gen.h"

void Person(char* name, char* surname, int *gender) 
{
	FILE *fp;
	char *buffer = malloc(40);

	int random;
	random = rand()%2;
	*gender = random; // 1-male, 0-female
	if(random == 1) 
	{
		 fp = fopen("Name_generator/male.txt", "r");
	}
	else 
	{
		fp = fopen("Name_generator/female.txt", "r");
	}
	if(fp == NULL)
	{
		printf("error reading male/female.txt");
		exit(1);
	}

	char c;
	int i;
	random = rand()%1000 + 1;
	for(i = 0; i < random-1; i++)
	{
		fscanf(fp, "%s", buffer);
	}
	strcpy(name, buffer);

	fclose(fp);
	fp = fopen("Name_generator/surnames.txt", "r");
	if(fp == NULL)
	{
		printf("error reading surnames.txt");
		exit(1);
	}

	random = rand()%1000 + 1;
	for(i = 0; i < random; i++)
	{
		fscanf(fp, "%s", buffer);
	}
	strcpy(surname, buffer);

	name[14] = '\0';

	fclose(fp);
	free(buffer);
}
