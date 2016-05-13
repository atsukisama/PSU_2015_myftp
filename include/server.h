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


# define ALLCMD "USER PASS CWD  CDUP QUIT DELE PWD  PASV PORT HELP NOOP RETR STOR LIST"

# define LOGIN_OK "331 Please specify the password.\r\n"
# define NEED_LOGIN "530 Please login with USER and PASS.\r\n"
# define WRONG_LOGIN "530 Login incorrect.\r\n"
# define PASS_OK "230 Login successful.\r\n"

typedef struct		s_client
{
  int			logged;
  char			*user;
  char			*pass;
}			m_client;

#endif
