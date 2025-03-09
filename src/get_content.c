/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:53:01 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/03/08 22:47:59 by joandre-         ###   ########.fr       */
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
	if (!line)
		return (fifo_free(file_content), NULL);
	while (line)
	{
		remove_nl(line);
		fifo_add(file_content, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (file_content);
}
