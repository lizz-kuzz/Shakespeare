#include <stdio.h>
#include "file.h"
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

int normal_strcmp(char *s, char *t) 
{
    // while (*s != ' ' && *t != ' ')  {
    //     s++;
    //     t++;
    // } 

    for (; (*t != '\0' && *s != '\0' ) && *s == *t; ++s, ++t)  {
        if ((*s >= 1 && *s <= 64)|| (*s >= 91 && *s <= 96)|| (*s >= 123 && *s <= 127) && 
            (*t >= 1 && *t <= 64)|| (*t >= 91 && *t <= 96)|| (*t >= 123 && *t <= 127))
            continue;
    }
    

    return *s - *t;
}

void normal_sorting(char **sort, int NUMBER)
{
    const char *OUTPUT_FILE_WITH_SORTING_TEXT = "C:\\Users\\User\\Desktop\\programs\\shakespeare\\shakespeare_sorting1.txt";
    
    
    for(int i = 0 ; i < (NUMBER - 1); i++) { 
       for(int j = 0 ; j < NUMBER - i - 1 ; j++) {  
           if(normal_strcmp(sort[j], sort[j+1]) > 0) {           
              char *tmp = sort[j];
              sort[j] = sort[j+1];
              sort[j+1] = tmp; 
           }
        }
    }


    FILE *file_write = fopen(OUTPUT_FILE_WITH_SORTING_TEXT, "w");
    for (int i = 0; i < NUMBER; i++)
        fprintf(file_write, "%s\n", sort[i]); 

    fclose(file_write);


}


int unnormal_strcmp(char *s, char *t) 
{
    // while (*s != ' ' && *t != ' ')  {
    //     s++;
    //     t++;
    // } 
    int length_s = strlen(s);
    int length_t = strlen(t);
    t += length_t;
    s += length_s;
    for (; (*t != '\0' && *s != '\0' ) && *s == *t; --s, --t)  {
        if ((*s >= 1 && *s <= 64)|| (*s >= 91 && *s <= 96)|| (*s >= 123 && *s <= 127) && 
            (*t >= 1 && *t <= 64)|| (*t >= 91 && *t <= 96)|| (*t >= 123 && *t <= 127))
            continue;
    }
    return *s - *t;
}
void unnormal_sorting(char **sort, int NUMBER)
{
    const char *OUTPUT_FILE_WITH_SORTING_TEXT = "C:\\Users\\User\\Desktop\\programs\\shakespeare\\shakespeare_sorting2.txt";
    
    for(int i = 0 ; i < (NUMBER - 1); i++) { 
       for(int j = 0 ; j < NUMBER - i - 1 ; j++) {  
           if (unnormal_strcmp(sort[j], sort[j+1]) > 0) {           
              char *tmp = sort[j];
              sort[j] = sort[j+1];
              sort[j+1] = tmp; 
           }
        }
    }


    FILE *file_write = fopen(OUTPUT_FILE_WITH_SORTING_TEXT, "w");
    for (int i = 0; i < NUMBER; i++)
        fprintf(file_write, "%s\n", sort[i]); 

    fclose(file_write);


}