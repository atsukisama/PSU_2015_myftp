/*
** cdup.c for cduo in /home/kerebe_p/Epitech/PSU_2015_myftp/src
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Sat May 14 22:31:48 2016 kerebe_p
** Last update Sat May 14 22:31:48 2016 kerebe_p
*/

#include <server.h>

int	my_cdup(char *cmd, t_client *data)
{
  if (chdir("..") >= 0)
    {
      dprintf(data->fd, CWD_OK);
      return (1);
    }
  dprintf(data->fd, FAIL_CWD);
  return (0);
}
