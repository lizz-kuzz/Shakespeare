#include "file.hpp"
#include "sort.hpp"



int main() { 
  const char *INPUT_FILE_WITH_TEXT = "C:\\Users\\User\\Desktop\\programs\\shakespeare\\shakespeare1.txt";
  const char *OUTPUT_FILE =          "C:\\Users\\User\\Desktop\\programs\\shakespeare\\shakespeare_write.txt";

  poem shakespeare = {
    .text = NULL,
    .arr_str = NULL,
    .NUMBER = 0,
  };

  read_file(INPUT_FILE_WITH_TEXT, &shakespeare);  

  sorting_and_print_to_file(&shakespeare, OUTPUT_FILE);


  return 0;

}