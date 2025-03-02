/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characaters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:34:14 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/03/02 21:37:24 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_valid_char(char c)
{
	char	*valid_chars;
	int		j;

	valid_chars = "01NSEW ";
	j = 0;
	while (valid_chars[j] != '\0')
	{
		if (c == valid_chars[j])
			return (1);
		j++;
	}
	return (0);
}

static void	validate_line(t_map *map_file, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_valid_char(line[i]))
		{
			free_map(map_file);
			error("Invalid characters in map");
		}
		i++;
	}
}

void	check_characters(t_map *map_file)
{
	t_node	*tmp;

	if (!map_file->file_content)
	{
		free_map(map_file);
		error("File doesn't have content");
	}
	tmp = map_file->file_content->first;
	while (tmp)
	{
		validate_line(map_file, tmp->value);
		tmp = tmp->next;
	}
}
