/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_borders.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 22:37:22 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/02/01 17:30:14 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	find_starting_point(t_map *map_file, t_coord *start)
{
	char	**matrix;

	matrix = map_file->matriz;
	start->y = 0;

	while (matrix[start->y])
	{
		start->x = 0;
		while (matrix[start->y][start->x])
		{
			if (matrix[start->y][start->x] == '1'
				&& start->y + 1 < map_file->height
				&& start->x + 1 < map_file->width
				&& matrix[start->y + 1][start->x] == '1'
				&& matrix[start->y][start->x + 1] == '1')
				return;
			start->x++;
		}
		start->y++;
	}
	free_map(map_file);
	error("Map no has walls");
}
void	get_neighbors(t_coord neighbors[4], t_coord position)
{
	neighbors[0].y = position.y - 1;
	neighbors[0].x = position.x;
	neighbors[1].y = position.y;
	neighbors[1].x = position.x - 1;
	neighbors[2].y = position.y + 1;
	neighbors[2].x = position.x;
	neighbors[3].y = position.y;
	neighbors[3].x = position.x + 1;
}

int	validate_edge(t_map *map_file, t_coord last_position, t_coord current_position)
{
	if (current_position.y < 0 || current_position.y >= map_file->height
		|| current_position.x < 0 || current_position.x >= map_file->width
		|| (last_position.y == current_position.y && last_position.x == current_position.x))
		return (0);

	int is_out_of_bounds = 
		current_position.y - 1 < 0 ||
		current_position.x - 1 < 0 ||
		map_file->matriz[current_position.y + 1] == NULL ||
		map_file->matriz[current_position.y][current_position.x + 1] == '\0';

	int is_next_to_empty_space = 
		map_file->matriz[current_position.y - 1][current_position.x] == ' ' ||
		map_file->matriz[current_position.y + 1][current_position.x] == ' ' ||
		map_file->matriz[current_position.y][current_position.x - 1] == ' ' ||
		map_file->matriz[current_position.y][current_position.x + 1] == ' ';

	int is_valid_cell = 
		map_file->matriz[current_position.y][current_position.x] == '1' ||
		map_file->matriz[current_position.y][current_position.x] == '#';

	return ((is_out_of_bounds || is_next_to_empty_space) && is_valid_cell);
}

int	check_if_map_closed(t_map *map_file, const t_coord start, t_coord last_position, t_coord current_position)
{
	t_coord	neighbors[4];
	int		i;

	if (map_file->matriz[current_position.y][current_position.x] == '#')
		return (current_position.y == start.y && current_position.x == start.x);

	map_file->matriz[current_position.y][current_position.x] = '#';

	get_neighbors(neighbors, current_position);

	for (i = 0; i < 4; i++)
	{
		if (validate_edge(map_file, last_position, neighbors[i])
			&& check_if_map_closed(map_file, start, current_position, neighbors[i]))
			return (1);
	}

	map_file->matriz[current_position.y][current_position.x] = '1';
	return (0);
}

void	validate_map_borders(t_map *map_file)
{
	t_coord	starting_point;

	find_starting_point(map_file, &starting_point);

	if (!check_if_map_closed(map_file, starting_point, starting_point, starting_point))
	{
		free_map(map_file);
		error("walls no closed");
	}
}