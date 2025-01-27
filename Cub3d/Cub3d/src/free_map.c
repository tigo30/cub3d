/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:23:42 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/01/24 23:21:42 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_map(t_map *map_file)
{
	if (map_file == NULL)
		return ;
	if (map_file->matriz)
		ft_clear_split(map_file->matriz);
	if (map_file->texture_no)
	{
		free(map_file->texture_no);
		map_file->texture_no = NULL;
	}
	if (map_file->texture_so)
	{
		free(map_file->texture_so);
		map_file->texture_so = NULL;
	}
	if (map_file->texture_we)
	{
		free(map_file->texture_we);
		map_file->texture_we = NULL;
	}
	if (map_file->texture_ea)
	{
		free(map_file->texture_ea);
		map_file->texture_ea = NULL;
	}
	if (map_file->file_content)
	{
		fifo_free(map_file->file_content);
		map_file->file_content = NULL;
	}
	free(map_file);
}


