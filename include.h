#ifndef INCLUDE_H_INCLUDED
#define INCLUDE_H_INCLUDED


int num_of_rows(FILE *file);

int count_simvols(FILE *file);

void normal_sorting(char **sort, int NUMBER);
void unnormal_sorting(char **sort, int NUMBER);

int unnormal_strcmp(char *s, char *t);
int normal_strcmp(char *s, char *t);



#endif