/*
** pwd.c for pwd in /home/kerebe_p/Epitech/PSU_2015_myftp/src
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Sat May 14 16:41:20 2016 kerebe_p
** Last update Sat May 14 16:41:20 2016 kerebe_p
*/

#include <server.h>

int	my_pwd(char *cmd, t_client *data)
{
  char	path[4096];

  bzero(path, 4096);
  if (data->logged == 2)
    {
      dprintf(data->fd, "257 \"");
      getcwd(path, 4094);
      path[4095] = '\n';
      /* dprintf(data->fd, data->path); */
      dprintf(data->fd, path);
      dprintf(data->fd, "\"\r\n");
      return (1);
    }
  dprintf(data->fd, NEED_LOGIN);
  return (0);
}
