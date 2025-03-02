/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:21:12 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/03/02 19:13:27 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	convert_rgb(char *texture)
{
	char	**rgb;
	t_rgb	color;
	int		final_color;

	if (!texture)
		return (-1);
	rgb = ft_split(texture, ',');
	if (!rgb || ft_split_len(rgb) != 3)
		return (ft_clear_split(rgb), -1);
	color.r = ft_atoi(rgb[0]);
	color.g = ft_atoi(rgb[1]);
	color.b = ft_atoi(rgb[2]);
	ft_clear_split(rgb);
	if (color.r < 0 || color.r > 255 || color.g < 0 || color.g > 255
		|| color.b < 0 || color.b > 255)
		return (-1);
	final_color = (color.r << 16) | (color.g << 8) | color.b;
	return (final_color);
}
