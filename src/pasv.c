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

int			add_socket_pasv(t_client *data)
{
  struct protoent       *pe;
  struct sockaddr_in    s_in;
  socklen_t		l;
  int                   fd;

  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(0);
  s_in.sin_addr.s_addr = INADDR_ANY;
  if (!(pe = getprotobyname("TCP")))
    return (-1);
  if ((fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (-1);
  if (bind_server(fd, &s_in) > 0 || listen_server(fd, 1) > 0)
    return (-1);
  l = sizeof(s_in);
  if (getsockname(fd, (struct sockaddr *)&s_in, &l) == -1)
    return (-1);
  data->fd_alt = fd;
  data->port = ntohs(s_in.sin_port);
  data->mode = 1;
  return (fd);
}

int	my_pasv(char *cmd, t_client *data)
{
  if (data->logged < 2)
    return (dprintf(data->fd, NEED_LOGIN));
  if (add_socket_pasv(data) == -1)
    return (dprintf(data->fd, FAIL_PASV));
  dprintf(data->fd, "%s (%s,%d,%d)\r\n",
	  M_PASV, data->ip, data->port / 256, data->port % 256);
  return (0);
}
