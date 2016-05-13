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

int		handle_cmd(int client_fd, m_client data)
{
  int		cmd_type;
  char		cmd[4096];
  int		(*test[14])(char *, m_client *);


  cmd_type = 0;
  dprintf(client_fd, "220 Welcome !\r\n");
  data.fd = client_fd;
  while (cmd_type != 1)
    {
      bzero(cmd, 4096);
      read(client_fd, cmd, 4095);
      cmd_type = cmd_init(strtok(cmd, " \t\n"), data.cmd_list);
      if (cmd_type == -1)
      	dprintf(client_fd, "UNKNOW\r\n");
      else
      	data.cmd[cmd_type](strtok(NULL, " \t\n"), &data);
    }
  return (cmd_type);
}

int		handle_clients(int s_fd, struct sockaddr_in *s_in, char *path)
{
  struct sockaddr_in	s_in_client;
  socklen_t		s_in_size;
  m_client		client_base;
  int			c_fd;
  int			pid;

  cmd_set(client_base.cmd_list);
  cmd_func_set(client_base.cmd);
  client_base.path = path;
  while (COFFE_IS_HOT)
    {
      c_fd = accept(s_fd, (struct sockaddr *)&s_in_client, &s_in_size);
      if (c_fd != -1)
	{
	  if ((pid = fork()) == 0)
	    handle_cmd(c_fd, client_base);
	  else
	    close(c_fd);
	}
    }
  return (0);
}

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

int    		create_server(int port, char *path)
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
  handle_clients(fd, &s_in, path);
  return (0);
}

int		main(int ac, char **av)
{
  if (ac == 3)
    create_server(atoi(av[1]), av[2]);
  return (0);
}
