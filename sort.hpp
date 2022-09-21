#ifndef SORT_HPP_INCLUDED
#define SORT_HPP_INCLUDED

#include "utils.hpp"

void  my_bubble_sort(void *sort_,  size_t NUMBER, size_t SIZE, int (*strcmp)(const void *s, const void *t));
void  my_qsort (void *sort_, int LOW, int NUMBER, size_t SIZE, int (*strcmp)(const void *s, const void *t));
int   partition(void *sort_, int LOW, int NUMBER, size_t SIZE, int (*strcmp)(const void *s, const void *t));

int   strcmp_last_letter (const void *s, const void *t);
int   strcmp_first_letter(const void *s, const void *t);

void  sort_qsort_first_letter    (poem *text);
void  sort_qsort_last_letter     (poem *text);
void  sort_my_qsort_first_letter (poem *text);
void  sort_my_qsort_last_letter  (poem *text);

void  swap(char *p1, char *p2, size_t SIZE);

#endif