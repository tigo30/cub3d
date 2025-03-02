/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:27:41 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/03/02 18:59:08 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

void	check_file(char *filename)
{
	if (!filename || ft_strlen(filename) < 5)
		error("Invalid file name");
	if (ft_strcmp(&filename[ft_strlen(filename) - 4], ".cub") != 0)
		error("Invalid file type (must be .cub)");
	if (open_file(filename) != 1)
		error("File does not exist");
}
