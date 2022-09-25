#include "utils.hpp"
#include "stack.hpp"
#include "error.hpp"

#include <stdio.h>
#include <assert.h>

// TODO сделать свой ассерт, коды ошибок, понять как дамп сделать макросомч


int main() {
    const char *LOG_FILE = "/mnt/c/Users/User/Desktop/programs/stack/log.txt";
    // const char *LOG_FILE = "C://Users//User//Desktop//programs//stack//log.txt";
    // extern FILE *log = fopen("/mnt/c/Users/User/Desktop/programs/stack/log.txt", "w");


    FILE *log = fopen(LOG_FILE, "w");

    assert(log != nullptr && "coudn't open file");

    if (log == nullptr)
        printf("Could not open file.\n");

    stack stk1 = {
        .data = nullptr,
        .size = 0,
        .capacity = 0,
        // .number_of_error = 0,
        .info = { 
            0, 
            __LINE__, 
            __FUNCTION__, 
            __FILE__, 
        },
        // .LINE = __LINE__,
        // .FUNC = __FUNCTION__,
        // .NAME_FILE = __FILE__, 
    };

    stack_ctor(&stk1, 10);
    assert(stk1.data != nullptr && "null pointer");
    to_dump(&stk1, log);
    for (int i = 1; i <= 40; i++) {
        stack_push(&stk1, i);
        to_dump(&stk1, log);
    }
    elem_stk value = 0;
    for (int i = 40; i > 0; i--) {
        stack_pop(&stk1, &value);
        to_dump(&stk1, log);
    }
    stack_dtor(&stk1);
    fclose(log);

}