#ifndef UTILS_HPP_INCLUDED
#define UTILS_HPP_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

typedef double elem_stk;

typedef struct {
    long int   number_of_error; //ошибки
    // инфа о созданном стеке
    int        LINE;
    const char *FUNC; 
    const char *NAME_FILE;
// инфа о месте где вызван dump
    int        LINE_CALL;
    const char *FUNC_CALL; 
    const char *NAME_FILE_CALL;

} stack_info;

typedef struct {
    elem_stk   *data;
    size_t     size;
    size_t     capacity;
    stack_info info;
} stack;



// enum ERRORS {
//     // написать коды ошибок
// };

#endif