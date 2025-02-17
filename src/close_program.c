/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:52:14 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/17 18:07:44 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	destroy_wall(void *init, t_texture *wall)
{
	if (wall->no.img)
		mlx_destroy_image(init, wall->no.img);
	if (wall->so.img)
		mlx_destroy_image(init, wall->so.img);
	if (wall->ea.img)
		mlx_destroy_image(init, wall->ea.img);
	if (wall->we.img)
		mlx_destroy_image(init, wall->we.img);
	free(wall);
}

void	close_program(t_data *cub)
{
	if (cub == NULL)
		return ;
	if (cub->wall && cub->init)
		destroy_wall(cub->init, cub->wall);
	if (cub->display.img && cub->init)
		mlx_destroy_image(cub->init, cub->display.img);
	if (cub->window)
		mlx_destroy_window(cub->init, cub->window);
	if (cub->init)
		mlx_destroy_display(cub->init);
	free(cub->init);
	free(cub->ray);
	free(cub->player);
	free_map(cub->map);
}
