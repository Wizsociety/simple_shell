#include "shell.h"

/**
 * split_line - split a string into multiple strings
 * @line: string to be splited
 * handle comments and symbols
 * Return: pointer that points to the new array
 */

char **tokenize_command(char *command)
{
 int bufersize = 64;
 int i = 0;
 char **tokens = malloc(bufersize * sizeof(char *));
 char *token;

 if (!tokens)
 {
  fprintf(stderr, "memory allocation error in split_line: tokens\n");
  exit(EXIT_FAILURE);
 }
 token = strtok(command, TOK_DELIM);
 while (token != NULL)
 {
  if (token[0] == '#')
  {
   break;
  }
  tokens[i] = token;
  i++;
  if (i >= bufersize)
  {
   bufersize += bufersize;
   tokens = realloc(tokens, bufersize * sizeof(char *));
   if (!tokens)
   {
    fprintf(stderr, "memory reallocation error in split_line: tokens");
    exit(EXIT_FAILURE);
   }
  }
  token = strtok(NULL, TOK_DELIM);
 }
 tokens[i] = NULL;
 return (tokens);
}
