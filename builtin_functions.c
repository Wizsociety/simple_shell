#include "shell.h"

/**
 * own_cd - change current working directory
 * @args: array of strings containing the command and its flags
 * own_exit - exit the shell
 * own_env - display the environment variable
 * own_help - display help message
 * Return: Always returns 1, to continue executing.
 */

int own_cd(char **args)
{
  if (args[1] == NULL)
  {
    fprintf(stderr, "shell: expected argument to \"cd\"\n");
  }
  else
  {
    if (chdir(args[1]) != 0)
    {
      perror("shell");
    }
  }
  return 1;
}

int own_exit(__attribute__((unused)) char **args)
{
  return 0;
}

int own_env(__attribute__((unused)) char **args)
{
  char **env = environ;
  while (*env != NULL)
  {
    printf("%s\n", *env);
    env++;
  }
  return 1;
}

int own_help(__attribute__((unused)) char **args)
{
  printf("Simple Shell\n");
  printf("Built-in commands:\n");
  printf("cd - Change directory\n");
  printf("env - Display environment variables\n");
  printf("help - Display this help message\n");
  printf("exit - Exit the shell\n");
  return 1;
}
