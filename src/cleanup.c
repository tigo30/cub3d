/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:52:14 by joandre-          #+#    #+#             */
/*   Updated: 2025/01/30 16:58:46 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	prog_cleanup(t_data *data)
{
	if (data == NULL)
		return ;
	if (data->img.img)
		mlx_destroy_image(data->init, data->img.img);
	if (data->window)
		mlx_destroy_window(data->init, data->window);
	mlx_destroy_display(data->init);
	free(data->init);
}
