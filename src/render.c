/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:00:31 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/17 21:00:36 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static double	get_x(t_img *wall, t_ray *ray)
{
	if (ray->flag)
		return (fmodf(ray->horizontal.x * (wall->width / TILE),
				wall->width));
	else
		return (fmodf(ray->vertical.y * (wall->width / TILE),
				wall->width));
}

static void	render_wall(t_data *cub, double top, double bot, double pixel)
{
	double		x;
	double		y;
	double		factor;
	uint32_t	*byte;
	t_img		*wall;

	wall = get_texture(cub->ray, cub->wall);
	if (wall == NULL)
		return ;
	byte = (uint32_t *)wall->addr;
	factor = wall->height / pixel;
	x = get_x(wall, cub->ray);
	y = (top - (HEIGHT / 2) + (wall->height / 2)) * factor;
	if (y < 0)
		y = 0;
	while (top < bot)
	{
		screen_draw(cub, x, y,
			reverse_bytes(byte[(int)y * wall->width + (int)x]));
		y += factor;
		++top;
	}
}

static void	render_floor_ceiling(void)
{
}

void	render(t_data *cub)
{
	double	pixel;
	double	top_pixel;
	double	bot_pixel;

	cub->ray->distance *= cos(normalize(cub->ray->angle - cub->player->angle));
	pixel = (TILE / cub->ray->distance) * ((WIDTH / 2) / tan(cub->player->fov / 2));
	bot_pixel = (HEIGHT / 2) + (pixel / 2);
	top_pixel = (HEIGHT / 2) - (pixel / 2);
	if (bot_pixel > HEIGHT)
		bot_pixel = HEIGHT;
	if (top_pixel < 0)
		top_pixel = 0;
	render_wall(cub, top_pixel, bot_pixel, pixel);
	render_floor_ceiling();
}
