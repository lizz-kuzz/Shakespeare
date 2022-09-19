#ifndef INCLUDE_H_INCLUDED
#define INCLUDE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>


typedef struct {
    char *string;
    int   len;
} string;

typedef struct {
    char   *poem;
    char  **sorting;
    string *arr_str;
    int     NUMBER;
} poem;

int   num_of_rows(char *text);
int   count_symbols(FILE *file);

void  my_buble_sort(void *sort_, size_t NUMBER, size_t SIZE,  int (*strcmp)(const void *s, const void *t));

int   strcmp_last_letter (const void *s, const void *t);
int   strcmp_first_letter(const void *s_, const void *t_);

void  sort_qsort_first_letter(poem *text);
void  sort_qsort_last_letter (poem *text);

char  *read_file(const char *TEXT);
void  text_normalize(poem *text);
void  text_cpy(poem *text, poem *cpy_text);
void  create_arr_str(poem *text);

void  printing_to_file_text(FILE *file, poem *text);
void  print_header(const char* WORD, FILE *file_write);
void  printing_to_file(FILE *file, string *text, int NUMBER);
void  sorting_and_print_to_file(poem *text, const char *NAME_OF_FILE);

#endif