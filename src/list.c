/*
** list.c for list in /home/kerebe_p/Epitech/PSU_2015_myftp/src
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Sun May 15 00:09:29 2016 kerebe_p
** Last update Sun May 15 00:09:29 2016 kerebe_p
*/

# define _GNU_SOURCE
#include <server.h>

int	my_list(char *cmd, t_client *data)
{
  int	old;
  char	*path;

  if (data->logged == 2)
    {
      dprintf(data->fd, LIST_ST);
      old = dup(1);
      dup2(data->fd, 1);
      if (cmd == NULL)
	system("ls -a");
      else
      	{
      	  asprintf(&path, "ls -a %s", cmd);
      	  system(path);
      	  free(path);
      	}
      dup2(old, 1);
      close(old);
      dprintf(data->fd, LIST_ED);
      return (1);
    }
  dprintf(data->fd, NEED_LOGIN);
  return (0);
}
