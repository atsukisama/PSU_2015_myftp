/*
** cmd.h for main in /home/kerebe_p/Epitech/PSU_2015_myftp
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Wed May 11 15:34:20 2016 kerebe_p
** Last update Wed May 11 15:34:20 2016 kerebe_p
*/

#ifndef _CMD_H_
# define _CMD_H_

#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

# define MAX_CLIENT 42
# define COFFE_IS_HOT 42

# define N_CMD 14
# define L_CMD 5
# define ALLCMD "USER PASS CWD  CDUP QUIT DELE PWD  PASV PORT HELP NOOP RETR STOR LIST"

# define LOGIN_OK "331 Please specify the password.\r\n"
# define NEED_LOGIN "530 Please login with USER and PASS.\r\n"
# define WRONG_LOGIN "530 Login incorrect.\r\n"
# define PASS_OK "230 Login successful.\r\n"
# define PASS_KO "503 Login with USER first.\r\n"
# define LOGIN_CHANGE "530 Can't change from guest user.\r\n"
# define DENIED "530 Permission denied.\r\n"
# define MY_QUIT "221 Goodbye.\r\n"
# define LOGIN_KO "530 Login incorrect.\r\n"
# define NO_ENOUGH "501 Not enough arguments.\r\n"
# define FAIL_CWD "550 Failed to change directory.\r\n"
# define CWD_OK "250 Directory successfully changed.\r\n"
# define NOOP_OK "200 NOOP ok.\r\n"
# define DELE_OK "250 DELE command successful.\r\n"
# define DELE_KO "550 Failed to delete file.\r\n"
# define HELP_ST "214-The following commands are recognized.\r\n"
# define MY_HELP "USER\tPASS\tCWD\tCDUP\tQUIT\tDELE\tPWD\r\nPASV\tPORT\tHELP\tNOOP\tRETR\tSTOR\tLIST\r\n"
# define HELP_ED "214 Help OK.\r\n"

typedef struct		s_client
{
  int			fd;
  char			cmd_list[N_CMD + 1][L_CMD];
  int			(*cmd[N_CMD])(char *, struct s_client *);
  int			logged;
  char			*user;
  char			*pass;
}			t_client;

#include "../src/my.h"

#endif
