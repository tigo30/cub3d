/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:52:14 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/05 00:28:11 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	prog_cleanup(t_data *data)
{
	if (data == NULL)
		return ;
	if (data->display.img)
		mlx_destroy_image(data->init, data->display.img);
	if (data->window)
		mlx_destroy_window(data->init, data->window);
	if (data->init)
		mlx_destroy_display(data->init);
	free(data->init);
	free_map(data->map);
}
