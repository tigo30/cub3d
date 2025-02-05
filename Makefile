# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joandre- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 01:29:41 by joandre-          #+#    #+#              #
#    Updated: 2025/02/05 00:08:13 by joandre-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
CLINK = -L libft -lft -L minilibx-linux -lmlx_Linux \
		-L /usr/lib -I mlx_linux -lXext -lX11 -lm -lz
LIBFT = libft/libft.a
MLX = minilibx-linux/libmlx-Linux.a
NAME = cub3d
SRC = $(shell find src -name *.c)
OBJ = $(SRC:.c=.o)
VFLAG = -s --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(CLINK) -o $(NAME)

$(LIBFT):
	make -sC libft
	make clean -sC libft
$(MLX):
	make -sC minilibx-linux

run: $(NAME)
	valgrind $(VFLAG) ./$(NAME) maps/debug.cub

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	make fclean -sC libft
	make clean -sC minilibx-linux

re: fclean all

rerun: re run
