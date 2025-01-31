/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:14:44 by joandre-          #+#    #+#             */
/*   Updated: 2025/01/31 18:00:50 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_data	*init_data(t_data *data, t_map *map)
{
	if (data == NULL || map == NULL)
		return (NULL);
	ft_bzero((void *)data, sizeof(data));
	data->init = NULL;
	data->window = NULL;
	data->img.img = NULL;
	data->img.addr = NULL;
	data->map = map;
	return (data);
}

bool	init_libx(t_data *data)
{
	if (data == NULL)
		return (false);
	data->init = mlx_init();
	if (data->init == NULL)
		return (false);
	data->window = mlx_new_window(data->init, HEIGHT, WIDTH, "cub3d");
	if (data->window == NULL)
		return (false);
	data->img.img = mlx_new_image(data->init, HEIGHT, WIDTH);
	if (data->img.img == NULL)
		return (false);
	data->img.addr = mlx_get_data_addr(data->img.img,
		&data->img.bpp, &data->img.size_line, &data->img.endian);
	if (data->img.addr == NULL)
		return (false);
	return (true);
}
