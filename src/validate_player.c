/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 01:37:22 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/03/02 19:49:38 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	char_in_set(char c, char *set)
{
	int	i;

	if (!set)
		return (0);
	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_players(char **grid)
{
	int	player_count;
	int	y;
	int	x;

	player_count = 0;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (char_in_set(grid[y][x], "NSEW"))
				player_count++;
			x++;
		}
		y++;
	}
	return (player_count);
}

void	find_player_position(t_map *map)
{
	int		y;
	int		x;
	char	**grid;

	grid = map->matriz;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x] && !char_in_set(grid[y][x], "NSEW"))
			x++;
		if (char_in_set(grid[y][x], "NSEW"))
			break ;
		y++;
	}
	if (grid[y] == NULL || grid[y][x] == '\0')
	{
		free_map(map);
		error("Map doesn't have a player");
	}
	map->player_direction = grid[y][x];
	map->player_x = x;
	map->player_y = y;
}

int	check_player_enclosed(char **grid, int player_y, int player_x)
{
	int	y;
	int	x;

	y = player_y - 1;
	while (y >= 0 && grid[y][player_x] != '#')
		y--;
	if (y < 0 || grid[y][player_x] != '#')
		return (0);
	y = player_y + 1;
	while (grid[y] && grid[y][player_x] != '#')
		y++;
	if (grid[y] == NULL || grid[y][player_x] != '#')
		return (0);
	x = player_x - 1;
	while (x >= 0 && grid[player_y][x] != '#')
		x--;
	if (x < 0 || grid[player_y][x] != '#')
		return (0);
	x = player_x + 1;
	while (grid[player_y][x] && grid[player_y][x] != '#')
		x++;
	if (grid[player_y][x] == '\0' || grid[player_y][x] != '#')
		return (0);
	return (1);
}

void	validate_player(t_map *map)
{
	int	player_count;

	player_count = count_players(map->matriz);
	if (player_count != 1)
	{
		free_map(map);
		if (player_count > 0)
			error("The map has more than one player");
		else
			error("The map doesn't have a player");
	}
	find_player_position(map);
	if (!check_player_enclosed(map->matriz, map->player_y, map->player_x))
	{
		free_map(map);
		error("Player is not inside the map");
	}
}
