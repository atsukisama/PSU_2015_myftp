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

int	my_list(char *cmd, t_client *data)
{
  int	old;

  if (data->logged == 2)
    {
      old = dup(1);
      dup2(data->fd, 1);
      system("ls");
      dup2(old, 1);
      close(old);
      return (1);
    }
  dprintf(data->fd, NEED_LOGIN);
  return (0);
}
