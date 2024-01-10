#include "shell.h"

/**
 * read_stream - read a line from the stream
 *
 * Return: pointer that points the the read line
 */

char *read_stream(void)
{
 int bufersize = 1024;
 int i = 0;
 char *command = malloc(sizeof(char) * bufersize);
 int character;

 if (command == NULL)
 {
  fprintf(stderr, "memory allocation error in read_stream");
  exit(EXIT_FAILURE);
 }
 while (1)
 {
  character = getchar(); 
  if (character == EOF)
  {
   free(command);
   exit(EXIT_SUCCESS);
  }
  else if (character == '\n')
  {
   command[i] = '\0';
   return (command);
  }
  else
  {
   command[i] = character;
  }
  i++;
  if (i >= bufersize)
  {
   bufersize += bufersize;
   command = realloc(command, bufersize);
   if (command == NULL)
   {
    fprintf(stderr, "memory reallocation error in read_stream");
    exit(EXIT_FAILURE);
   }
  }
 }
}

