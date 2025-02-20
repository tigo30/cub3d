/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 00:04:42 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/20 02:47:20 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "fifo.h"
# include "raycast.h"
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
	int		width;
	int		height;
}	t_img;

typedef struct s_texture
{
	t_img	no;
	t_img	so;
	t_img	ea;
	t_img	we;
}	t_texture;

typedef struct s_data
{
	void		*init;
	void		*window;
	t_img		display;
	t_map		*map;
	t_texture	*wall;
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
void	close_program(t_data *cub);
bool	load_data(t_data *cub);
void	init_data(t_data *cub, char *filename);
void	hooks(t_data *cub);
void	raycasting(t_data *cub);
void	draw_pixel(t_img *image, int x, int y, int color);
int		reverse_bytes(int c);
t_img	*get_texture(t_ray *ray, t_texture *tex);
void	render(t_data *cub);
bool	execute(t_data *cub);
// DEBUG
void	print_map_matrix(char **matrix, int height);
void	print_map_info(t_map *map_file);
void	print_texture(t_img *wall);
void	print_ray_data(t_ray *ray);
void	print_player_data(t_player *player);
void	print_data(t_data *cub);

#endif
