/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:59:57 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/20 02:47:55 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	wall_hit(float x, float y, t_map *map)
{
	int	map_x;
	int	map_y;

	if (x < 0 || y < 0)
		return (true);
	map_x = floor(x / TILE);
	map_y = floor(y / TILE);
	if (map_y >= map->height || map_x >= map->width)
		return (true);
	if (map->matriz[map_y] && map_x <= (int)ft_strlen(map->matriz[map_y]))
		if (map->matriz[map_y][map_x] == '1')
			return (true);
	return (false);
}

static float	vertical_intersection(t_data *cub)
{
	float	x;
	float	y;
	float	step_x;
	float	step_y;
	int		pixel;

	step_x = TILE;
	step_y = TILE * tan(cub->ray->angle);
	x = floor(cub->player->x / TILE) * TILE;
	y = cub->player->y + (x - cub->player->x) * tan(cub->ray->angle);
	pixel = check_intersection(cub->ray->angle, &x, &step_x, false);
	if ((unit_circle(cub->ray->angle, 'x') && step_y < 0)
		|| (unit_circle(cub->ray->angle, 'x') && step_y > 0))
		step_y *= -1;
	while (!wall_hit(x - pixel, y, cub->map))
	{
		x += step_x;
		y += step_y;
	}
	cub->ray->vertical.x = x;
	cub->ray->vertical.y = y;
	return (sqrt(pow(x - cub->player->x, 2) + pow(y - cub->player->x, 2)));
}

static float	horizontal_intersection(t_data *cub)
{
	float	x;
	float	y;
	float	step_x;
	float	step_y;
	int		pixel;

	y = floor(cub->player->y / TILE) * TILE;
	x = cub->player->x + (y - cub->player->y) / tan(cub->ray->angle);
	step_y = TILE;
	step_x = TILE / tan(cub->ray->angle);
	pixel = check_intersection(cub->ray->angle, &y, &step_y, true);
	if ((unit_circle(cub->ray->angle, 'y') && step_x > 0)
		|| (!unit_circle(cub->ray->angle, 'y') && step_x < 0))
		step_x *= -1;
	while (!wall_hit(x, y - pixel, cub->map))
	{
		x += step_x;
		y += step_y;
	}
	cub->ray->horizontal.x = x;
	cub->ray->horizontal.y = y;
	return (sqrt(pow(x - cub->player->x, 2) + pow(y - cub->player->y, 2)));
}

void	raycasting(t_data *cub)
{
	int		ray;
	double	h_inter;
	double	v_inter;

	if (!cub || !cub->player || !cub->ray)
		return ;
	cub->ray->angle = cub->player->angle - (cub->player->fov / 2);
	ray = 0;
	while (ray < WIDTH)
	{
		cub->ray->flag = false;
		h_inter = horizontal_intersection(cub);
		v_inter = vertical_intersection(cub);
		if (v_inter <= h_inter)
			cub->ray->distance = v_inter;
		else
		{
			cub->ray->flag = true;
			cub->ray->distance = h_inter;
		}
		render(cub);
		++ray;
		cub->ray->angle += (cub->player->fov / WIDTH);
	}
}
