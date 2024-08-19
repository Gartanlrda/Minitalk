# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 12:05:39 by ggoy              #+#    #+#              #
#    Updated: 2024/08/19 15:02:44 by ggoy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#######################       ARGUMENTS         ################################
################################################################################

NAME		= libft.a
CFLAGS		= -Wall -Wextra -Werror
CC			= @ cc

################################################################################
#######################         SOURCES         ################################
################################################################################

SRC_FILES	= ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		get_next_line.c\
		get_next_line_utils.c\
		ft_utils1.c\
		ft_printf.c


SRC_FILES_BONUS = $(SRC_FILES)\
		ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c

OBJ_FILES	= $(SRC_FILES:.c=.o)

OBJ_FILES_BONUS = $(SRC_FILES_BONUS:.c=.o)

################################################################################
#######################          RULES          ################################
################################################################################

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@ ar rcs $(NAME) $(OBJ_FILES)

bonus: $(OBJ_FILES_BONUS)
	@ ar rcs $(NAME) $(OBJ_FILES_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@ rm -f $(OBJ_FILES) $(OBJ_FILES_BONUS)

fclean: clean
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
