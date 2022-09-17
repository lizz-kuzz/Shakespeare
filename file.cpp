#include <stdio.h>
#include "include.h"

char *read_file(const char *TEXT)  {

    FILE *file = fopen(TEXT, "r");

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
    char *point = text;
    while (*point != '\0')  {
        if (*point == '\n')
            count++;
        point++;
    }
    return count;
}

int count_symbols(FILE *file)  {
// stat, getsize
    fseek(file, 0, SEEK_END);
    int number = ftell(file);
    fseek(file, 0, SEEK_SET);

    return number;
}

void text_cpy(poem *text, poem *cpy_text) {
    assert(text != nullptr && "coudn't open file");
    assert(cpy_text != nullptr && "coudn't open file");

    cpy_text->NUMBER = text->NUMBER;
    cpy_text->sorting = (char **) calloc(text->NUMBER + 1, sizeof(char *)); 

    for (int i = 0; (i <= cpy_text->NUMBER); i++)  { 
        cpy_text->sorting[i] = text->sorting[i];
    }
    
}
void printing_to_file(FILE *file, poem *text) {
    for (int i = 0; i < text->NUMBER; i++)
        fprintf(file, "%s\n", text->sorting[i]); 
}

void print_header(const char* WORD, FILE *file_write) {
    fprintf(file_write, "\n\n\n------------------------------------------------------------\n\n\n");
    fprintf(file_write, "                    %s                        ", WORD);
    fprintf(file_write, "\n\n\n------------------------------------------------------------\n\n\n");
}


void sorting_and_print_to_file(poem *text, const char *NAME_OF_FILE)  {
    
    poem cpy_text = {
        .poem = NULL,
        .sorting = NULL,
        .NUMBER = 0,
    };

    text_cpy(text, &cpy_text);

    FILE *file_write = fopen(NAME_OF_FILE, "w");

    assert(file_write != nullptr && "coudn't open file");

    print_header("TEXT SORTED BY FIRST LETTERS", file_write);
    
    // sort_qsort_first_letter(text);
    my_sort(text->sorting, text->NUMBER, sizeof(char*), strcmp_first_letter);

    printing_to_file(file_write, text);
    print_header("TEXT SORTED BY LAST LETTERS", file_write);

    // sort_qsort_last_letter(text);
    my_sort(text->sorting, text->NUMBER, sizeof(char*), strcmp_last_letter);

    printing_to_file(file_write, text);
    print_header("SOURCE TEXT", file_write);

    printing_to_file(file_write, &cpy_text);
    print_header("END", file_write);

    fclose(file_write);
    free(text->sorting);
    free(cpy_text.sorting);
}

void text_normalize(poem *text)  {
    assert(text != nullptr && "null pointer");
    assert(text->poem != NULL && "null pointer");

    text->NUMBER = num_of_rows(text->poem);

    text->sorting = (char **) calloc(text->NUMBER + 1, sizeof(char *));
   
    assert(text->sorting != NULL && "null pointer");

    char *point = text->poem;
    text->sorting[0] = point;
    int count = 0;

    for (int i = 1; (i <= text->NUMBER) && *(point) != '\0'; point++)  { 
        if (*point == '\n')  {
            *point = '\0';
            if ((*(point + 1)) == '\n')
                continue;
            if ((*(point + 1)) == ' ' && (*(point + 2)) == ' ' &&
                (*(point + 3)) == ' ' && (*(point + 4)) == ' ')  { 
                text->sorting[i] = point + 5;
                point += 4; 
            }
            text->sorting[i] = point + 1;
            count++;
            i++;
        }
    }
    text->NUMBER = count;
}
