/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:34:55 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/20 02:32:33 by joandre-         ###   ########.fr       */
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

void	hooks(t_data *cub)
{
	mlx_hook(cub->window, 3, 1L << 1, key_close, cub);
	mlx_hook(cub->window, 17, 1L << 17, mouse_close, cub);
}
