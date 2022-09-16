#include <stdio.h>
#include "include.h"

void  sort_qsort_first_letter(poem *text) {
    qsort(text->sorting, text->NUMBER, sizeof(char **), *strcmp_first_letter);
}
void  sort_qsort_last_letter(poem *text)  {
    qsort(text->sorting, text->NUMBER, sizeof(char **), *strcmp_last_letter);
}

int strcmp_first_letter(const void *s_, const void *t_)  {
    assert((t_ != nullptr) && "null pointer");
    assert((s_ != nullptr) && "null pointer");

    const char* t = (const char*) t_;
    const char* s = (const char*) s_;

    for (; *t != '\0' && *s != '\0';) {        
        if (isalpha(*s) == 0)  {
            s++;
            continue;
        } else if (isalpha(*t) == 0) {
            t++;
            continue;
        } else if (toupper(*s) == toupper(*t)) {
            s++; t++;
            continue;
        }
        break;
    }
    return *s - *t;
}

void sort_first_letter(char **sort, int NUMBER)  {
    assert(sort != nullptr && "null pointer");
    
    for(int i = 0 ; i < (NUMBER - 1); i++) { 
       for(int j = 0 ; j < NUMBER - i - 1 ; j++) {  
           if(strcmp_first_letter(sort[j], sort[j+1]) > 0) {          
              char *tmp = sort[j];
              sort[j] = sort[j+1];
              sort[j+1] = tmp; 
           }
        }
    } 
}

int strcmp_last_letter(const void *s_, const void *t_)  {
    const char* t = (const char*) t_;
    const char* s = (const char*) s_;

    assert(s != nullptr && "null pointer");
    assert(t != nullptr && "null pointer");

    const char *ps = s;
    const char *pt = t;
    t += strlen(t) - 1;
    s += strlen(s) - 1;

    for (; t >= pt && s >= ps; ) {
        if (isalpha(*s) == 0) {
            s--;
            continue;
        } else if (isalpha(*t) == 0) {
            t--;
            continue;
        } else if (tolower(*s) == tolower(*t)) {
            s--; t--;
            continue;
        } 
        break;
    }
    return *s - *t;
}

void sort_last_letter(char **sort, int NUMBER)  {    
    assert(sort != nullptr && "null pointer");

    for(int i = 0 ; i < (NUMBER - 1); i++) { 
       for(int j = 0 ; j < NUMBER - i - 1 ; j++) {  
           if (strcmp_last_letter(sort[j], sort[j+1]) > 0) {           
              char *tmp = sort[j];
              sort[j] = sort[j+1];
              sort[j+1] = tmp; 
           }
        }
    }
}

