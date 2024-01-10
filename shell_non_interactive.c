#include "shell.h"

/**
 * shell_no_interactive - unix command line interpreter
 *
 * Return: void
 */

void shell_non_interactive(void)
{
 char *command;
 char **args;
 int status = -1;

 do {
  command = read_stream();
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
