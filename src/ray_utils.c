/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:38:22 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/09 19:50:07 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_intersection(float angle, float *inter, float *step, bool flag)
{
	if (flag)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += TILE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
		{
			*inter += TILE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

bool	unit_circle(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (true);
	}
	else if (c == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (true);
	}
	return (false);
}

bool	wall_hit(float x, float y, t_map *map)
{
	int	map_x;
	int	map_y;

	if (x < 0 || y < 0)
		return (false);
	map_x = floor(x / TILE);
	map_y = floor(y / TILE);
	if (map_y >= map->height || map_x >= map->width)
		return (false);
	if (map->matriz[map_y] && map_x <= (int)ft_strlen(map->matriz[map_y]))
		if (map->matriz[map_y][map_x] == '1')
			return (false);
	return (true);
}
