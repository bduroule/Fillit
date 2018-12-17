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

.PHONY: clean all re fclean

NAME 	= fillit
LIB 	= $(LIB_PATH)/libft.a

#Compil
CC 		= gcc
CFLAGS 	= -Wall -Werror -Wextra

#File
SRC_N 	= 	fill_main.c		\
			fill_error.c 	\
			fill_solver.c 	\
			fill_read.c		\
			fill_map.c		\
			fill_place.c
			
INC_N 	= fillit.h
SRC 	= $(addprefix $(SRC_PATH)/, $(SRC_N))
INC 	= $(addprefix $(INC_PATH)/, $(INC_N))
OBJ		= $(addprefix $(OBJ_PATH)/, $(SRC_N:.c=.o))

#Path
SRC_PATH = ./srcs
INC_PATH = ./include
LIB_PATH = ./libft
OBJ_PATH = ./obj

#Color
GREEN 	= \e[92m
END 	= \e[97m
END2	= \e[0m
GREEN2	= \e[92;7m
OK 		= $(GREEN)[ok]$(END)

all: obj $(NAME) 

$(NAME) : $(OBJ)
	@make -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $(LIB) $(OBJ) -o $(NAME)
	@printf "compilling ($(NAME))........................................... $(OK)\n"

obj:
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c 
	@$(CC) $(CFLAGS) -I $(INC) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rm -fr $(OBJ_PATH)
	@make -C $(LIB_PATH) clean
	@printf "remove object ($(NAME))........................................ $(OK)\n"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@printf "remove all ($(NAME))........................................... $(OK)\n"

re: fclean all

signatur:
	@printf "$(GREEN)                                        	\n";
	@printf "███████╗  ██╗  ██╗       ██╗       ██╗  ████████╗	\n";
	@printf "██╔════╝  ██║  ██║       ██║       ██║  ╚══██╔══╝	\n";
	@printf "█████╗    ██║  ██║       ██║       ██║     ██║   	\n";
	@printf "██╔══╝    ██║  ██║       ██║       ██║     ██║   	\n";
	@printf "██║       ██║  ███████╗  ███████╗  ██║     ██║   	\n";
	@printf "╚═╝       ╚═╝  ╚══════╝  ╚══════╝  ╚═╝     ╚═╝   	\n";
	@printf "$(END)                                  			\n";