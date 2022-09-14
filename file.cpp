#include <stdio.h>
#include "include.h"

char *read_file()  {
    const char *INPUT_FILE_WITH_TEXT = "C:\\Users\\User\\Desktop\\programs\\shakespeare\\shakespeare.txt";

    FILE *file = fopen(INPUT_FILE_WITH_TEXT, "r");

    assert(file != nullptr && "coudn't open file");

    if (file == NULL)
        printf("Could not open file.\n");
    
    const int SYMBOLS = count_symbols(file);
    char *reading_file = (char *) calloc(SYMBOLS + 1, sizeof(char));  

    fread(reading_file, sizeof(char), SYMBOLS, file);
    fclose(file);

    return reading_file;
}

int num_of_rows(char *text)  {
    int count = 0;

    while (*text != '\0')  {
        if (*text == '\n')
            count++;
        text++;
    }
    return count;
}

int count_symbols(FILE *file)  {

    fseek(file, 0, SEEK_END);

    int number = ftell(file);
    
    fseek(file, 0, SEEK_SET);

    return number;
}

void print_to_file(poem *text)  {

    const char *NAME_OF_FILE =  "C:\\Users\\User\\Desktop\\programs\\shakespeare\\shakespeare_write.txt";

    FILE *file_write = fopen(NAME_OF_FILE, "w");

    assert(file_write != nullptr && "coudn't open file");
    fprintf(file_write, "\n\n\n------------------------------------------------------------\n\n\n");
    fprintf(file_write, "                    TEXT SORTED BY FIRST LETTERS                        ");
    fprintf(file_write, "\n\n\n------------------------------------------------------------\n\n\n");

    for (int i = 0; i < text->NUMBER; i++)
        fprintf(file_write, "%s\n", text->sorting_begin[i]); 
    
    fprintf(file_write, "\n\n\n------------------------------------------------------------\n\n\n");
    fprintf(file_write, "                    TEXT SORTED BY LAST LETTERS                        ");
    fprintf(file_write, "\n\n\n------------------------------------------------------------\n\n\n");


    for (int i = 0; i < text->NUMBER; i++)
        fprintf(file_write, "%s\n", text->sorting_end[i]);
    fprintf(file_write, "\n\n\n------------------------------------------------------------\n\n\n");
    fprintf(file_write, "                          SOURCE TEXT                                   ");
    fprintf(file_write, "\n\n\n------------------------------------------------------------\n\n\n");

    for (int i = 0; i < text->NUMBER; i++)
        fprintf(file_write, "%s\n", text->save_point[i]);  
    fprintf(file_write, "\n\n\n------------------------------------------------------------\n\n\n");
    fprintf(file_write, "                              END                                       ");
    fprintf(file_write, "\n\n\n------------------------------------------------------------\n\n\n");
    
    fclose(file_write);

    free(text->sorting_begin);
    free(text->sorting_end);
    free(text->save_point);
}

void text_normalize(poem *text)  {
    assert(text->poem != NULL && "null pointer");

    text->NUMBER = num_of_rows(text->poem);

    text->sorting_begin = (char **) calloc(text->NUMBER + 1, sizeof(char *));
    text->sorting_end   = (char **) calloc(text->NUMBER + 1, sizeof(char *));
    text->save_point    = (char **) calloc(text->NUMBER + 1, sizeof(char *)); 

    assert(text->save_point != NULL && "null pointer");
    assert(text->sorting_begin!= NULL && "null pointer");

    char *point = text->poem;

    text->sorting_begin[0] = point;
    text->sorting_end[0]   = point; 
    text->save_point[0]    = point;
    
    int count = 0;

    for (int i = 1; (i <= text->NUMBER) && *(point) != '\0'; point++)  { 
        if (*point == '\n')  {
            *point = '\0';

            text->save_point[i] = point + 1;

            if ((*(point + 1)) == '\n')
                continue;

            if ((*(point + 1)) == ' ' && (*(point + 2)) == ' ' &&
                (*(point + 3)) == ' ' && (*(point + 4)) == ' ')  { 
                text->sorting_begin[i] = point + 5;
                text->sorting_end[i] = point + 5;
                point += 4;
            }
            text->sorting_begin[i] = point + 1;
            text->sorting_end[i] = point + 1;
            count++;
            i++;
        }
    }
    text->NUMBER = count;
}
