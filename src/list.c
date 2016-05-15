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

void	my_print_list(char *cmd)
{
  char	*path;

  if (cmd == NULL)
    system("ls -la");
  else
    {
      asprintf(&path, "ls -la %s", cmd);
      system(path);
      free(path);
    }
}

int	my_list(char *cmd, t_client *data)
{
  int	old;
  int	fd;

  if (data->mode == 0)
    return (dprintf(data->fd, NO_FD));
  if (data->logged == 2)
    {
      fd = handle_mode_fd(data);
      dprintf(data->fd, LIST_ST);
      if (fd != -1)
	{
	  old = dup(1);
	  dup2(fd, 1);
	  my_print_list(cmd);
	  dup2(old, 1);
	  close(old);
	  shutdown(fd, SHUT_RDWR);
	}
      data->mode = 0;
      shutdown(data->fd_alt, SHUT_RDWR);
      dprintf(data->fd, LIST_ED);
      return (1);
    }
  dprintf(data->fd, NEED_LOGIN);
  return (0);
}
