/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_map_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:37:22 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/03/02 18:58:27 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calculate_map_size(t_map *map_file)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	if (map_file->matriz && map_file->matriz[0])
	{
		while (map_file->matriz[0][width])
			width++;
		while (map_file->matriz[height])
			height++;
	}
	map_file->width = width;
	map_file->height = height;
	if (width == 0 && height == 0)
	{
		free_map(map_file);
		error("Map doesn't have width and height");
	}
}
