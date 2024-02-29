#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define steps 1000

void correct(int size_x, int size_y, char map[size_x][size_y])
{
    // do 
}

void walker(int size_x, int size_y, char map[size_x][size_y])
{
    srand(time(NULL));

    for(int i=0;i<size_x;i++)
        for(int j=0;j<size_y;j++)
            map[i][j] = '0';

    int x = size_x/2, y = size_y/2;
    map[x][y] = '1';
    int direction;

    int correct = 1;
    for(int i = 0; i < steps; i++)
    {
        do
        {
            correct = 1;
            direction = rand()%4;
            switch (direction)
            {
            case 0:
            {

            } 
                break;
            case 1:
            {

            }
                break;
            case 2:
            {

            }
                break;
            case 3:
            {

            }
                break;
            }
        } while (correct == 0);
        
    }  
}