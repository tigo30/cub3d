/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 02:23:39 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/20 02:37:48 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	load_player(t_player *player, t_map *map)
{
	if (player == NULL || map == NULL)
		return ;
	if (map->player_direction == 'N')
		player->angle = 3 * M_PI / 2;
	else if (map->player_direction == 'S')
		player->angle = M_PI / 2;
	else if (map->player_direction == 'E')
		player->angle = 0;
	else if (map->player_direction == 'W')
		player->angle = M_PI;
	player->x = (map->player_x * TILE) + (TILE / 2);
	player->y = (map->player_y * TILE) + (TILE / 2);
	player->fov = (FOV * M_PI) / 180;
}

static bool	load_file_image(void *init, t_img *png, char *filename)
{
	png->img = mlx_xpm_file_to_image(init, filename, &png->width, &png->height);
	if (png->img == NULL)
		return (false);
	png->addr = mlx_get_data_addr(png->img,
			&png->bpp, &png->size_line, &png->endian);
	if (png->addr == NULL)
		return (false);
	return (true);
}

static bool	load_textures(void *init, t_texture *wall, t_map *map)
{
	return (load_file_image(init, &wall->no, map->texture_no)
		&& load_file_image(init, &wall->so, map->texture_so)
		&& load_file_image(init, &wall->ea, map->texture_ea)
		&& load_file_image(init, &wall->we, map->texture_we));
}

static bool	init_minilibx(t_data *cub)
{
	if (cub == NULL)
		return (false);
	cub->init = mlx_init();
	if (cub->init == NULL)
		return (false);
	cub->window = mlx_new_window(cub->init, HEIGHT, WIDTH, "cub3d");
	if (cub->window == NULL)
		return (false);
	cub->display.img = mlx_new_image(cub->init,
		cub->display.height, cub->display.width);
	if (cub->display.img == NULL)
		return (false);
	cub->display.addr = mlx_get_data_addr(cub->display.img,
			&cub->display.bpp, &cub->display.size_line,
			&cub->display.endian);
	if (cub->display.addr == NULL)
		return (false);
	return (true);
}

bool	load_data(t_data *cub)
{
	if (!cub || !cub->map || !cub->wall || !cub->ray || !cub->player)
		return (false);
	if (init_minilibx(cub) == false)
		return (false);
	if (load_textures(cub->init, cub->wall, cub->map) == false)
		return (false);
	load_player(cub->player, cub->map);
	cub->ray->angle = cub->player->angle;
	return (true);
}
