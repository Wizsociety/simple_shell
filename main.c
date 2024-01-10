#include "shell.h"

/**
 * main - function that checks if our shell is called
 * determines if file descriptor is associated with a terminal
 * Return: 0 on success
 */

int main(void)
{
 if (isatty(STDIN_FILENO) == 1)
 {
  shell_interactive();
 }
 else
 {
  shell_non_interactive();
 }
 return (0);
}

