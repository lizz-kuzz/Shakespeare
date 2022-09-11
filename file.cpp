#include <stdio.h>
#include "include.h"


int num_of_rows(FILE *file)  {
    int count = 0;

    while (!feof(file) && !ferror(file))  {
        if (fgetc(file) == '\n')
            count++;
    }
    return count;
}

int count_simvols(FILE *file)  {
    fseek(file, 0, SEEK_END);

    int number = ftell(file);
    
    fseek(file, 0, SEEK_SET);

    return number;
}

void print_to_file(char **save_point, int count, const char *NAME_OF_FILE)  {
    FILE *file_write = fopen(NAME_OF_FILE, "w");

    assert(file_write != nullptr && "coudn't open file");

    for (int i = 0; i < count; i++)
        fprintf(file_write, "%s\n", save_point[i]); 
    
    fclose(file_write);
}


