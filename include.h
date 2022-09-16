#ifndef INCLUDE_H_INCLUDED
#define INCLUDE_H_INCLUDED

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char  *poem;
    char **sorting;
    int    NUMBER;
} poem;

int   num_of_rows(char *text);
int   count_symbols(FILE *file);

void  sort_first_letter(char **sort, int NUMBER);
void  sort_last_letter(char **sort, int NUMBER);

int   strcmp_last_letter(const void *s, const void *t);
int   strcmp_first_letter(const void *s_, const void *t_);

void  sort_qsort_first_letter(poem *text);
void  sort_qsort_last_letter(poem *text);


char  *read_file();
void  text_normalize(poem *text);
void  text_cpy(poem *text, poem *cpy_text);
void  sorting_and_print_to_file(poem *text);


#endif