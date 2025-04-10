/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:23:42 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/03/08 22:49:01 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_map_file(t_map *map_file)
{
	map_file->matriz = NULL;
	map_file->width = -1;
	map_file->height = -1;
	map_file->texture_no = NULL;
	map_file->texture_so = NULL;
	map_file->texture_ea = NULL;
	map_file->texture_we = NULL;
	map_file->ceil_color = -1;
	map_file->floor_color = -1;
	map_file->player_direction = '?';
	map_file->player_x = -1;
	map_file->player_y = -1;
}

t_map	*get_map(char *filename)
{
	t_map	*map_file;

	check_file(filename);
	map_file = (t_map *)malloc(sizeof(t_map));
	if (map_file == NULL)
		error("Cannot allocate memory in get_map_file");
	init_map_file(map_file);
	map_file->file_content = get_file_content(filename);
	if (!map_file->file_content)
	{
		free_map(map_file);
		error("Error file content");
	}
	check_textures(map_file);
	check_map(map_file);
	return (map_file);
}
