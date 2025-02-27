/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:29:16 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/27 16:16:39 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_texture(t_ray *ray)
{
	if (!ray->flag)
	{
		if (ray->direction.x < 0)
			return (WEST);
		else
			return (EAST);
	}
	else
	{
		if (ray->direction.y > 0)
			return (SOUTH);
		else
			return (NORTH);
	}
}
