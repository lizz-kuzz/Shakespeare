#include "../include/file.hpp"
#include "../include/sort.hpp"

int main() { 
  const char *INPUT_FILE_WITH_TEXT = "/mnt/c/Users/User/Desktop/programs/shakespeare/res/shakespeare.txt";
  const char *OUTPUT_FILE =          "/mnt/c/Users/User/Desktop/programs/shakespeare/res/shakespeare_write.txt";

  poem shakespeare = {
    .text = NULL,
    .arr_str = NULL,
    .NUMBER = 0,
  };

  read_file(INPUT_FILE_WITH_TEXT, &shakespeare);  
  
  sorting_and_print_to_file(&shakespeare, OUTPUT_FILE);

  return 0;

}