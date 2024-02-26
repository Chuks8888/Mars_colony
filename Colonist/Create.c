#include "Colonist_structure.h"
#include "Name_generator/name_gen.h"
#include "Job_Hobby_gen/Activity_gen.h"
#include "Id_generator/ID_gen.h"
#include "MISC/show_colonist.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define Population 10 // <<---- Current number of people 
	
void allocate(create* temp)
{
	temp->Name = malloc(15);
	temp->Surname = malloc(20);
	temp->Id = malloc(9);
	temp->Hobby = malloc(40);
	temp->Job = malloc(40);
	temp->Traits[0] = malloc(30);
	temp->Traits[1] = malloc(30);
	temp->Traits[2] = malloc(30);
}

void discard(create* temp)
{
	free(temp->Name);
	free(temp->Surname);
	free(temp->Id);
	free(temp->Hobby);
	free(temp->Job);
	free(temp->Traits[0]);
	free(temp->Traits[1]);
	free(temp->Traits[2]);
}

void Height_generator(int *Height, int gender)
{
		int average;

		if(gender == 1)
			average = 175; // male
		else
			average = 165; // female
						   
		int temp = rand()%100;

		if(temp  >=25 && temp <75) *Height = rand()%10 + average - 5;
		else if(temp <25) *Height = average - rand()%30;
		else *Height = average + rand()%13;
}

int main()
{

	FILE *cf = fopen("colonists.txt", "w");

	srand(time(NULL));

	create* person[Population];

	for(int i = 0; i < Population; i++)
	{
		person[i] = (create*) malloc(sizeof(create));
		allocate(person[i]);

		Person(person[i]->Name, person[i]->Surname, &person[i]->gender);

		person[i]->Age = rand()%45 + 20;

		Height_generator(&person[i]->Height, person[i]->gender);

		Jobs(person[i]->Job);
		Hobbies(person[i]->Hobby);

		id_maker(person[i]->Id, i, person[i]->gender, person[i]->Age);

		/*show_colonist(person[i]);*/

		fprintf(cf, "%s %s %s %d %s %d %s %s\n", person[i]->Id, person[i]->Name, person[i]->Surname, person[i]->Age, person[i]->gender == 1? "MALE":"FEMALE", person[i]->Height, person[i]->Job, person[i]->Hobby);
		
		discard(person[i]);
		free(person[i]);
	}

	fclose(cf);
}
