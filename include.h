#ifndef INCLUDE_H_INCLUDED
#define INCLUDE_H_INCLUDED

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char  *poem;
    char **sorting_poem;
    char **save_point_poem;
    int    NUMBER;
} poem;

int   num_of_rows(char *text);
int   count_symbols(FILE *file);

void  normal_sorting(char **sort, int NUMBER);
void  unnormal_sorting(char **sort, int NUMBER);

int   unnormal_strcmp(char *s, char *t);
int   normal_strcmp(char *s, char *t);

void  print_to_file(char **save_point, int count);

char  *read_file();
// void  text_normalize(poem *text);

#endif