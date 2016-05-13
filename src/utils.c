/*
** test.c for test in /home/kerebe_p/Epitech/PSU_2015_myftp
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Tue May 10 04:39:03 2016 kerebe_p
** Last update Tue May 10 04:39:03 2016 kerebe_p
*/

#include <server.h>

int	cmd_func_set(int (*cmd[14])(char **))
{
  /* cmd[0] = &test; */
}

int	cmd_set(char cmd[14][5])
{
  int	i;

  i = 0;
  strcpy(cmd[0], ALLCMD);
  while (i < strlen(ALLCMD))
    {
      if (cmd[0][i] == ' ')
	cmd[0][i] = '\0';
      i++;
    }
  i = 0;
  return (0);
}
