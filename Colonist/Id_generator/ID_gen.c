#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "../Colonist_structure.h"
#include "ID_gen.h"
#define Year 2077

void id_maker(char* ID, int i, int gender, int age)
{
	// first four is the number of the colonist
	int j=3;
	while(j>=0)
	{
		ID[j] = i%10 + 48; // +48 because of ASCII
		i = i/10;
		j--;
	}

	/*srand(time(NULL));*/
	int random = rand()%100;
	
	// next two are: 2 even digits for females and 2 odds for males
	if(gender == 1) // male
	{
		while(random%2 != 1)
			random = rand()%100;
	}
	else
	{
		while(random%2 != 0)
			random = rand()%100;
	}

	ID[5] = random%10 + 48;
	random = random/10 + 48;
	ID[4] = random;
	
	// last two are the unit and tenths digits of the year the colonist was born
	int gap = Year - age;

	ID[7] = gap%10 + 48;
	gap = gap/10;
	ID[6] = gap%10 + 48;

	ID[8] = '\0';
}

