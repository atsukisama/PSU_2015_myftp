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

int		bind_server(int fd, struct sockaddr_in *s_in)
{
 if (bind(fd, (const struct sockaddr *)s_in, sizeof(*s_in)) == -1)
    {
      if (close(fd) == -1)
	return (1);
      return (1);
    }
 return (0);
}

int	       	listen_server(int fd, int nbr_client_max)
{
  if (listen(fd, nbr_client_max) == -1)
    {
      if (close(fd) == -1)
	return (1);
      return (1);
    }
  return (0);
}

int    		create_server(int port)
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
    {
      chdir(av[2]);
      create_server(atoi(av[1]));
    }
  return (0);
}
