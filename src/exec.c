/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:34:24 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/09 16:59:40 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	execute(t_data *cub)
{
	if (!cub || FOV <= 0 || FOV >= 180)
		return (false);
	cub->ray = ft_calloc(1, sizeof(t_ray));
	cub->player = ft_calloc(1, sizeof(t_player));
	if (!cub->ray || !cub->player)
		return (false);
	game_loop(cub);
	return (true);
}
