/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:52:14 by joandre-          #+#    #+#             */
/*   Updated: 2025/03/09 01:54:30 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	clean_game_assets(t_data *cub)
{
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

void	close_program(t_data *cub, bool error)
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
	clean_game_assets(cub);
	if (!error)
		exit(EXIT_SUCCESS);
	perror("cub3d error");
	exit(EXIT_FAILURE);
}
