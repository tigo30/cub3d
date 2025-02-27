/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:34:55 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/27 21:00:56 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	execute(t_data *cub)
{
	raycasting(cub);
	render_display(cub);
	hooks(cub);
	mlx_loop_hook(cub->init, render, cub);
	mlx_loop(cub->init);
}
