#include "Colonist_structure.h"
#include "Name_generator/name_gen.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define Population 100 // <<---- Current number of people 
	
void allocate(create* temp)
{
	temp->Name = malloc(15);
	temp->Surname = malloc(20);
	temp->Continent = malloc(15);
	temp->Education = malloc(10);
	temp->Id = malloc(8);
	temp->Hobby = malloc(20);
	temp->Job = malloc(20);
}

void discard(create* temp)
{
	free(temp->Name);
	free(temp->Surname);
	free(temp->Continent);
	free(temp->Education);
	free(temp->Id);
	free(temp->Hobby);
	free(temp->Job);
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
	
		printf("%s %s %s", person[i]->Name, person[i]->Surname, person[i]->gender == 1? "male\n":"female\n");

		discard(person[i]);
		free(person[i]);
	}
}
