#include <stdio.h>
#include "include.h"
#include <math.h>

int main()
{
  poem shakespeare = {
    .poem = NULL,
    .sorting_poem = NULL,
    .save_point_poem = NULL,
    .NUMBER = 0,
  };

  shakespeare.poem = read_file();  // работает

  assert(shakespeare.poem != NULL && "null pointer");

  printf("fghgfd\n");
  // text_normalize(&shakespeare);
  shakespeare.NUMBER = num_of_rows(shakespeare.poem);

  // const int NUMBER = num_of_rows(shakespeare);  //work  


  // char **sorting_shakespeare =    (char **) calloc(NUMBER + 1, sizeof(char *));
  // char **save_point_shakespeare = (char **) calloc(NUMBER + 1, sizeof(char *)); 

  // assert(sorting_shakespeare != NULL && "null pointer");
  // assert(save_point_shakespeare != NULL && "null pointer");

 

 

  shakespeare.sorting_poem  =    (char **) calloc(shakespeare.NUMBER + 1, sizeof(char *));
  shakespeare.save_point_poem =  (char **) calloc(shakespeare.NUMBER + 1, sizeof(char *)); 

  // fread(shakespeare, sizeof(char), SIMBOLS, file);
  // fclose(file);

/* исправить надо эти вещи

  Text* text = (Text*) calloc(1, sizeof(Text));
  Text_Ctor(text, shakespeare);
  {
   text->str_ptrs = (char**) calloc(fdsafsda, sizeof(char)); 
  }
*/



  char *point_shakespeare = shakespeare.poem;
  shakespeare.sorting_poem[0] = point_shakespeare; 
  shakespeare.save_point_poem[0] = point_shakespeare;
 
 

  int count = 0;
  for (int i = 1; (i <= shakespeare.NUMBER) && *(point_shakespeare) != '\0'; point_shakespeare++)  { 
    if (*point_shakespeare == '\n')  {
      *point_shakespeare = '\0';

      shakespeare.save_point_poem[i] = point_shakespeare + 1;

      if ((*(point_shakespeare + 1)) == '\n')
        continue;
      
  
      if ((*(point_shakespeare + 1)) == ' ' && (*(point_shakespeare + 2)) == ' ' &&
          (*(point_shakespeare + 3)) == ' ' && (*(point_shakespeare + 4)) == ' ')  { 
            shakespeare.sorting_poem[i] = point_shakespeare + 5;
            point_shakespeare += 4;
          }

      count++;
      shakespeare.sorting_poem[i] = point_shakespeare + 1;

      i++;
    }
  }

  normal_sorting(shakespeare.sorting_poem, count);
  unnormal_sorting(shakespeare.sorting_poem, count);

  print_to_file(shakespeare.save_point_poem, count);

  free(shakespeare.sorting_poem);
  free(shakespeare.poem);
  free(shakespeare.save_point_poem);
  printf("fghg"); 
  return 0;

}