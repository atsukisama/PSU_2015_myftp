/*
** quit.c for quit in /home/kerebe_p/Epitech/PSU_2015_myftp/src
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Sat May 14 16:53:03 2016 kerebe_p
** Last update Sat May 14 16:53:03 2016 kerebe_p
*/

#include <sys/socket.h>
#include <server.h>

int	my_quit(char *cmd, t_client *data)
{
  dprintf(data->fd, MY_QUIT);
  return (0);
}
