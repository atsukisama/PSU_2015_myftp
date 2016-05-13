/*
** cmd_one.c for cmd in /home/kerebe_p/Epitech/PSU_2015_myftp
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Wed May 11 10:26:37 2016 kerebe_p
** Last update Wed May 11 10:26:37 2016 kerebe_p
*/

#include <server.h>

int	my_user(char *cmd, m_client *data)
{
  if (strcmp(cmd, "Anonymous") == 0)
    {
      dprintf(data->fd, LOGIN_OK);
      return (1);
    }
  return (0);
}

