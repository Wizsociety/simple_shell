#include "shell.h"

/**
 * read_line - read a line from stdin
 * test for eof and exit 
 * Return: pointer that points to a str with the line content
 */

char *read_command(void)
{
 char *command = NULL;
 size_t bufersize = 0;

 if (getline(&command, &bufersize, stdin) == -1) 
 {
  if (feof(stdin)) 
  {
   free(command); 
   exit(EXIT_SUCCESS); 
  }
  else
  {
   free(command); 
   perror("error while reading the commands from stdin");
   exit(EXIT_FAILURE);
  }
 }
 return (command);
}

