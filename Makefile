# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 01:29:41 by joandre-          #+#    #+#              #
#    Updated: 2025/03/09 16:45:17 by joandre-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
CLINK = -L libft -lft -L minilibx-linux -lmlx_Linux \
		-L /usr/lib -I mlx_linux -lXext -lX11 -lm -lz
LIBFT = libft/libft.a
MLX = minilibx-linux/libmlx_Linux.a
NAME = cub3d
SRC = src/calculate_map_size.c src/check_characaters.c src/check_empty.c src/check_file.c src/check_map.c src/check_texture.c \
	src/close_program.c src/convert_fifo_to_matriz.c src/convert_rgb.c src/erro.c src/execute.c src/fifo.c src/free_map.c \
	src/get_content.c src/get_map.c src/hooks.c src/init_data.c src/load_data.c src/load_data_util.c src/main.c \
	src/player_movement.c src/ray_utils.c src/raycasting.c src/render.c src/render_utils.c src/validate_map_borders.c \
	src/validate_player.c
OBJ = $(SRC:.c=.o)
VFLAG = -s --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes

all: $(NAME)

$(NAME): $(MLX) $(OBJ) $(LIBFT) 
	$(CC) $(CFLAGS) $(OBJ) $(CLINK) -o $(NAME)

$(LIBFT):
	make -sC libft

$(MLX):
	make -sC minilibx-linux

run: $(NAME)
	valgrind $(VFLAG) ./$(NAME) maps/map0.cub

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	make fclean -sC libft
	make clean -sC minilibx-linux

re: fclean all

rerun: re run
