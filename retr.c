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

int	my_retr_file(int fd, char *cmd, t_client *data)
{
  int	file;
  char	buff[4096];
  int	lenght;

  if (access(cmd, F_OK | R_OK) == -1)
    return (dprintf(data->fd, RETR_FAIL));
  if ((file = open(cmd, O_RDONLY)) == -1)
    return (dprintf(data->fd, RETR_FAIL));
  dprintf(data->fd, RETR_ST);
  bzero(buff, 4096);
  while (read(file, buff, 4095) > 0)
    {
      write(fd, buff, strlen(buff));
      bzero(buff, 4096);
    }
  close(file);
  shutdown(fd, SHUT_RDWR);
  dprintf(data->fd, RETR_ED);
  return (0);
}

int	my_retr(char *cmd, t_client *data)
{
  int	fd;

  if (data->logged < 2)
    return (dprintf(data->fd, NEED_LOGIN));
  if (data->mode == 0)
    return (dprintf(data->fd, NO_FD));
  if (cmd == NULL)
    return (dprintf(data->fd, NO_ENOUGH));
  fd = handle_mode_fd(data);
  if (fd != -1)
    {
      my_retr_file(fd, cmd, data);
      data->mode = 0;
      shutdown(data->fd_alt, SHUT_RDWR);
    }
  return (0);
}
