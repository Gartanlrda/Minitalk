# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 12:05:39 by ggoy              #+#    #+#              #
#    Updated: 2024/08/20 12:47:18 by ggoy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#######################       ARGUMENTS         ################################
################################################################################

NAME_SERVER	= server
NAME_CLIENT = client
CFLAGS		= -Wall -Wextra -Werror #-fsanitize=address -g3
LIBFT_FLAGS	= -L./libft -lft
CC			= @cc
################################################################################
#######################         SOURCES         ################################
################################################################################

SRC_FILES_SERVER	= main_server.c\
						utils.c

SRC_FILES_CLIENT	= main_client.c

OBJ_FILES_SERVER	= $(SRC_FILES_SERVER:.c=.o)

OBJ_FILES_CLIENT	= $(SRC_FILES_CLIENT:.c=.o)

################################################################################
#######################          RULES          ################################
################################################################################


all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): libft/libft.a $(OBJ_FILES_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_FILES_SERVER) $(LIBFT_FLAGS)

$(NAME_CLIENT): $(OBJ_FILES_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_FILES_CLIENT) $(LIBFT_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

libft/libft.a:
	@ make -C ./libft bonus

clean:
	@ rm -f $(OBJ_FILES_CLIENT)
	@ rm -f $(OBJ_FILES_SERVER)

fclean: clean
	@ rm -f $(NAME_SERVER)
	@ rm -f $(NAME_CLIENT)
	@ make -C ./libft fclean

re:  fclean all

.PHONY: all clean fclean re
