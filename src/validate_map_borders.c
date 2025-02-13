/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_borders.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 22:37:22 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/02/13 22:42:46 by tgrunho-         ###   ########.fr       */
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

int	validate_edge(t_map *map_file, t_coord last_pos, t_coord pos)
{
	if (pos.y < 0 || pos.y >= map_file->height
		|| pos.x < 0 || pos.x >= map_file->width
		|| (last_pos.y == pos.y && last_pos.x == pos.x))
		return (0);
	return (\
		(\
			pos.y - 1 == -1 \
			|| pos.x - 1 == -1 \
			|| map_file->matriz[pos.y + 1] == NULL \
			|| map_file->matriz[pos.y][pos.x + 1] == '\0' \
			|| map_file->matriz[pos.y - 1][pos.x] == ' ' \
			|| map_file->matriz[pos.y + 1][pos.x] == ' ' \
			|| map_file->matriz[pos.y][pos.x - 1] == ' ' \
			|| map_file->matriz[pos.y][pos.x + 1] == ' ' \
			|| map_file->matriz[pos.y - 1][pos.x - 1] == ' ' \
			|| map_file->matriz[pos.y - 1][pos.x + 1] == ' ' \
			|| map_file->matriz[pos.y + 1][pos.x - 1] == ' ' \
			|| map_file->matriz[pos.y + 1][pos.x + 1] == ' ' \
		) && (\
			map_file->matriz[pos.y][pos.x] == '1' \
			|| map_file->matriz[pos.y][pos.x] == '#' \
		)
	);
}

int	check_if_map_closed(t_map *map_file, const t_coord start, t_coord last_pos, t_coord pos)
{
	t_coord	neighbors[4];
	int		i;

	if (map_file->matriz[pos.y][pos.x] == '#')
		return (pos.y == start.y && pos.x == start.x);

	map_file->matriz[pos.y][pos.x] = '#';

	get_neighbors(neighbors, pos);

	for (i = 0; i < 4; i++)
	{
		if (validate_edge(map_file, last_pos, neighbors[i])
			&& check_if_map_closed(map_file, start, pos, neighbors[i]))
			return (1);
	}

	map_file->matriz[pos.y][pos.x] = '1';
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