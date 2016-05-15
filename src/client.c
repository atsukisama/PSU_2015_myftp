/*
** client.c for client in /home/kerebe_p/Epitech/PSU_2015_myftp/src
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Sun May 15 02:05:17 2016 kerebe_p
** Last update Sun May 15 02:05:17 2016 kerebe_p
*/

#include <server.h>

void            set_client_data(int client_fd, t_client *data)
{
  char		*new;

  data->logged = 0;
  data->mode = 0;
  data->user = NULL;
  data->pass = NULL;
  data->fd_alt = -1;
  data->port = -1;
  data->fd = client_fd;
}

void            clean_client(int client_fd, t_client *data)
{
  free(data->user);
  free(data->pass);
  shutdown(client_fd, SHUT_RDWR);
}

int             handle_cmd(int client_fd, t_client data)
{
  FILE          *fd;
  size_t        cmd_type;
  char          *cmd;

  cmd_type = 0;
  dprintf(client_fd, "220 Welcome %s !\r\n", data.ip);
  set_client_data(client_fd, &data);
  fd = fdopen(client_fd, "rw");
  while (cmd_type != 4)
    {
      cmd = NULL;
      if (getline(&cmd, &cmd_type, fd) > 0)
	{
	  cmd_type = cmd_init(strtok(cmd, " \t\r\n"), data.cmd_list);
	  if (cmd_type == -1)
	    dprintf(client_fd, "500 Unknown command.\r\n");
	  else
	    data.cmd[cmd_type](strtok(NULL, " \t\r\n"), &data);
	  free(cmd);
	}
      else
	cmd_type = 4;
    }
  clean_client(client_fd, &data);
  return (0);
}

void		my_set_ip(struct sockaddr_in *s_in_client, t_client *data)
{
  int		i;
  char		*my_ip;

  i = 0;
  my_ip = inet_ntoa(s_in_client->sin_addr);
  bzero(data->ip, 16);
  strcpy(data->ip, my_ip);
  while (data->ip[i])
    {
      if (data->ip[i] == '.')
	data->ip[i] = ',';
      i++;
    }
}

int             handle_clients(int s_fd, struct sockaddr_in *s_in)
{
  struct sockaddr_in    s_in_client;
  socklen_t             s_in_size;
  t_client              client_base;
  int                   c_fd;
  int                   pid;

  cmd_set(client_base.cmd_list);
  cmd_func_set(client_base.cmd);
  s_in_size = sizeof(s_in_client);
  while (COFFE_IS_HOT)
    {
      c_fd = accept(s_fd, (struct sockaddr *)&s_in_client, &s_in_size);
      if (c_fd != -1)
	{
	  my_set_ip(&s_in_client, &client_base);
	  if ((pid = fork()) == 0)
	    handle_cmd(c_fd, client_base);
	  else
	    close(c_fd);
	}
    }
  return (0);
}
