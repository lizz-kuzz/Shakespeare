#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include <assert.h>

int main()
{
  const char *INPUT_FILE_WITH_TEXT = "C:\\Users\\User\\Desktop\\programs\\shakespeare\\shakespeare.txt";
  const char *OUTPUT_TEXT_TO_FILE = "C:\\Users\\User\\Desktop\\programs\\shakespeare\\shakespeare_write.txt";
                        
  FILE *file = fopen(INPUT_FILE_WITH_TEXT, "r");

  if (file == NULL)
    printf("Could not open file.\n");
                        
  const int NUMBER = num_of_rows(file);
  const int SIMBOLS = count_simvols(file);

  char *shakespeare = (char *) calloc(SIMBOLS + 1, sizeof(char));  
  char *point_shakespeare = shakespeare;
                    
  fread(shakespeare, sizeof(char), SIMBOLS, file);
  fclose(file);

  char **normal_sorting_shakespeare = (char **) calloc(NUMBER + 1, sizeof(char *));
  char **save_point_shakespeare = (char **) calloc(NUMBER + 1, sizeof(char *));

  assert(normal_sorting_shakespeare != NULL);

  normal_sorting_shakespeare[0] = point_shakespeare; 
  save_point_shakespeare[0] = point_shakespeare;
                    

  for (int i = 1; (i <= NUMBER); point_shakespeare++)
  {
    if (*point_shakespeare == '\n')
    {
      *point_shakespeare = '\0';
      normal_sorting_shakespeare[i] = point_shakespeare + 1;
      save_point_shakespeare[i] = point_shakespeare + 1;
      i++;
    }
  }

                    
                    // for (int i = 0; (i < NUMBER); i++)
                    //   printf("%s\n\n", sorting_shakespeare[i]);

  normal_sorting(normal_sorting_shakespeare, NUMBER);
  unnormal_sorting(normal_sorting_shakespeare, NUMBER);
                  
                        
  FILE *file_write = fopen(OUTPUT_TEXT_TO_FILE, "w");

  for (int i = 0; i < NUMBER; i++)
    fprintf(file_write, "%s\n", save_point_shakespeare[i]); 

  fclose(file_write);

  free(shakespeare);
  free(normal_sorting_shakespeare);
  free(save_point_shakespeare);
  return 0;

}