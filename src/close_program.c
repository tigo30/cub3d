/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:52:14 by joandre-          #+#    #+#             */
/*   Updated: 2025/03/02 19:01:06 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	close_program(t_data *cub)
{
	int	i;

	if (cub == NULL)
		return ;
	if (cub->window)
		mlx_destroy_window(cub->init, cub->window);
	if (cub->init)
		mlx_destroy_display(cub->init);
	free(cub->init);
	i = -1;
	if (cub->frame)
		while (++i < HEIGHT)
			free(cub->frame[i]);
	free(cub->frame);
	if (cub->wall)
	{
		free(cub->wall[NORTH]);
		free(cub->wall[SOUTH]);
		free(cub->wall[EAST]);
		free(cub->wall[WEST]);
	}
	free(cub->wall);
	free(cub->ray);
	free(cub->player);
	free_map(cub->map);
}
