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

int	my_user(char **av, int c_fd)
{
  if (strcmp(av[1], "Anonymous") == 0)
    {
      dprintf(c_fd, LOGIN_OK);
      return (1);
    }
  return (0);
}
