/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:14:44 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/27 00:47:23 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	**init_frame(void)
{
	int	**frame;
	int	i;

	frame = ft_calloc(sizeof(int *), HEIGHT);
	if (!frame)
		return (NULL);
	i = -1;
	while (++i < HEIGHT)
	{
		frame[i] = ft_calloc(sizeof(int), WIDTH);
		if (frame[i] == NULL)
		{
			while (i--)
				free(frame[i]);
			free(frame);
			return (NULL);
		}
	}
	return (frame);
}

void	init_data(t_data *cub)
{
	if (cub == NULL)
		return ;
	ft_bzero(cub, sizeof(cub));
	cub->init = NULL;
	cub->window = NULL;
	cub->frame = NULL;
	cub->wall = NULL;
	cub->map = NULL;
	cub->wall = NULL;
	cub->ray = NULL;
	cub->player = NULL;
}
