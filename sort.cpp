#include "sort.hpp"

int strcmp_first_letter(const void *s_, const void *t_)  {

    assert((t_ != nullptr) && "null pointer");
    assert((s_ != nullptr) && "null pointer");

    char* str1 = ((const string *) s_)->string;
    char* str2 = ((const string *) t_)->string;

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

int strcmp_last_letter(const void *s_, const void *t_)  { // rename
   
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

void swap(char *p1, char *p2, size_t SIZE) {
    assert((p1 != nullptr) && "null pointer");
    assert((p2 != nullptr) && "null pointer");

    if (SIZE >= sizeof(long double)) {
        int count = SIZE / sizeof(long double);
        while (count--) {
            long double tmp = *p1;
            *p1++ = *p2;
            *p2++ = tmp;
            SIZE -=  sizeof(long double);
        }
    } else if (SIZE >= sizeof(long int)) {
        int count = SIZE / sizeof(long int);
        while (count--) {
            long int tmp = *p1;
            *p1++ = *p2;
            *p2++ = tmp;
            SIZE -=  sizeof(long int);
        }
    } else if (SIZE >= sizeof(int)) {
        int count = SIZE / sizeof(int);
        while (count--) {
            int tmp = *p1;
            *p1++ = *p2;
            *p2++ = tmp;
            SIZE -=  sizeof(int);
        }
    } else {
        while (SIZE--) {
            char tmp = *p1;
            *p1++ = *p2;
            *p2++ = tmp;
        }
    }
}

void my_bubble_sort(void *sort_, size_t NUMBER, size_t SIZE,  int (* strcmp)(const void *s, const void *t))  {
    assert(sort_  != nullptr && "null pointer");
    assert(strcmp != nullptr && "null pointer");

    char *sort = (char *)sort_;

    for(unsigned i = 0 ; i < (NUMBER - 1); i++) { 
       for(unsigned j = 0 ; j < NUMBER - i - 1 ; j++) {  
            if (strcmp(sort + j*SIZE, sort + (j + 1)*SIZE) > 0) { 
                swap((sort + j*SIZE), (sort + (j + 1)*SIZE), SIZE);
           }
        }
    } 
}

int partition (void *sort_, int LOW, int NUMBER, size_t SIZE, int (*strcmp)(const void *s, const void *t)) {
    char *sort = (char *)sort_;
	int i = LOW - 1;
	char *tmp = sort + NUMBER*SIZE;

    for (int j = LOW; j < NUMBER; j++) {
        if (strcmp((sort + j*SIZE), tmp) < 0) {
            i++;
            swap (sort + j*SIZE, sort + i*SIZE, SIZE);
        }
    }

    swap(sort + (i + 1)*SIZE, sort + NUMBER*SIZE, SIZE);
	return (i + 1);
}

void  my_qsort(void *sort, int LOW, int NUMBER, size_t SIZE,  int (*strcmp)(const void *s, const void *t)) {
	if(LOW < NUMBER) {
    	int i = partition(sort, LOW, NUMBER, SIZE, strcmp);

		my_qsort(sort, LOW, i-1, SIZE, strcmp);
		my_qsort(sort, i+1, NUMBER, SIZE, strcmp);
	}
}

void  sort_qsort_first_letter(poem *text) {
    qsort(text->arr_str, text->NUMBER, sizeof(string), strcmp_first_letter);
}

void  sort_qsort_last_letter(poem *text)  {
    qsort(text->arr_str, text->NUMBER, sizeof(string), strcmp_last_letter);
}

void  sort_my_qsort_first_letter(poem *text) {
    my_qsort(text->arr_str, 0, text->NUMBER - 1, sizeof(string),  strcmp_first_letter);
}

void  sort_my_qsort_last_letter(poem *text)  {
    my_qsort(text->arr_str, 0, text->NUMBER - 1, sizeof(string),  strcmp_last_letter);
}