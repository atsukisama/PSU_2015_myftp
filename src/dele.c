/*
** list.c for list in /home/kerebe_p/Epitech/PSU_2015_myftp/src
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Sun May 15 00:09:29 2016 kerebe_p
** Last update Sun May 15 00:09:29 2016 kerebe_p
*/

#include <server.h>

int	my_dele(char *cmd, t_client *data)
{
  char	path[4096];

  bzero(path, 4096);
  if (data->logged < 2)
    return (dprintf(data->fd, NEED_LOGIN));
  if (cmd == NULL)
    return (dprintf(data->fd, NO_ENOUGH));
  if (remove(cmd) != -1)
    return (dprintf(data->fd, DELE_OK));
  dprintf(data->fd, DELE_KO);
  return (0);
}
