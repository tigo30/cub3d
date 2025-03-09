/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:53:01 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/03/09 00:36:42 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_texture(char *content)
{
	int	i;

	i = 0;
	while (content[i] && content[i] == ' ')
		i++;
	return (content[i] == 'N' || content[i] == 'S' || content[i] == 'E'
		|| content[i] == 'W'
		|| content[i] == 'C' || content[i] == 'F');
}

static void	add_texture(t_map *map_file, char **tex)
{
	if (!tex[1])
	{
		ft_clear_split(tex);
		free_map(map_file);
		error("Invalid texture definition");
	}
	if (!map_file->texture_no && ft_strcmp(tex[0], "NO") == 0)
		map_file->texture_no = ft_strdup(tex[1]);
	else if (!map_file->texture_so && ft_strcmp(tex[0], "SO") == 0)
		map_file->texture_so = ft_strdup(tex[1]);
	else if (!map_file->texture_ea && ft_strcmp(tex[0], "EA") == 0)
		map_file->texture_ea = ft_strdup(tex[1]);
	else if (!map_file->texture_we && ft_strcmp(tex[0], "WE") == 0)
		map_file->texture_we = ft_strdup(tex[1]);
	else if (map_file->ceil_color == -1 && ft_strcmp(tex[0], "C") == 0)
		map_file->ceil_color = convert_rgb(tex[1]);
	else if (map_file->floor_color == -1 && ft_strcmp(tex[0], "F") == 0)
		map_file->floor_color = convert_rgb(tex[1]);
	else
	{
		ft_clear_split(tex);
		free_map(map_file);
		error("Invalid texture");
	}
}

static void	process_texture_line(t_map *map_file, char *content)
{
	char	**tex;

	tex = ft_split(content, ' ');
	if (!tex)
	{
		free_map(map_file);
		error("Memory allocation failed");
	}
	add_texture(map_file, tex);
	ft_clear_split(tex);
}

void	check_textures(t_map *map_file)
{
	t_fifo	*file_content;
	char	*content;

	file_content = map_file->file_content;
	while (file_content->len > 0)
	{
		content = file_content->first->value;
		if (has_content(content))
		{
			if (!is_texture(content))
				break ;
			process_texture_line(map_file, content);
		}
		fifo_remove_first(file_content);
	}
	if (!(map_file->texture_no && map_file->texture_so && map_file->texture_ea
			&& map_file->texture_we && map_file->ceil_color != -1
			&& map_file->floor_color != -1))
	{
		free_map(map_file);
		error("Missing or invalid textures");
	}
}
