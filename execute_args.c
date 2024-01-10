#include "shell.h"

/**
 * execute_args - map if command is a builtin or a process
 * @args: command and its flags
 * check for builtin commands
 * Return: 1 on sucess, 0 otherwise
 */

int execute_args(char **args)
{
 char *builtin_func_list[] = {
  "cd",
  "env",
  "help",
  "exit"
 };
 int (*builtin_func[])(char **) = {
  &own_cd,
  &own_env,
  &own_help,
  &own_exit
 };
 int i = 0;

 if (args[0] == NULL)
 {
  return (-1);
 }
 for (; i < (int)(sizeof(builtin_func_list) / sizeof(char *)); i++)
 {
  if (strcmp(args[0], builtin_func_list[i]) == 0)
  {
   return ((*builtin_func[i])(args));
  }
 }
 return (fork_process(args));
}
