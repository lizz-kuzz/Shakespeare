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

    shakespeare->text = (char *) calloc(SYMBOLS + 1, sizeof(char)); 

    assert(shakespeare->text != nullptr && "null pointer");

    fread(shakespeare->text, sizeof(char), SYMBOLS, file);

    fclose(file);

    text_normalize(shakespeare);
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
    // for (int i = 0; i < text->NUMBER; i++) {
        // free(text->normal_text[i]);
        // printf("%s", text->normal_text[i]);
    // }
    free(text->text);
    free(text->arr_str);
}

void text_normalize(poem *text)  {
    assert(text != nullptr && "null pointer");

    text->NUMBER = num_of_rows(text->text);

    text->arr_str = (string *) calloc (text->NUMBER + 1, sizeof(string));

    assert(text->arr_str != NULL && "null pointer");

   
    char *point = text->text;
    text->arr_str[0].string = point;
    int count = 0;

    for (int i = 1; (i <= text->NUMBER) && *(point) != '\0'; point++)  { 
        if (*point == '\n')  {
            *point = '\0';
            if ((*(point + 1)) == '\n')
                continue;
            if ((*(point + 1)) == ' ' && (*(point + 2)) == ' ' &&
                (*(point + 3)) == ' ' && (*(point + 4)) == ' ')  { 
                text->arr_str[i].string = point + 5;
                point += 4; 
            }
            text->arr_str[i].string = point + 1;
            text->arr_str[i-1].len = strlen(text->arr_str[i-1].string);
            count++;
            i++;
        }
    }
    text->NUMBER = count;
    text->arr_str = (string *) realloc(text->arr_str, (text->NUMBER + 1)*sizeof(string)); 
}

void  sorting_and_print_to_file(poem *text, const char *NAME_OF_FILE)  {
    assert(NAME_OF_FILE != nullptr && "null pointer");

    FILE *file_write = fopen(NAME_OF_FILE, "w");
    if (file_write == NULL)
        printf("Could not open file.\n");

    assert(file_write != nullptr && "coudn't open file");

    print_header("TEXT SORTED BY FIRST LETTERS", file_write);
    sort_qsort_first_letter(text);
    // sort_my_qsort_first_letter(text);
    // my_bubble_sort(text->arr_str, text->NUMBER, sizeof(string), strcmp_first_letter);
    printing_to_file_arr_string(file_write, text->arr_str, text->NUMBER);

    print_header("TEXT SORTED BY LAST LETTERS", file_write);
    // sort_qsort_last_letter(text);
    sort_my_qsort_last_letter(text);
    // my_bubble_sort(text->arr_str, text->NUMBER, sizeof(string), strcmp_last_letter);
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
    for (int i = 0; i < text->NUMBER; i++) {
        fprintf(file, "%s\n", text->text); 
        for (; *text->text != '\0'; text->text++) continue;
        (text->text)++;
    }
}

void print_header(const char* WORD, FILE *file_write) {
    fprintf(file_write, "\n\n\n------------------------------------------------------------\n\n\n");
    fprintf(file_write, "                    %s                        ", WORD);
    fprintf(file_write, "\n\n\n------------------------------------------------------------\n\n\n");
}
