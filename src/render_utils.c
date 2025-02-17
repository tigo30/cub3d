/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:29:16 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/17 20:00:14 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	screen_draw(t_data *cub, int x, int y, int color)
{
	printf("screen_draw()\n");
	if (x < 0 || y < 0)
		return ;
	if (x > WIDTH || y > HEIGHT)
		return ;
	mlx_pixel_put(cub->init, cub->window, x, y, color);
}

int	reverse_bytes(int c)
{
	unsigned int	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}

t_img	*get_texture(t_ray *ray, t_texture *img)
{
	if (ray == NULL || img == NULL)
		return (NULL);
	ray->angle = normalize(ray->angle);
	if (ray->flag)
	{
		if (ray->angle > 0 && ray->angle < M_PI)
			return (&img->so);
		else
			return (&img->no);
	}
	else
	{
		if (ray->angle > 0 && ray->angle < M_PI)
			return (&img->ea);
		else
			return (&img->we);
	}
}
