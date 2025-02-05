/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:25:20 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/05 00:04:14 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <stdbool.h>
# include <math.h>

# define FOV 90
# define PLAYER_SPEED 4
# define ROTATION_SPEED 0.042

typedef struct s_ray
{
	double	horizontal_x;
	double	horizontal_y;
	double	vertical_x;
	double	vertical_y;
	double	distance;
	double	angle;
}	t_ray;

typedef struct s_player
{
	int		x;
	int		y;
	double	fov;
	double	angle;
}	t_player;

#endif
