/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_fifo_to_matriz.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 09:39:57 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/03/02 19:02:05 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*pad_line_with_spaces(char *line, size_t target_length)
{
	char	*padded_line;
	size_t	line_length;
	size_t	i;

	line_length = ft_strlen(line);
	if (line_length == target_length)
		return (ft_strdup(line));
	padded_line = (char *)malloc((target_length + 1) * sizeof(char));
	if (!padded_line)
		return (NULL);
	i = 0;
	while (i < target_length)
	{
		if (i < line_length)
			padded_line[i] = line[i];
		else
			padded_line[i] = ' ';
		i++;
	}
	padded_line[i] = '\0';
	return (padded_line);
}

size_t	find_max_line_length(t_fifo *file_content)
{
	t_node	*current;
	size_t	line_length;
	size_t	max_length;

	max_length = 0;
	current = file_content->first;
	while (current)
	{
		line_length = ft_strlen(current->value);
		if (line_length > max_length)
			max_length = line_length;
		current = current->next;
	}
	return (max_length);
}

int	normalize_line_lengths(t_fifo *file_content)
{
	t_node	*current;
	char	*new_line;
	size_t	max_line_length;

	max_line_length = find_max_line_length(file_content);
	current = file_content->first;
	while (current)
	{
		new_line = pad_line_with_spaces(current->value, max_line_length);
		if (!new_line)
			return (-1);
		free(current->value);
		current->value = new_line;
		current = current->next;
	}
	return (0);
}

char	**convert_fifo_to_matriz(t_fifo *file_content)
{
	char	**matriz;
	char	*nbr;

	if (!file_content || file_content->len == 0)
		return (NULL);
	if (normalize_line_lengths(file_content) != 0)
		return (NULL);
	matriz = (char **)malloc((file_content->len + 1) * sizeof(char *));
	if (!matriz)
		return (NULL);
	matriz[file_content->len] = NULL;
	while (file_content->len > 0)
	{
		nbr = file_content->last->value;
		file_content->last->value = NULL;
		matriz[file_content->len - 1] = nbr;
		fifo_remove_last(file_content);
	}
	return (matriz);
}
