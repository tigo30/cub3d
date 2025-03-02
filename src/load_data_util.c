/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_data_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 02:23:39 by joandre-          #+#    #+#             */
/*   Updated: 2025/03/02 19:25:54 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	load_image(void *init, t_img *png, char *filename)
{
	png->img = mlx_xpm_file_to_image(init, filename, &png->width, &png->height);
	if (png->img == NULL)
		return (false);
	png->addr = mlx_get_data_addr(png->img,
			&png->bpp, &png->size_line, &png->endian);
	if (png->addr == NULL)
		return (mlx_destroy_image(init, png->img), false);
	return (true);
}
