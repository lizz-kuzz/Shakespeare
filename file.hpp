#ifndef FILE_HPP_INCLUDED
#define FILE_HPP_INCLUDED

#include "utils.hpp"

void  read_file                  (const char *TEXT, poem *shakespeare);

void  text_normalize             (poem *text);

void  printing_to_file_text      (FILE *file, poem *text);
void  printing_to_file_arr_string(FILE *file, string *text, int NUMBER);

void  print_header               (const char* WORD, FILE *file_write);
void  sorting_and_print_to_file  (poem *text, const char *NAME_OF_FILE);

#endif