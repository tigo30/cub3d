/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:53:01 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/01/25 11:20:03 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"



int	has_non_space(char *nbr)
{
	int	i;

	i = 0;
	while (nbr[i] && nbr[i] == ' ')
		i++;
	return (nbr[i] != '\0');
}

void	check_textures(t_map *map_file)
{
	t_fifo	*file_content;
	char	**texture;
	int i;
	char *content;
	int color;

	i = 0;
	file_content = map_file->file_content;
	while (file_content->len > 0)
	{
		if (has_non_space(file_content->first->value))
		{
			content = file_content->first->value;
			while (content[i] && content[i] == ' ')
				i++;
			if (!(content[i] == 'N' || content[i] == 'S' || content[i] == 'E' || content[i] == 'W' || content[i] == 'C' || content[i] == 'F'))
				break;

			texture = ft_split(content, ' ');

			
			if (ft_strcmp(texture[0], "NO") == 0 || ft_strcmp(texture[0], "SO") == 0 ||
				ft_strcmp(texture[0], "EA") == 0 || ft_strcmp(texture[0], "WE") == 0)
			{
				if ((ft_strcmp(texture[0], "NO") == 0 && !map_file->texture_no) ||
					(ft_strcmp(texture[0], "SO") == 0 && !map_file->texture_so) ||
					(ft_strcmp(texture[0], "EA") == 0 && !map_file->texture_ea) || (ft_strcmp(texture[0], "WE") == 0 && !map_file->texture_we))
				{
					if (ft_strcmp(texture[0], "NO") == 0)
						map_file->texture_no = ft_strdup(texture[1]);
					else if (ft_strcmp(texture[0], "SO") == 0)
						map_file->texture_so = ft_strdup(texture[1]);
					else if (ft_strcmp(texture[0], "EA") == 0)
						map_file->texture_ea = ft_strdup(texture[1]);
					else if (ft_strcmp(texture[0], "WE") == 0)
						map_file->texture_we = ft_strdup(texture[1]);
				}
			}
			else if (ft_strcmp(texture[0], "C") == 0 || ft_strcmp(texture[0], "F") == 0)
			{
				color = convert_rgb(texture[1]);
				if (ft_strcmp(texture[0], "C") == 0 && map_file->ceil_color == -1)
					map_file->ceil_color = color;
				else if (ft_strcmp(texture[0], "F") == 0 && map_file->floor_color == -1)
					map_file->floor_color = color;
			}
			ft_clear_split(texture);
		}
		fifo_remove_first(file_content);
	}
	if (!(map_file->texture_no && map_file->texture_so && map_file->texture_ea && map_file->texture_we && map_file->ceil_color != -1 && map_file->floor_color != -1))
	{
		free_map(map_file);
		error("Missing textures or colors");
	}
}
// adicionar os restantes free e limpar memoria....