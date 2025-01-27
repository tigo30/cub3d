/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:28:34 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/01/27 23:41:01 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void	check_characters(t_map *map_file)
{
	t_node	*tmp;
	int				i;
	int				j;
	char	valid_chars[8];
    int	found;

    valid_chars[] = {'0', '1', 'N', 'S', 'E', 'W', ' ', '\0'};
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


void	check_empty(t_map *map_file)
{
	int	row;
    int col;
    int empty_rows;
    int empty_columns;
	int	has_content_in_column;
	char	*err_msg;

	err_msg = NULL;
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
	while (map_file->matriz[0][col])
	{
		row = 0;
		has_content_in_column = 0;
		while (map_file->matriz[row])
		{
			if (map_file->matriz[row][col] != ' ')
			{
				has_content_in_column = 1;
				break;
			}
			row++;
		}
		if (!has_content_in_column)
			empty_columns++;
		col++;
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
    
    // Ainda falta Verifica se há espaços vazios ou outros problemas na matriz do mapa. Bordas, verificar posicao incial do jogadopr
	
}
