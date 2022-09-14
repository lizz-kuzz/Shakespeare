#include <stdio.h>
#include "include.h"


int normal_strcmp(char *s, char *t)  {
    assert((s != nullptr || t != nullptr) && "null pointer");

    for (; (*t != '\0' && *s != '\0') && *s == *t; ++s, ++t)  {
        if (isalpha(*s) && isalpha(*t))
                continue;
    }

    return *s - *t;
}

void normal_sorting(char **sort, int NUMBER)  {

    const char *OUTPUT_FILE_WITH_SORTING_TEXT = "C:\\Users\\User\\Desktop\\programs\\shakespeare\\shakespeare_sorting1.txt";
    
    assert(sort != nullptr && "null pointer");

    for(int i = 0 ; i < (NUMBER - 1); i++) { 
       for(int j = 0 ; j < NUMBER - i - 1 ; j++) {  
           if(normal_strcmp(sort[j], sort[j+1]) > 0) {           
              char *tmp = sort[j];
              sort[j] = sort[j+1];
              sort[j+1] = tmp; 
           }
        }
    }

    // print_to_file(sort, NUMBER);
    FILE *file_write = fopen(OUTPUT_FILE_WITH_SORTING_TEXT, "w");

    assert(file_write != nullptr && "coudn't open file");

    for (int i = 0; i < NUMBER; i++)
        fprintf(file_write, "%s\n", sort[i]); 

    fclose(file_write);
}


int unnormal_strcmp(char *s, char *t)  {
    assert((s != nullptr || t != nullptr) && "null pointer");

    int length_s = strlen(s);
    int length_t = strlen(t);
    t += length_t - 1;
    s += length_s - 1;

    for (; (*t != '\0' && *s != '\0' ) && *s == *t; --s, --t)  {
        if (isalpha(*s) && isalpha(*t))
            continue;
    }
    return *s - *t;
}
void unnormal_sorting(char **sort, int NUMBER)  {
    const char *OUTPUT_FILE_WITH_SORTING_TEXT = "C:\\Users\\User\\Desktop\\programs\\shakespeare\\shakespeare_sorting2.txt";
    
    assert(sort != nullptr && "null pointer");

    for(int i = 0 ; i < (NUMBER - 1); i++) { 
       for(int j = 0 ; j < NUMBER - i - 1 ; j++) {  
           if (unnormal_strcmp(sort[j], sort[j+1]) > 0) {           
              char *tmp = sort[j];
              sort[j] = sort[j+1];
              sort[j+1] = tmp; 
           }
        }
    }
    // print_to_file(sort, NUMBER);
    FILE *file_write = fopen(OUTPUT_FILE_WITH_SORTING_TEXT, "w");

    assert(file_write != nullptr && "coudn't open file");

    for (int i = 0; i < NUMBER; i++)
        fprintf(file_write, "%s\n", sort[i]); 

    fclose(file_write);
}