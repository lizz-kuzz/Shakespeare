#ifndef UTILS_HPP_INCLUDED
#define UTILS_HPP_INCLUDED

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
    char   *text;
    string *arr_str;
    int     NUMBER;
} poem;

#endif