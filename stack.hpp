#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED

#include "utils.hpp"

void stack_ctor(stack *stk, size_t capasity);

void stack_push(stack *stk, double elem);

void stack_dtor(stack *stk);

void stack_resize(stack *stk);

void stack_pop(stack *stk, elem_stk *value);

#endif