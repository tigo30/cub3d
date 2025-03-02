/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:53:01 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/03/02 20:04:12 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	has_non_space(char *nbr)
{
	int	i;

	i = 0;
	while (nbr[i] && nbr[i] == ' ')
		i++;
	return (nbr[i] != '\0');
}

static int	is_texture_identifier(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == 'C' || c == 'F');
}

static void	set_texture_or_color(t_map *map_file, char **texture)
{
	int	color;

	if (!ft_strcmp(texture[0], "NO") && !map_file->texture_no)
		map_file->texture_no = ft_strdup(texture[1]);
	else if (!ft_strcmp(texture[0], "SO") && !map_file->texture_so)
		map_file->texture_so = ft_strdup(texture[1]);
	else if (!ft_strcmp(texture[0], "EA") && !map_file->texture_ea)
		map_file->texture_ea = ft_strdup(texture[1]);
	else if (!ft_strcmp(texture[0], "WE") && !map_file->texture_we)
		map_file->texture_we = ft_strdup(texture[1]);
	else if (!ft_strcmp(texture[0], "C") && map_file->ceil_color == -1)
	{
		color = convert_rgb(texture[1]);
		map_file->ceil_color = color;
	}
	else if (!ft_strcmp(texture[0], "F") && map_file->floor_color == -1)
	{
		color = convert_rgb(texture[1]);
		map_file->floor_color = color;
	}
}

static void	process_texture_line(t_map *map_file, char *content)
{
	char	**texture;

	texture = ft_split(content, ' ');
	if (!texture)
	{
		free_map(map_file);
		error("Malloc failed");
	}
	set_texture_or_color(map_file, texture);
	ft_clear_split(texture);
}

void	check_textures(t_map *map_file)
{
	t_fifo	*file_content;
	char	*content;
	int		i;

	file_content = map_file->file_content;
	while (file_content->len > 0)
	{
		content = file_content->first->value;
		if (has_non_space(content))
		{
			i = 0;
			while (content[i] == ' ')
				i++;
			if (!is_texture_identifier(content[i]))
				break ;
			process_texture_line(map_file, content);
		}
		fifo_remove_first(file_content);
	}
	if (!(map_file->texture_no && map_file->texture_so && map_file->texture_ea
			&& map_file->texture_we && map_file->ceil_color != -1
			&& map_file->floor_color != -1))
		free_map(map_file);
}
