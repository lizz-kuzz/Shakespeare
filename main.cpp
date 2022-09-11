#include <stdio.h>
#include "include.h"


int main()
{
  const char *INPUT_FILE_WITH_TEXT = "C:\\Users\\User\\Desktop\\programs\\shakespeare\\shakespeare.txt";
  const char *OUTPUT_TEXT_TO_FILE =  "C:\\Users\\User\\Desktop\\programs\\shakespeare\\shakespeare_write.txt";
                        
  FILE *file = fopen(INPUT_FILE_WITH_TEXT, "r");

  assert(file != nullptr && "coudn't open file");

  if (file == NULL)
    printf("Could not open file.\n");
                        
  const int NUMBER =  num_of_rows(file);
  const int SIMBOLS = count_simvols(file);

  char *shakespeare =             (char *) calloc(SIMBOLS + 1, sizeof(char));  
  char **sorting_shakespeare =    (char **) calloc(NUMBER + 1, sizeof(char *));
  char **save_point_shakespeare = (char **) calloc(NUMBER + 1, sizeof(char *)); 

  fread(shakespeare, sizeof(char), SIMBOLS, file);
  fclose(file);


  assert(shakespeare != NULL && "null pointer");
  assert(sorting_shakespeare != NULL && "null pointer");
  assert(save_point_shakespeare != NULL && "null pointer");

  char *point_shakespeare = shakespeare;
  sorting_shakespeare[0] = point_shakespeare; 
  save_point_shakespeare[0] = point_shakespeare;
 
  printf("%d\n", isalpha('\''));

  int count = 0;
  for (int i = 1; (i <= NUMBER) && *(point_shakespeare + 1) != '\0'; point_shakespeare++)  { 
    if (*point_shakespeare == '\n')  {
      *point_shakespeare = '\0';

      save_point_shakespeare[i] = point_shakespeare + 1;

      if ((*(point_shakespeare + 1)) == '\n')
        continue;
      
  
      if ((*(point_shakespeare + 1)) == ' ' && (*(point_shakespeare + 2)) == ' ' &&
          (*(point_shakespeare + 3)) == ' ' && (*(point_shakespeare + 4)) == ' ')  { 
            sorting_shakespeare[i] = point_shakespeare + 5;
            point_shakespeare += 4;
          }

      count++;
      sorting_shakespeare[i] = point_shakespeare + 1;

      i++;
    }
  }

  normal_sorting(sorting_shakespeare, count);
  unnormal_sorting(sorting_shakespeare, count);

  print_to_file(save_point_shakespeare, count, OUTPUT_TEXT_TO_FILE);

  free(shakespeare);
  free(sorting_shakespeare);
  free(save_point_shakespeare);

  return 0;

}