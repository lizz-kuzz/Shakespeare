#include <stdio.h>
#include "include.h"

char *read_file()  {
    const char *INPUT_FILE_WITH_TEXT = "C:\\Users\\User\\Desktop\\programs\\shakespeare\\shakespeare.txt";

    FILE *file = fopen(INPUT_FILE_WITH_TEXT, "r");

    assert(file != nullptr && "coudn't open file");

    if (file == NULL)
        printf("Could not open file.\n");
    
    const int SYMBOLS = count_symbols(file);
    char *reading_file = (char *) calloc(SYMBOLS + 1, sizeof(char));  

    fread(reading_file, sizeof(char), SYMBOLS, file);
    fclose(file);

    return reading_file;
}

int num_of_rows(char *text)  {
    int count = 0;

    while (*text != '\0')  {
        if (*text == '\n')
            count++;
        text++;
    }
    return count;
}

int count_symbols(FILE *file)  {

    fseek(file, 0, SEEK_END);

    int number = ftell(file);
    
    fseek(file, 0, SEEK_SET);

    return number;
}

void print_to_file(char **save_point, int count)  {

    const char *NAME_OF_FILE =  "C:\\Users\\User\\Desktop\\programs\\shakespeare\\shakespeare_write.txt";

    FILE *file_write = fopen(NAME_OF_FILE, "w");

    assert(file_write != nullptr && "coudn't open file");

    for (int i = 0; i < count; i++)
        fprintf(file_write, "%s\n", save_point[i]); 
    
    fclose(file_write);
}
// void text_normalize(poem *text)
// {
//     text->NUMBER = num_of_rows(text->poem);



// }


