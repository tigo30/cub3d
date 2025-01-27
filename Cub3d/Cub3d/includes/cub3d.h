#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
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





void	error(char *error);
void	check_file(char *filename);
int     open_file(char *filename);
t_map	*get_map(char *filename);

void	init_map_file(t_map *map_file);
int	has_non_space(char *nbr);
t_fifo	*get_file_content(char *filename);
char	**convert_fifo_to_matriz(t_fifo *file_content);





#endif
