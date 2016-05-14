/*
** cmd_one.c for cmd in /home/kerebe_p/Epitech/PSU_2015_myftp
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Wed May 11 10:26:37 2016 kerebe_p
** Last update Wed May 11 10:26:37 2016 kerebe_p
*/

#include <server.h>

int	my_user(char *cmd, t_client *data)
{
  if (cmd == NULL)
    return (dprintf(data->fd, DENIED));
  free(data->user);
  data->user = strdup(cmd);
  data->logged = 1;
  dprintf(data->fd, LOGIN_OK);
  if (data->logged == 2)
    dprintf(data->fd, LOGIN_CHANGE);
  return (0);
}

