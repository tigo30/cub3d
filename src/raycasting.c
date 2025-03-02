/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:59:57 by joandre-          #+#    #+#             */
/*   Updated: 2025/03/02 19:43:03 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	calculate_height(t_ray *ray, t_player *player)
{
	if (ray->flag)
		ray->distance = ray->side.y - ray->delta.y;
	else
		ray->distance = ray->side.x - ray->delta.x;
	ray->line = (int)(HEIGHT / ray->distance);
	ray->start = -(ray->line) / 2 + HEIGHT / 2;
	if (ray->start < 0)
		ray->start = 0;
	ray->end = ray->line / 2 + HEIGHT / 2;
	if (ray->end >= HEIGHT)
		ray->end = HEIGHT - 1;
	if (ray->flag)
		ray->wall = player->position.x + ray->distance * ray->direction.x;
	else
		ray->wall = player->position.y + ray->distance * ray->direction.y;
	ray->wall -= floor(ray->wall);
}

static void	dda_algo(t_ray *ray, t_map *map)
{
	while (1)
	{
		if (ray->side.x < ray->side.y)
		{
			ray->side.x += ray->delta.x;
			ray->position.x += ray->step.x;
			ray->flag = false;
		}
		else
		{
			ray->side.y += ray->delta.y;
			ray->position.y += ray->step.y;
			ray->flag = true;
		}
		if (ray->position.y < 0.25 || ray->position.x < 0.25
			|| ray->position.y > map->height - 0.25
			|| ray->position.x > map->width - 1.25
			|| map->matriz[ray->position.y][ray->position.x] > '0')
			break ;
	}
}

static void	calculate_step(t_ray *ray, t_player *player)
{
	if (ray->direction.x < 0)
	{
		ray->step.x = -1;
		ray->side.x = (player->position.x - ray->position.x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side.x = (ray->position.x + 1.0 - player->position.x)
			* ray->delta.x;
	}
	if (ray->direction.y < 0)
	{
		ray->step.y = -1;
		ray->side.y = (player->position.y - ray->position.y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side.y = (ray->position.y + 1.0 - player->position.y)
			* ray->delta.y;
	}
}

static void	cast_info(int x, t_ray *ray, t_player *player)
{
	ft_bzero(ray, sizeof(ray));
	ray->camera = 2 * x / (double)WIDTH - 1;
	ray->direction.x = player->direction.x + player->plane.x * ray->camera;
	ray->direction.y = player->direction.y + player->plane.y * ray->camera;
	ray->position.x = (int)player->position.x;
	ray->position.y = (int)player->position.y;
	ray->delta.x = fabs(1 / ray->direction.x);
	ray->delta.y = fabs(1 / ray->direction.y);
}

void	raycasting(t_data *cub)
{
	t_ray	ray;
	int		x;

	if (cub == NULL)
		return ;
	ray = *cub->ray;
	x = -1;
	while (++x < WIDTH)
	{
		cast_info(x, &ray, cub->player);
		calculate_step(&ray, cub->player);
		dda_algo(&ray, cub->map);
		calculate_height(&ray, cub->player);
		render_frame(cub, &ray, x);
	}
}
