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

int	my_noop(char *cmd, t_client *data)
{
  if (data->logged == 2)
    return (dprintf(data->fd, NOOP_OK));
  dprintf(data->fd, NEED_LOGIN);
  return (0);
}
