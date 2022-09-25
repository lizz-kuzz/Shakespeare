#include "error.hpp"


void to_dump(stack *stk, FILE *log) {  
    // как сделать макросом?
    assert(log != nullptr && "coudn't open file");
    assert(stk != nullptr && "coudn't open file");

    stk->info.FUNC_CALL = __FUNCTION__;
    stk->info.LINE_CALL = __LINE__;
    stk->info.NAME_FILE_CALL = __FILE__;

    fprintf(log, "\n%s() at %s(%d)\n", stk->info.FUNC_CALL, stk->info.NAME_FILE_CALL, stk->info.LINE_CALL);
    fprintf(log, "Stack[%p] ", stk);

    if (stk->info.number_of_error == 0) {
        fprintf(log, "(ok) \"stk1\" at %s() at %s(%d) \n", stk->info.FUNC ,stk->info.NAME_FILE, stk->info.LINE);
        fprintf(log, "size = %lu\n", stk->size);
        fprintf(log, "cappacity = %lu\n", stk->capacity);

        fprintf(log, "data [%p]\n{\n", stk->data);
        for (int i = 0; i < stk->capacity; i++) {
            fprintf(log, "*[%d] = %g\n", i, stk->data[i]);
        }

        fprintf(log, "}\n");  
    } else {
        // функция расшифровки кодов ошибок и их запись
        fprintf(log, "распечатать коды ошибок(но сначала расшифровать)");
    }

}