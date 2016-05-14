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

void	cmd_func_set(int (*cmd[N_CMD])(char *, m_client *))
{
  cmd[0] = &my_user;
  cmd[1] = &my_pass;
  //
  cmd[4] = &my_quit;
  cmd[6] = &my_pwd;
  //
}

int	cmd_init(char *cmd, char cmd_list[N_CMD + 1][L_CMD])
{
  int	i;

  i = 0;
  if (cmd == NULL)
    return (-1);
  while (i < N_CMD)
    {
      if (strcmp(cmd, cmd_list[i]) == 0)
	return (i);
      i++;
    }
  return (-1);
}

void	cmd_set(char cmd[N_CMD][L_CMD])
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
}
