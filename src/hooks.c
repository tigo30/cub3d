/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:34:55 by joandre-          #+#    #+#             */
/*   Updated: 2025/03/09 01:54:05 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	mouse_close(t_data *cub)
{
	close_program(cub, false);
	return (EXIT_SUCCESS);
}

static int	key_close(int keysym, t_data *cub)
{
	if (keysym == XK_Escape)
		close_program(cub, false);
	return (EXIT_FAILURE);
}

int	render(t_data *cub)
{
	if (ft_memcmp(cub->player, &cub->control, sizeof(t_player)))
	{
		cub->frame = init_frame();
		if (!cub->frame)
			close_program(cub, true);
		*cub->player = cub->control;
		raycasting(cub);
		render_display(cub);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

void	hooks(t_data *cub)
{
	mlx_hook(cub->window, 3, 1L << 1, key_close, cub);
	mlx_hook(cub->window, 17, 1L << 17, mouse_close, cub);
	mlx_hook(cub->window, 2, 1L << 0, player_movement, cub);
}
