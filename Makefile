# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 13:43:51 by alvalope          #+#    #+#              #
#    Updated: 2023/05/15 12:04:02 by alvalope         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

SO_LONG = so_long.a

SO_LONG_BONUS = so_long_bonus.a

LIBFT_PATH = ./libft_plus

LIBFT = $(LIBFT_PATH)/libft.a

MINILIBX_PATH = ./mlx

MINILIBX = $(MINILIBX_PATH)/libmlx.a

MINILIBX2 = ./MLX42/libmlx42.a

HEADER = ft_so_long.h $(LIBFT_PATH)/libft.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FRAMEWORK = -framework OpenGL -framework AppKit

SRCS = ft_so_long.c ft_check_map.c ft_create_window.c ft_moves.c ft_keypress.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = ft_so_long_bonus.c ft_check_map_bonus.c ft_create_window_bonus.c \
	ft_moves_bonus.c ft_keypress_bonus.c ft_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

RM = rm -f

LIB = ar rcs

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX) $(HEADER)
	$(LIB) $(SO_LONG) $(OBJS)
	$(CC) $(CFLAGS) $(SO_LONG) $(LIBFT) $(MINILIBX) $(FRAMEWORK) -o $(NAME)

bonus: $(BONUS_OBJS) $(LIBFT) $(MINILIBX)
	$(LIB) $(SO_LONG_BONUS) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(SO_LONG_BONUS) $(LIBFT) $(MINILIBX) $(FRAMEWORK) -o $(NAME_BONUS)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(MINILIBX):
	@make -C $(MINILIBX_PATH) all

help:
	@echo "\nPrueba make game o make game_bonus para crear los ejecutables \
	y luego para ejecutarlos ./so_long mapa o ./so_long_bonus mapa\n"

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(MINILIBX_PATH) clean
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME) $(NAME_BONUS) $(SO_LONG) $(SO_LONG_BONUS)

game: all clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(SO_LONG)

game_bonus: bonus clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(SO_LONG) $(SO_LONG_BONUS)
	
test: all
	cp $(MINILIBX) libmlx.a
	cp $(LIBFT) libft.a
	make fclean

re: fclean all

.PHONY: all clean fclean re help