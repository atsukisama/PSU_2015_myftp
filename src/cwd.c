/*
** cwd.c for cwd in /home/kerebe_p/Epitech/PSU_2015_myftp/src
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Sat May 14 19:22:27 2016 kerebe_p
** Last update Sat May 14 19:22:27 2016 kerebe_p
*/

#include <server.h>

int	my_cwd(char *cmd, t_client *data)
{
  if (cmd == NULL)
    return (dprintf(data->fd, NO_ENOUGH));
  if (chdir(cmd) >= 0)
    {
      dprintf(data->fd, CWD_OK);
      /* free(data->path); */
      /* data->path = strdup(cmd); */
      return (1);
    }
  dprintf(data->fd, FAIL_CWD);
  return (0);
}
