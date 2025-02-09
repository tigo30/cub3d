/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:59:57 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/09 19:53:22 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_player(t_data *cub)
{
	if (!cub || !cub->map || !cub->player)
		return ;
	if (cub->map->player_direction == 'N')
		cub->player->angle = 3 * M_PI / 2;
	else if (cub->map->player_direction == 'S')
		cub->player->angle = M_PI / 2;
	else if (cub->map->player_direction == 'E')
		cub->player->angle = 0;
	else if (cub->map->player_direction == 'W')
		cub->player->angle = M_PI;
	cub->player->x = (cub->map->player_x * TILE) + TILE * 2;
	cub->player->y = (cub->map->player_y * TILE) + TILE * 2;
	cub->player->fov = FOV * M_PI / 180;
}

float	horizonal_intersection(t_data *cub)
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
	while (wall_hit(x, y - pixel, cub->map))
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
	int	ray;

	if (!cub || !cub->player || !cub->ray)
		return ;
	cub->ray->angle = cub->player->angle - (cub->player->fov / 2);
	ray = 0;
	while (ray < WIDTH)
	{
		++ray;
		cub->ray->angle += cub->player->fov / WIDTH;
	}
}
