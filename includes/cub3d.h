/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 00:04:42 by joandre-          #+#    #+#             */
/*   Updated: 2025/03/09 01:55:49 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "fifo.h"
# include "raycast.h"
# include <fcntl.h>
# include <X11/keysym.h>

# define HEIGHT 600
# define WIDTH 800

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

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

enum e_walls
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

typedef struct s_data
{
	void		*init;
	void		*window;
	int			**frame;
	int			**wall;
	t_map		*map;
	t_ray		*ray;
	t_player	*player;
	t_player	control;
}	t_data;

void	error(char *error);
void	check_file(char *filename);
void	check_empty(t_map *map_file);
int		has_content(char *content);
void	check_characters(t_map *map_file);
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
void	check_characters(t_map *map_file);
void	validate_player(t_map *map);
void	check_map(t_map *map_file);
void	close_program(t_data *cub, bool error);
bool	load_data(t_data *cub, char *filename);
bool	load_image(void *init, t_img *png, char *filename);
int		**init_frame(void);
void	init_data(t_data *cub);
int		player_movement(int keysym, t_data *cub);
void	hooks(t_data *cub);
void	raycasting(t_data *cub);
int		get_texture(t_ray *ray);
void	render_display(t_data *cub);
void	render_frame(t_data *cub, t_ray *ray, int x);
int		render(t_data *cub);
void	execute(t_data *cub);

#endif
