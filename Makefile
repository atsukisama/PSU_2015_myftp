##
## Makefile for make in /home/kerebel/bin
## 
## Made by kerebe_p
## Login   <kerebe_p@epitech.eu>
## 
## Started on  Fri Dec  5 05:43:19 2014 kerebe_p
## Last update Fri Dec  5 05:43:19 2014 kerebe_p
##

SRC	= ./src/user.c \
	  ./src/pass.c \
	  ./src/pwd.c \
	  ./src/cwd.c \
	  ./src/cdup.c \
	  ./src/quit.c \
	  ./src/dele.c \
	  ./src/pasv.c \
	  ./src/port.c \
	  ./src/help.c \
	  ./src/noop.c \
	  ./src/retr.c \
	  ./src/stor.c \
	  ./src/list.c \
	  ./src/main.c \
	  ./src/client.c \
	  ./src/utils.c \

OBJ	= $(SRC:.c=.o)

NAME	= server

CFLAGS	= -I./include

RM	= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean
