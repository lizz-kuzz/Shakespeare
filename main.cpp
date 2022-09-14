#include <stdio.h>
#include "include.h"

int main()
{
  poem shakespeare = {
    .poem = NULL,
    .sorting_begin= NULL,
    .sorting_end= NULL,
    .save_point = NULL,
    .NUMBER = 0,
  };

  shakespeare.poem = read_file();  

  assert(shakespeare.poem != NULL && "null pointer");

  text_normalize(&shakespeare);

  normal_sorting(shakespeare.sorting_begin, shakespeare.NUMBER);
  unnormal_sorting(shakespeare.sorting_end, shakespeare.NUMBER);

  print_to_file(&shakespeare);

  return 0;

}