#include "Colonist_structure.h"
#include "Name_generator/name_gen.h"
#include "Job_Hobby_gen/Activity_gen.h"
#include "Id_generator/ID_gen.h"
#include "show_colonist.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define Population 5 // <<---- Current number of people 
	
void allocate(create* temp)
{
	temp->Name = malloc(15);
	temp->Surname = malloc(20);
	temp->Id = malloc(8);
	temp->Hobby = malloc(40);
	temp->Job = malloc(40);
}

void discard(create* temp)
{
	free(temp->Name);
	free(temp->Surname);
	free(temp->Id);
	free(temp->Hobby);
	free(temp->Job);
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

		show_colonist(person[i]);
	
		discard(person[i]);
		free(person[i]);
	}
}
