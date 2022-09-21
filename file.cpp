#include "file.hpp"
#include "sort.hpp"

static int   count_symbols(FILE *file);
static int   num_of_rows  (char *text); 
static void  free_text    (poem *text);


void read_file(const char *TEXT, poem *shakespeare) {
    FILE *file = fopen(TEXT, "r");

    assert(file != nullptr && "coudn't open file");

    if (file == NULL)
        printf("Could not open file.\n");
    
    int SYMBOLS = count_symbols(file);

    char *reading_file = (char *) calloc(SYMBOLS + 1, sizeof(char));  
    assert(reading_file != nullptr && "null pointer");

    fread(reading_file, sizeof(char), SYMBOLS, file);

    text_normalize(shakespeare, reading_file);

    fclose(file);
}

static int num_of_rows(char *text)  {
    int count = 0;
    char *point = text;

    while (*point != '\0')  {
        if (*point == '\n')
            count++;
        point++;
    }
    return count;
}

static int count_symbols(FILE *file)  {
    fseek(file, 0, SEEK_END);
    
    int number = ftell(file);

    fseek(file, 0, SEEK_SET);

    return number;
}

static void free_text(poem *text) {
    free(text->normal_text);
    free(text->arr_str);
}

void  text_normalize(poem *text, char *text_poem) {
    assert(text      != nullptr && "null pointer");
    assert(text_poem != nullptr && "null pointer");


    text->normal_text = (char **) calloc(text->NUMBER + 1, sizeof(char *));
    text->arr_str =    (string *) calloc(text->NUMBER + 1, sizeof(string)); 
   
    assert(text->normal_text != NULL && "null pointer");
    assert(text->arr_str     != NULL && "null pointer");

    char *ptr_point = text_poem;
    text->normal_text[0] = ptr_point;
    text->arr_str[0].string = ptr_point;
    text->NUMBER = num_of_rows(text_poem);

    int count = 0;

    for (int i = 1; i <= text->NUMBER && *ptr_point != '\0'; ptr_point++)  { 
        if (*ptr_point == '\n')  {
            *ptr_point = '\0';
            text->arr_str[i-1].len = strlen(text->normal_text[i-1]);

            if ((*(ptr_point + 1)) == '\n') 
                continue;
                
            text->normal_text[i] = ptr_point + 1;
            text->arr_str[i].string = ptr_point + 1;
            count++;
            i++;
        }
    }

    text->NUMBER = count;

    text->normal_text = (char **)  realloc(text->normal_text, text->NUMBER + 1);
    text->arr_str     = (string *) realloc(text->arr_str,     text->NUMBER + 1); 
}

void text_cpy(poem *text, poem *cpy_text) {
    assert(text     != nullptr && "null pointer");
    assert(cpy_text != nullptr && "null pointer");

    cpy_text->NUMBER = text->NUMBER;
    cpy_text->normal_text = (char **) calloc(text->NUMBER + 1, sizeof(char *)); 

    for (int i = 0; (i <= cpy_text->NUMBER); i++)  { 
        cpy_text->normal_text[i] = text->normal_text[i];
    }
    
}

void  sorting_and_print_to_file(poem *text, const char *NAME_OF_FILE)  {
    FILE *file_write = fopen(NAME_OF_FILE, "w");

    assert(file_write != nullptr && "coudn't open file");

    print_header("TEXT SORTED BY FIRST LETTERS", file_write);
    // sort_qsort_first_letter(text);
    // sort_my_qsort_first_letter(text);
    my_bubble_sort(text->arr_str, text->NUMBER, sizeof(string), strcmp_first_letter);
    printing_to_file_arr_string(file_write, text->arr_str, text->NUMBER);

    print_header("TEXT SORTED BY LAST LETTERS", file_write);
    // sort_qsort_last_letter(text);
    // sort_my_qsort_last_letter(text);
    my_bubble_sort(text->arr_str, text->NUMBER, sizeof(string), strcmp_last_letter);
    printing_to_file_arr_string(file_write, text->arr_str, text->NUMBER);

    print_header("SOURCE TEXT", file_write);
    printing_to_file_text(file_write, text);
    print_header("END", file_write);

    fclose(file_write);
    free_text(text);
}


void printing_to_file_arr_string(FILE *file, string *text, int NUMBER) {
    for (int i = 0; i < NUMBER; i++)
        fprintf(file, "%s\n", text[i].string); 
}

void printing_to_file_text(FILE *file, poem *text) {
    for (int i = 0; i < text->NUMBER; i++)
        fprintf(file, "%s\n", text->normal_text[i]); 
}

void print_header(const char* WORD, FILE *file_write) {
    fprintf(file_write, "\n\n\n------------------------------------------------------------\n\n\n");
    fprintf(file_write, "                    %s                        ", WORD);
    fprintf(file_write, "\n\n\n------------------------------------------------------------\n\n\n");
}
