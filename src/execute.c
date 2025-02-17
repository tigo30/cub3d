/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:34:55 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/17 21:52:27 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	mouse_close(t_data *cub)
{
	close_program(cub);
	exit(EXIT_SUCCESS);
}

static int	key_close(int keysym, t_data *cub)
{
	if (keysym == XK_Escape)
	{
		close_program(cub);
		exit(EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

static void	hook_register(t_data *cub)
{
	mlx_hook(cub->window, 3, 1L << 1, key_close, cub);
	mlx_hook(cub->window, 17, 1L << 17, mouse_close, cub);
}

bool	execute(t_data *cub)
{
	if (!cub || FOV <= 0 || FOV >= 180)
		return (false);
	hook_register(cub);
	render(cub);
	mlx_loop(cub->init);
	return (true);
}
