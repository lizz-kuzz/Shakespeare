#include "include.h"


void  sort_qsort_first_letter(poem *text) {
    qsort(text->arr_str, text->NUMBER, sizeof(string), strcmp_first_letter);
}

void  sort_qsort_last_letter(poem *text)  {
    qsort(text->arr_str, text->NUMBER, sizeof(string), strcmp_last_letter);
}

int strcmp_first_letter(const void *s_, const void *t_)  {

    assert((t_ != nullptr) && "null pointer");
    assert((s_ != nullptr) && "null pointer");


    char* str1 = ((const string *) s_)->string;
    char* str2 = ((const string *) t_)->string;


    // for (; *t != '\0' && *s != '\0';) {        
    //     if (isalpha(*s) == 0)  {
    //         s++;
    //         continue;
    //     } else if (isalpha(*t) == 0) {
    //         t++;
    //         continue;
    //     } else if (toupper(*s) == toupper(*t)) {
    //         s++; t++;
    //         continue;
    //     } 
    //     break;
    // }
    // return *s - *t;
    int dif = 0;
    while (dif == 0 ) {
        while (*str1 != '\0' && isalpha(*str1) == 0)
            str1++;
        while (*str2 != '\0' && isalpha(*str2) == 0)
            str2++;
    
        if (dif != 0 || *str1 == '\0' || *str2 == '\0')
            return dif;
        dif = *str1 - *str2;
        str1++; str2++;
    }
    return dif;
}

char* swap(char *p1, char *p2, size_t SIZE) {
    assert((p1 != nullptr) && "null pointer");
    assert((p2 != nullptr) && "null pointer");

    char *p = p2;
    while(SIZE--) {
        char tmp = *p1;
        *p1++ = *p2;
        *p2++ = tmp;
    }
    return p;
}

void my_buble_sort(void *sort, size_t NUMBER, size_t SIZE,  int (* strcmp)(const void *s, const void *t))  {
    assert(sort   != nullptr && "null pointer");
    assert(strcmp != nullptr && "null pointer");

    void *tmp = 0;
    void *sort1 = 0;
    void *sort2 = 0;

    for(unsigned i = 0 ; i < (NUMBER - 1); i++) { 
       for(unsigned j = 0 ; j < NUMBER - i - 1 ; j++) {  
            if (strcmp((void *)(sort + j*SIZE), (void *)(sort + (j + 1)*SIZE)) > 0) { 
                sort1 = (sort + j*SIZE);
                sort2 = (sort + (j + 1)*SIZE);
                tmp = sort1;
                sort1 = swap((char*)sort1, (char*)sort2, SIZE);
                sort2 = tmp;
           }
        }
    } 
}

int strcmp_last_letter(const void *s_, const void *t_)  {
   
    assert((s_ != nullptr) && "null pointer");
    assert((t_ != nullptr) && "null pointer");

    char* str1 = ((const string *) s_)->string;
    char* str2 = ((const string *) t_)->string;

    char *p1 = str1;
    char *p2 = str2;

    str1 += ((const string *) s_)->len - 1;
    str2 += ((const string *) t_)->len - 1;

    for (; str1 >= p1 && str2 >= p2 && *str1 != '\0' && *str2 != '\0'; ) {
        if (isalpha(*str1) == 0) {
            str1--;
            continue;
        } else if (isalpha(*str2) == 0) {
            str2--;
            continue;
        } else if (tolower(*str1) == tolower(*str2)) {
            str1--; str2--;
            continue;
        } 
        break;
    }
    return *str1 - *str2;
}
