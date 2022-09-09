#include <stdio.h>
#include "include.h"
#include <string.h>


int num_of_rows(FILE *file)
{
    int count = 0;

    while (!feof(file) && !ferror(file)) 
    {
        if (fgetc(file) == '\n')
            count++;
    }
    return count;
}

int count_simvols(FILE *file)
{
    fseek(file, 0, SEEK_END);

    int number = ftell(file);
    
    fseek(file, 0, SEEK_SET);

    return number;
}

