/*
** main.c for main in /home/kerebe_p/Epitech/PSU_2015_myftp
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Mon May  9 16:04:07 2016 kerebe_p
** Last update Mon May  9 16:04:07 2016 kerebe_p
*/

#include <server.h>

int		handle_cmd(int client_fd)
{
  int		cmd_type;

  cmd_type = 0;
  dprintf(client_fd, "220 Welcome !\r\n");
  while (cmd_type != 1)
    {
      /* bla bla bla */
    }
  return (cmd_type);
}

int		handle_clients(int s_fd, struct sockaddr_in *s_in)
{
  struct sockaddr_in	s_in_client;
  socklen_t		s_in_size;
  int			c_fd;
  int			pid;

  while (COFFE_IS_HOT)
    {
      c_fd = accept(s_fd, (struct sockaddr *)&s_in_client, &s_in_size);
      if (c_fd != -1)
	{
	  if ((pid = fork()) == 0)
	    handle_cmd(c_fd);
	  else
	    close(c_fd);
	}
    }
  return (0);
}

int			bind_server(int fd, struct sockaddr_in *s_in)
{
 if (bind(fd, (const struct sockaddr *)s_in, sizeof(*s_in)) == -1)
    {
      if (close(fd) == -1)
	return (1);
      return (1);
    }
 return (0);
}

int			listen_server(int fd, int nbr_client_max)
{
  if (listen(fd, nbr_client_max) == -1)
    {
      if (close(fd) == -1)
	return (1);
      return (1);
    }
  return (0);
}

int			create_server(int port, char *path)
{
  struct protoent	*pe;
  struct sockaddr_in	s_in;
  int			fd;

  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = INADDR_ANY;
  if (!(pe = getprotobyname("TCP")))
    return (1);
  if ((fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (1);
  if (bind_server(fd, &s_in) > 0 || listen_server(fd, MAX_CLIENT) > 0)
    return (1);
  handle_clients(fd, &s_in);
  return (0);
}

int		main(int ac, char **av)
{
  if (ac == 3)
    create_server(atoi(av[1]), av[2]);
  return (0);
}
