/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:25:20 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/28 23:18:58 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include <math.h>
# include <stddef.h>
# include <stdbool.h>
# include "../minilibx-linux/mlx.h"

# define TILE 64
# define PLAYER_SPEED 0.125
# define ROTATION_SPEED 0.15

typedef struct s_coori
{
	int	x;
	int	y;
}	t_coori;

typedef struct s_coor
{
	double	x;
	double	y;
}	t_coor;

typedef struct s_ray
{
	t_coori	position;
	t_coori	step;
	t_coor	direction;
	t_coor	side;
	t_coor	delta;
	double	distance;
	double	wall;
	double	camera;
	int		line;
	int		start;
	int		end;
	bool	flag;
}	t_ray;

typedef struct s_player
{
	t_coor		position;
	t_coor		direction;
	t_coor		plane;
}	t_player;

#endif
