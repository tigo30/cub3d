/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:14:44 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/09 01:55:33 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_data	*init_data(t_data *cub, t_map *map)
{
	if (cub == NULL)
		return (NULL);
	ft_bzero((void *)cub, sizeof(cub));
	cub->init = NULL;
	cub->window = NULL;
	cub->display.img = NULL;
	cub->display.addr = NULL;
	cub->map = map;
	cub->ray = NULL;
	cub->player = NULL;
	return (cub);
}

bool	init_libx(t_data *cub)
{
	if (cub == NULL)
		return (false);
	cub->init = mlx_init();
	if (cub->init == NULL)
		return (false);
	cub->window = mlx_new_window(cub->init, HEIGHT, WIDTH, "cub3d");
	if (cub->window == NULL)
		return (false);
	cub->display.img = mlx_new_image(cub->init, HEIGHT, WIDTH);
	if (cub->display.img == NULL)
		return (false);
	cub->display.addr = mlx_get_data_addr(cub->display.img,
			&cub->display.bpp, &cub->display.size_line,
			&cub->display.endian);
	if (cub->display.addr == NULL)
		return (false);
	return (true);
}
