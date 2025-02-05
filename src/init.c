/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:14:44 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/05 00:46:49 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_data	*init_data(t_data *data, t_map *map)
{
	if (data == NULL)
		return (NULL);
	ft_bzero((void *)data, sizeof(data));
	data->init = NULL;
	data->window = NULL;
	data->display.img = NULL;
	data->display.addr = NULL;
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
	data->display.img = mlx_new_image(data->init, HEIGHT, WIDTH);
	if (data->display.img == NULL)
		return (false);
	data->display.addr = mlx_get_data_addr(data->display.img,
			&data->display.bpp, &data->display.size_line,
			&data->display.endian);
	if (data->display.addr == NULL)
		return (false);
	return (true);
}
