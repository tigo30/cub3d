/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 00:04:42 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/09 19:52:10 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include "fifo.h"
# include "raycast.h"
# include <stdbool.h>
# include <fcntl.h>
# include <X11/keysym.h>

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
	void		*init;
	void		*window;
	t_img		display;
	t_map		*map;
	t_ray		*ray;
	t_player	*player;
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
void	calculate_map_size(t_map *map_file);
void	validate_map_borders(t_map *map_file);
void	validate_player(t_map *map);
void	check_map(t_map *map_file);
void	prog_cleanup(t_data *cub);
t_data	*init_data(t_data *cub, t_map *map);
bool	init_libx(t_data *cub);
void	game_loop(t_data *cub);
void	init_player(t_data *cub);
int		check_intersection(float angle, float *inter, float *step, bool flag);
bool	unit_circle(float angle, char c);
bool	wall_hit(float x, float y, t_map *map);
void	raycasting(t_data *cub);
bool	execute(t_data *cub);

#endif
