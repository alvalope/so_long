# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 13:43:51 by alvalope          #+#    #+#              #
#    Updated: 2023/05/13 14:55:55 by alvalope         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SO_LONG = so_long.a

LIBFT_PATH = ./libft_plus

LIBFT = $(LIBFT_PATH)/libft.a

MINILIBX_PATH = ./mlx

MINILIBX = $(MINILIBX_PATH)/libmlx.a

HEADER = ft_so_long.h $(LIBFT_PATH)/libft.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FRAMEWORK = -framework OpenGL -framework AppKit

SRCS = ft_so_long.c ft_check_map.c ft_create_window.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

LIB = ar rcs

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX) $(HEADER)
	$(LIB) $(SO_LONG) $(OBJS)
	$(CC) $(CFLAGS) $(SO_LONG) $(LIBFT) $(MINILIBX) $(FRAMEWORK) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(MINILIBX):
	make -C $(MINILIBX_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(MINILIBX_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME) $(SO_LONG)

game: all clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(SO_LONG)
	
re: fclean all

.PHONY: all clean fclean re