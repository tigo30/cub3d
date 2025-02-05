/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:34:55 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/04 19:20:57 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	mouse_close(t_data *data)
{
	prog_cleanup(data);
	exit(EXIT_SUCCESS);
}

static int	key_close(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		prog_cleanup(data);
		exit(EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

static void	hook_register(t_data *data)
{
	mlx_hook(data->window, 3, 1L << 1, key_close, data);
	mlx_hook(data->window, 17, 1L << 17, mouse_close, data);
}

void	game_loop(t_data *data)
{
	if (data == NULL)
		return ;
	hook_register(data);
	mlx_loop(data->init);
}
