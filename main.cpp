#include <stdio.h>
#include "include.h"

int main()
{
  poem shakespeare = {
    .poem = NULL,
    .sorting = NULL,
    .NUMBER = 0,
  };

  shakespeare.poem = read_file();  

  assert(shakespeare.poem != NULL && "null pointer");

  text_normalize(&shakespeare);

  sorting_and_print_to_file(&shakespeare);

  // char *arr[2] = {"for", "For"};
  // char **arr_1 = arr;
  // sort_first_letter(arr_1, 2);
  // printf("\n%s\n%s\n" , arr[0], arr[1]);
  // return 0;

}