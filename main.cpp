#include <stdio.h>
#include "include.h"

int main()
{
  const char *INPUT_FILE_WITH_TEXT = "C:\\Users\\User\\Desktop\\programs\\shakespeare\\shakespeare.txt";
  const char *OUTPUT_FILE =          "C:\\Users\\User\\Desktop\\programs\\shakespeare\\shakespeare_write.txt";

  poem shakespeare = {
    .poem = NULL,
    .sorting = NULL,
    .NUMBER = 0,
  };

  shakespeare.poem = read_file(INPUT_FILE_WITH_TEXT);  

  assert(shakespeare.poem != NULL && "null pointer");

  text_normalize(&shakespeare);

  sorting_and_print_to_file(&shakespeare, OUTPUT_FILE);

  return 0;

}