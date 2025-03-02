/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 02:23:39 by joandre-          #+#    #+#             */
/*   Updated: 2025/03/02 19:25:02 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	*xpm_to_img(void *init, char *path)
{
	t_img	tmp;
	int		*wall;
	int		x;
	int		y;

	ft_bzero(&tmp, sizeof(t_img));
	tmp.img = NULL;
	tmp.addr = NULL;
	if (!load_image(init, &tmp, path))
		return (NULL);
	wall = ft_calloc(1, sizeof(int) * tmp.height * tmp.width + sizeof(int));
	if (!wall)
		return (mlx_destroy_image(init, tmp.img), NULL);
	y = -1;
	while (++y < tmp.height)
	{
		x = -1;
		while (++x < tmp.width)
			wall[y * tmp.width + x]
				= ((int *)tmp.addr)[y * (tmp.size_line / 4) + x];
	}
	mlx_destroy_image(init, tmp.img);
	return (wall);
}

int	**init_wall(void *init, t_map *map)
{
	int	**wall;

	wall = ft_calloc(sizeof(int *), 4);
	if (!wall)
		return (NULL);
	wall[NORTH] = xpm_to_img(init, map->texture_no);
	if (!wall[NORTH])
		return (free(wall), NULL);
	wall[SOUTH] = xpm_to_img(init, map->texture_so);
	if (!wall[SOUTH])
		return (free(wall[NORTH]), free(wall), NULL);
	wall[EAST] = xpm_to_img(init, map->texture_ea);
	if (!wall[EAST])
		return (free(wall[NORTH]), free(wall[SOUTH]), free(wall), NULL);
	wall[WEST] = xpm_to_img(init, map->texture_we);
	if (!wall[WEST])
		return (free(wall[NORTH]), free(wall[SOUTH]),
			free(wall[EAST]), free(wall), NULL);
	return (wall);
}

static bool	start_minilibx(t_data *cub)
{
	cub->init = mlx_init();
	if (!cub->init)
		return (false);
	cub->window = mlx_new_window(cub->init, WIDTH, HEIGHT, "cub3d");
	if (!cub->window)
		return (false);
	return (true);
}

void	load_player_data(t_player *player, t_map *map)
{
	if (map->player_direction == 'N')
	{
		player->direction.y = -1;
		player->plane.x = 0.66;
	}
	else if (map->player_direction == 'S')
	{
		player->direction.y = 1;
		player->plane.x = -0.66;
	}
	else if (map->player_direction == 'E')
	{
		player->direction.x = 1;
		player->plane.y = 0.66;
	}
	else if (map->player_direction == 'W')
	{
		player->direction.x = -1;
		player->plane.y = -0.66;
	}
	player->position.x = map->player_x + 0.5;
	player->position.y = map->player_y + 0.5;
}

bool	load_data(t_data *cub, char *filename)
{
	if (!cub || !filename || !(*filename))
		return (false);
	cub->map = get_map(filename);
	if (!cub->map)
		return (false);
	cub->player = ft_calloc(sizeof(t_player), 1);
	if (!cub->player)
		return (false);
	load_player_data(cub->player, cub->map);
	cub->control = *cub->player;
	cub->ray = ft_calloc(sizeof(t_ray), 1);
	if (!cub->ray)
		return (false);
	cub->frame = init_frame();
	if (!cub->frame)
		return (false);
	if (!start_minilibx(cub))
		return (false);
	cub->wall = init_wall(cub->init, cub->map);
	if (!cub->wall)
		return (false);
	return (true);
}
