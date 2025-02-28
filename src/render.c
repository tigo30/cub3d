/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:00:31 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/28 22:40:14 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_pixel(t_img *img, int x, int y, int color)
{
	int	*pix;

	pix = (int *)img->addr;
	pix[y * (img->size_line / 4) + x] = color;
}

static void	frame_pixel(t_data *cub, t_img *img, int x, int y)
{
	if (cub->frame[y][x] > 0)
		set_pixel(img, x, y, cub->frame[y][x]);
	else if (y < HEIGHT / 2)
		set_pixel(img, x, y, cub->map->ceil_color);
	else if (y < HEIGHT - 1)
		set_pixel(img, x, y, cub->map->floor_color);
}

void	clean_frame(int **frame)
{
	int	y;

	y = -1;
	while (++y < HEIGHT)
		free(frame[y]);
	free(frame);
}

void	render_display(t_data *cub)
{
	int		x;
	int		y;
	t_img	img;

	ft_bzero(&img, sizeof(img));
	img.img = mlx_new_image(cub->init, WIDTH, HEIGHT);
	if (!img.img)
		close_program(cub);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.size_line, &img.endian);
	if (!img.addr)
		close_program(cub);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			frame_pixel(cub, &img, x, y);
	}
	mlx_put_image_to_window(cub->init, cub->window, img.img, 0, 0);
	mlx_destroy_image(cub->init, img.img);
	clean_frame(cub->frame);
	cub->frame = NULL;
}

void	render_frame(t_data *cub, t_ray *ray, int x)
{
	t_coori	wall;
	t_coor	step;
	int		i;
	int		color;
	int		y;

	i = get_texture(ray);
	wall.x = (int)(ray->wall * TILE);
	if ((ray->flag && ray->direction.y > 0)
		|| (!ray->flag && ray->direction.x < 0))
		wall.x = TILE - wall.x;
	step.y = 1.0 * TILE / ray->line;
	step.x = (ray->start - HEIGHT / 2 + ray->line / 2) * step.y;
	y = ray->start;
	while (y < ray->end)
	{
		wall.y = (int)step.x & (TILE - 1);
		step.x += step.y;
		color = cub->wall[i][TILE * wall.y + wall.x];
		cub->frame[y][x] = color;
		++y;
	}
}
