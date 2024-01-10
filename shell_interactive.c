#include "shell.h"

/**
 * shell_interactive - UNIX command line interpreter
 * prompt symbol,read the stdin, tokenize
 * avoid memory leaks the exit
 * Return: void
 */

void shell_interactive(void)
{
 char *command;
 char **args;
 int status = -1;

 do {
  printf("Kshell_prompt$ "); 
  command = read_command(); 
  args = tokenize_command(command); 
  status = execute_args(args);
  
  free(command);
  free(args);
  
  if (status >= 0)
  {
   exit(status);
  }
 } while (status == -1);
}

