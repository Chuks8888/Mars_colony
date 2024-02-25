#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "../Colonist_structure.h"
#include "Activity_gen.h"

void Jobs(char *job)
{
	char* buffer = (char*)malloc(40);
	FILE *fp = fopen("Job_Hobby_gen/Jobs.txt", "r");

	if(fp == NULL)
	{
		printf("error reading Jobs.txt");
		exit(1);
	}

	/*srand(time(NULL));*/

	int random = rand()%150 + 1;

	for(int i = 0; i<random; i++)
	{
		/*fscanf(fp, "%s", buffer);*/
		fgets(buffer, 39, fp);
	}

	strcpy(job, buffer);

	fclose(fp);
	free(buffer);
}

void Hobbies(char *hobby)
{
	char* buffer = (char*)malloc(40);
	FILE *fp = fopen("Job_Hobby_gen/Hobbies.txt", "r");

	if(fp == NULL)
	{
		printf("error reading Hobbies.txt");
		exit(1);
	}

	/*srand(time(NULL));*/

	int random = rand()%150 + 1;

	for(int i = 0; i<random; i++)
	{
		/*fscanf(fp, "%s", buffer);*/
		fgets(buffer, 39, fp);
	}

	strcpy(hobby, buffer);

	fclose(fp);
	free(buffer);
}
