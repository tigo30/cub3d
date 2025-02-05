/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 00:04:42 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/05 00:43:05 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include "fifo.h"
# include "game.h"
# include <fcntl.h>
# include <X11/keysym.h>

# define LOOK_LEFT  65361 
# define LOOK_RIGHT 65363
# define UP 119 
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define EXIT 65307

# define HEIGHT 800
# define WIDTH 600
# define TILE_SIZE 64

typedef struct s_map
{
	char	**matriz;
	int		width;
	int		height;
	char	*texture_no;
	char	*texture_so;
	char	*texture_we;
	char	*texture_ea;
	int		ceil_color;
	int		floor_color;
	char	player_direction;
	int		player_x;
	int		player_y;
	t_fifo	*file_content;
}	t_map;

typedef struct s_coord
{
	int	y;
	int	x;
}	t_coord;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*init;
	void	*window;
	t_img	display;
	t_map	*map;
}	t_data;

void	error(char *error);
void	check_file(char *filename);
int		open_file(char *filename);
void	check_textures(t_map *map_file);
t_map	*get_map(char *filename);
int		convert_rgb(char *texture);
void	free_map(t_map *map_file);
void	init_map_file(t_map *map_file);
int		has_non_space(char *nbr);
t_fifo	*get_file_content(char *filename);
char	**convert_fifo_to_matriz(t_fifo *file_content);
void	prog_cleanup(t_data *data);
t_data	*init_data(t_data *data, t_map *map);
bool	init_libx(t_data *data);
void	game_loop(t_data *data);
void	calculate_map_size(t_map *map_file);
void	validate_map_borders(t_map *map_file);
void	validate_player(t_map *map);
void	check_map(t_map *map_file);

#endif
