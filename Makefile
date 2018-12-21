# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/08 00:34:43 by beduroul     #+#   ##    ##    #+#        #
#    Updated: 2018/11/14 16:55:26 by beduroul    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Werror -Wextra -Wall

SRCS = srcs/fill_main.c		\
		srcs/fill_error.c 	\
		srcs/fill_solver.c 	\
		srcs/fill_read.c	\
		srcs/fill_map.c		\
		srcs/fill_place.c

LIBS = libft/libft.a

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@$(CC) $(LIBS) $(OBJ) -o $@
%.o: %.c
	@gcc $(CFLAGS) -o $@ -c $<
clean:
	@rm -f $(OBJ)
	@cd libft && $(MAKE) clean

fclean: clean
	@rm -f $(NAME)
	@cd libft && $(MAKE) fclean

re: fclean all