#include "stack.hpp"
#include "utils.hpp"
#include <math.h>

// extern FILE *log = fopen("/mnt/c/Users/User/Desktop/programs/stack/log.txt", "w");


void stack_ctor(stack *stk, size_t capasity) {
    assert(stk != nullptr && "null pointer");
    stk->capacity = capasity;
    stk->data = (elem_stk *)calloc(capasity + 1, sizeof(elem_stk));
    stk->size = 0;
}

void stack_dtor(stack *stk) {
    assert(stk != nullptr && "null pointer");
    free(stk->data);
    stk->data = nullptr;
    stk->capacity = -1;
    stk->size = -1;
}

void stack_push(stack *stk, double elem) {
    assert(stk != nullptr && "null pointer"); //вместо ассертов вызывать функцию проверки всего стека

    if (stk->size >= stk->capacity) stack_resize(stk);
    stk->data[stk->size] = elem;
    (stk->size)++;
}

void stack_resize(stack *stk) {

    assert(stk       != nullptr && "null pointer");
    assert(stk->data != nullptr && "null pointer");

    if (stk->capacity == stk->size) {
        stk->capacity *= 2;
    } else if (stk->size + 1 == stk->capacity/2) {
        stk->capacity /= 2; 
    }
    //изменяем капасити и получаем новое значение, до которого расширяемся
    stk->data = (elem_stk *)realloc(stk->data, stk->capacity*sizeof(elem_stk));

    assert(stk->data != nullptr && "null pointer");

}

void stack_pop(stack *stk, elem_stk *value) {
    assert(stk       != nullptr && "null pointer");
    assert(stk->data != nullptr && "null pointer");
    *value = stk->data[stk->size];
    stk->size--;
    stk->data[stk->size] = NAN;
    if (stk->size + 1 == stk->capacity/2 && stk->size >= 10) stack_resize(stk);
}




