/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:14:44 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/17 21:48:00 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_texture	*init_textures(void)
{
	t_texture	*wall;

	wall = ft_calloc(sizeof(t_texture), 1);
	if (wall == NULL)
		return (NULL);
	wall->no.img = NULL;
	wall->no.addr = NULL;
	wall->so.img = NULL;
	wall->so.addr = NULL;
	wall->ea.img = NULL;
	wall->ea.addr = NULL;
	wall->we.img = NULL;
	wall->we.addr = NULL;
	return (wall);
}

void	init_data(t_data *cub, char *filename)
{
	if (cub == NULL)
		return ;
	ft_bzero((void *)cub, sizeof(cub));
	cub->init = NULL;
	cub->window = NULL;
	cub->display.img = NULL;
	cub->display.addr = NULL;
	cub->display.height = HEIGHT;
	cub->display.width = WIDTH;
	cub->map = get_map(filename);
	cub->wall = init_textures();
	cub->ray = ft_calloc(sizeof(t_ray), 1);
	cub->player = ft_calloc(sizeof(t_player), 1);
}
