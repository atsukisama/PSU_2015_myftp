/*
** pass.c for pass in /home/kerebe_p/Epitech/PSU_2015_myftp/src
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Sat May 14 03:31:50 2016 kerebe_p
** Last update Sat May 14 03:31:50 2016 kerebe_p
*/

#include <server.h>

int	my_pass(char *cmd, t_client *data)
{
  if (data->logged < 1)
    return (dprintf(data->fd, PASS_KO));
  if (strcmp(data->user, "Anonymous") == 0)
    {
      if (cmd != NULL)
	data->pass = strdup(cmd);
      data->logged = 2;
      dprintf(data->fd, PASS_OK);
      return (1);
    }
  dprintf(data->fd, LOGIN_KO);
  return (0);
}
