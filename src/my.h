/*
** my.h for lib in /home/kerebe_p/Epitech/PSU_2015_myftp/src
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Mon May  9 16:04:07 2016 kerebe_p
** Last update Mon May  9 16:04:07 2016 kerebe_p
*/

#ifndef MY_H_
# define MY_H_

int	handle_cmd(int client_fd, m_client data);
int	handle_clients(int s_fd, struct sockaddr_in *s_in, char *path);
int	bind_server(int fd, struct sockaddr_in *s_in);
int	       	listen_server(int fd, int nbr_client_max);
int    	create_server(int port, char *path);
int	my_user(char *cmd, m_client *data);
void	cmd_func_set(int (*cmd[N_CMD])(char *, m_client *));
int	cmd_init(char *cmd, char cmd_list[N_CMD + 1][L_CMD]);
void	cmd_set(char cmd[N_CMD][L_CMD]);

#endif
