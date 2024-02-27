#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "Trait_gen.h"

#define No_traits 61

void Traitz(char **traits)
{
    FILE *ch_traits = fopen("Trait_gen/Character_traits.txt", "r");
    if(ch_traits == NULL)
    {
        puts("error reading file");
        exit(1);
    }

    char *buffer1 = malloc(30), *buffer2 = malloc(30);
    int temp[3];
    int i = 0, check = 1; 
    while(i < 3)
    {
        check = 1;
        temp[i] = rand()%No_traits + 1;
        for(int j=0;j<i;j++)
        {
            if(temp[j] == temp[j+1]) check = 0;   
        }
        if(check == 0) continue;

        for(int j = 0;j < temp[i]; j++)
        {
            fscanf(ch_traits, "%s / %s", buffer1, buffer2);
        }
        if(i == 3) strcpy(traits[i], buffer2);
        else strcpy(traits[i], buffer1);
        i++;
    }

    fclose(ch_traits);
    free(buffer1);
    free(buffer2);
}