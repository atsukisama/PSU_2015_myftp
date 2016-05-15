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
  if (data->logged  < 2)
    return (dprintf(data->fd, NEED_LOGIN));
  if (cmd == NULL)
    return (dprintf(data->fd, NO_ENOUGH));
  if (chdir(cmd) >= 0)
    return (dprintf(data->fd, CWD_OK));
  dprintf(data->fd, FAIL_CWD);
  return (0);
}
