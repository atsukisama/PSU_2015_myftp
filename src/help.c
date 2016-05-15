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

int	my_help(char *cmd, t_client *data)
{
  if (data->logged == 2)
    {
      dprintf(data->fd, HELP_ST);
      dprintf(data->fd, MY_HELP);
      dprintf(data->fd, HELP_ED);
      return (1);
    }
  dprintf(data->fd, NEED_LOGIN);
  return (0);
}
