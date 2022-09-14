#ifndef INCLUDE_H_INCLUDED
#define INCLUDE_H_INCLUDED

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char  *poem;
    char **sorting_begin;
    char **sorting_end;
    char **save_point;
    int    NUMBER;
} poem;

int   num_of_rows(char *text);
int   count_symbols(FILE *file);

void  normal_sorting(char **sort, int NUMBER);
void  unnormal_sorting(char **sort, int NUMBER);

int   unnormal_strcmp(char *s, char *t);
int   normal_strcmp(char *s, char *t);

void  print_to_file(poem *text);
void  text_normalize(poem *text);
char  *read_file();

#endif