/*
** my.h for lib in /home/kerebe_p/Epitech/PSU_2015_myftp/src
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Sat May 14 22:31:48 2016 kerebe_p
** Last update Sat May 14 22:31:48 2016 kerebe_p
*/

#ifndef MY_H_
# define MY_H_

int	my_cdup(char *cmd, t_client *data);
void            set_client_data(int client_fd, t_client *data);
void            clean_client(int client_fd, t_client *data);
int             handle_cmd(int client_fd, t_client data);
void	my_set_ip(struct sockaddr_in *s_in_client, t_client *data);
int             handle_clients(int s_fd, struct sockaddr_in *s_in);
int	my_cwd(char *cmd, t_client *data);
int	my_dele(char *cmd, t_client *data);
int	my_help(char *cmd, t_client *data);
void	my_dup_list(int fd, char *cmd);
void	my_print_list(char *cmd);
int	my_list(char *cmd, t_client *data);
int	bind_server(int fd, struct sockaddr_in *s_in);
int	       	listen_server(int fd, int nbr_client_max);
int    	create_server(int port);
int	my_noop(char *cmd, t_client *data);
int	my_pass(char *cmd, t_client *data);
int		add_socket_pasv(t_client *data);
int	my_pasv(char *cmd, t_client *data);
int	my_port(char *cmd, t_client *data);
int	my_pwd(char *cmd, t_client *data);
int	my_quit(char *cmd, t_client *data);
int	my_retr_file(int fd, char *cmd, t_client *data);
int	my_retr(char *cmd, t_client *data);
int	my_stor(char *cmd, t_client *data);
int	my_user(char *cmd, t_client *data);
void	cmd_func_set(int (*cmd[N_CMD])(char *, t_client *));
int	cmd_init(char *cmd, char cmd_list[N_CMD + 1][L_CMD]);
void	cmd_set(char cmd[N_CMD][L_CMD]);
int		handle_mode_fd(t_client *data);

#endif
