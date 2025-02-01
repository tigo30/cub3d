/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:28:34 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/02/01 17:53:52 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_characters(t_map *map_file)
{
	t_node	*tmp;
	int		i;
	int		j;
	char	*valid_chars;
    int		found;

    valid_chars = "01NSEW ";
	if (!map_file->file_content)
	{
		free_map(map_file); 
		error("File doesn't have content"); 
	}
	tmp = map_file->file_content->first;
	while (tmp)
	{
		i = 0;
		while (tmp->value[i])
		{
			found = 0; 
			j = 0;
			while (valid_chars[j] != '\0')
			{
				if (tmp->value[i] == valid_chars[j])
				{
					found = 1;
					break;
				}
				j++;
			}
			if (!found)
			{
				free_map(map_file); 
				error("Invalid characters in map");
			}
			i++;
		}
		tmp = tmp->next;
	}
}

int	has_content(char *content)
{
	int	i;

	i = 0;
	while (content[i] && content[i] == ' ')
		i++;
	return (content[i] != '\0');
}

void	check_empty(t_map *map_file)
{
	int		row;
	int		col;
	int		empty_rows;
	int		empty_columns;

	empty_rows = 0;
	empty_columns = 0;
	row = 0;
	while (map_file->matriz[row])
	{
		if (!has_content(map_file->matriz[row]))
			empty_rows++;
		row++;
	}
	col = 0;
	row = 0;
	while (map_file->matriz[row])
	{
		int column_is_empty = 1;
		while (map_file->matriz[row] && map_file->matriz[row][col])
		{
			if (map_file->matriz[row][col] != ' ')
			{
				column_is_empty = 0;
				break;
			}
			row++;
		}

		if (column_is_empty)
			empty_columns++;

		if (map_file->matriz[0][col] == '\0')
			break;
		
		col++;
		row = 0;
	}
	if (empty_rows || empty_columns)
	{
		free_map(map_file);
		error("The map has empty rows or columns");
	}

}

void	check_map(t_map *map_file)
{
	int	row;
	int	col;
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

