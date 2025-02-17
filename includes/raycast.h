/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:25:20 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/16 19:42:21 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include <math.h>
# include <stddef.h>
# include <stdbool.h>
# include "../minilibx-linux/mlx.h"

# define HEIGHT 800
# define WIDTH 600
# define TILE 64
# define FOV 90
# define PLAYER_SPEED 4
# define ROTATION_SPEED 0.042

typedef struct s_coor
{
	double	x;
	double	y;
}	t_coor;

typedef struct s_ray
{
	t_coor	horizontal;
	t_coor	vertical;
	double	distance;
	double	angle;
	bool	flag;
}	t_ray;

typedef struct s_player
{
	int		x;
	int		y;
	double	angle;
	float	fov;
}	t_player;

float	normalize(float angle);
int		check_intersection(float angle, float *inter, float *step, bool flag);
bool	unit_circle(float angle, char c);

#endif
