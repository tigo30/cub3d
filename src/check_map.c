/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:28:34 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/03/02 21:38:49 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	has_content(char *content)
{
	int	i;

	i = 0;
	while (content[i] && content[i] == ' ')
		i++;
	return (content[i] != '\0');
}

void	validate_format_map(t_map *map_file)
{
	int	row;
	int	col;

	map_file->matriz[map_file->player_y][map_file->player_x] = '0';
	row = 0;
	while (map_file->matriz[row])
	{
		col = 0;
		while (map_file->matriz[row][col])
		{
			if (map_file->matriz[row][col] != '0'
				&& map_file->matriz[row][col] != ' ')
				map_file->matriz[row][col] = '1';
			col++;
		}
		row++;
	}
}

void	check_map(t_map *map_file)
{
	check_characters(map_file);
	map_file->matriz = convert_fifo_to_matriz(map_file->file_content);
	if (!map_file->matriz)
	{
		free_map(map_file);
		error("Failed to create map matrix");
	}
	check_empty(map_file);
	calculate_map_size(map_file);
	validate_map_borders(map_file);
	validate_player(map_file);
	validate_format_map(map_file);
}
