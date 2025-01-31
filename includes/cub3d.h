#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h> 
# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"
# include "./fifo.h"

# define LOOK_LEFT  65361 
# define LOOK_RIGHT 65363
# define UP 119  //w
# define DOWN 115 //s
# define LEFT 97 //a
# define RIGHT 100 //d
# define EXIT 65307 //esq

# define TILE_SIZE 50
# define HEIGHT 600
# define WIDTH 800

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
	t_img	img;
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

#endif
