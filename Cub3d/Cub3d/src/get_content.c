/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:53:01 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/01/24 23:21:39 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	remove_nl(char *line)
{
	char	*newline_position;

	newline_position = ft_strrchr(line, '\n');
	if (newline_position)
		*newline_position = '\0';
}

t_fifo	*get_file_content(char *filename)
{
	int		fd;
	t_fifo	*file_content;
	char	*line;

	file_content = fifo_init();
	if (!file_content)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fifo_free(file_content);
		return (NULL);
	}
	line = get_next_line(fd);
	while (line)
	{
		remove_nl(line);
		fifo_add(file_content, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (file_content);
}


//EXEMPLO 

// Entrada (arquivo map.cub):
// Conteúdo do arquivo:

// NO ./textures/wall_north.xpm
// SO ./textures/wall_south.xpm
// WE ./textures/wall_west.xpm
// EA ./textures/wall_east.xpm
// 111111
// 100001
// 1001N1
// 111111



// Saída (t_fifo):
// A fila (t_fifo) armazenará cada linha como um item separado:

// t_fifo:
// [
//     "NO ./textures/wall_north.xpm", t_node
//     "SO ./textures/wall_south.xpm",
//     "WE ./textures/wall_west.xpm",
//     "EA ./textures/wall_east.xpm",
//     "111111",
//     "100001",
//     "1001N1",
//     "111111"
// ]