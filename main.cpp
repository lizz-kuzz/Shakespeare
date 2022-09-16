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

  // char *arr[] = {"for", "For", "aaa", "AAAA", "Bbb", "Bab"};
  // qsort(arr, sizeof(arr)/sizeof(char*), sizeof(char *), strcmp_first_letter);
  // // sort_first_letter(arr, 6);
  // printf("\n%s\n%s\n%s\n%s\n%s\n%s\n\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);

  return 0;

}