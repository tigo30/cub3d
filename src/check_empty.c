/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_empty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:30:26 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/03/02 21:37:34 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	count_empty_rows(char **matriz)
{
	int	row;
	int	empty_rows;

	empty_rows = 0;
	row = 0;
	while (matriz[row])
	{
		if (!has_content(matriz[row]))
			empty_rows++;
		row++;
	}
	return (empty_rows);
}

static int	count_empty_columns(char **matriz)
{
	int	col;
	int	row;
	int	empty_columns;
	int	column_is_empty;

	empty_columns = 0;
	col = 0;
	while (matriz[0][col])
	{
		column_is_empty = 1;
		row = 0;
		while (matriz[row])
		{
			if (matriz[row][col] != ' ')
			{
				column_is_empty = 0;
				break ;
			}
			row++;
		}
		if (column_is_empty)
			empty_columns++;
		col++;
	}
	return (empty_columns);
}

void	check_empty(t_map *map_file)
{
	int	empty_rows;
	int	empty_columns;

	empty_rows = count_empty_rows(map_file->matriz);
	empty_columns = count_empty_columns(map_file->matriz);
	if (empty_rows && empty_columns)
	{
		free_map(map_file);
		error("The map has empty rows or columns");
	}
}
