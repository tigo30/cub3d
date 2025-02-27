/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:01:05 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/27 20:44:04 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	is_valid_move(t_data *cub, double x, double y)
{
	if (x < 0.25 || y < 0.25)
		return (false);
	if (x >= cub->map->width - 1.25 || y >= cub->map->height - 0.25)
		return (false);
	if (cub->map->matriz[(int)y][(int)x] != '0')
		return (false);
	cub->control.position.x = x;
	cub->control.position.y = y;
	return (true);
}

bool	move_player(int keysym, t_data *cub)
{
	double	x;
	double	y;

	if (keysym == XK_w)
	{
		x = cub->player->position.x + cub->player->direction.x * PLAYER_SPEED;
		y = cub->player->position.y + cub->player->direction.y * PLAYER_SPEED;
	}
	if (keysym == XK_s)
	{
		x = cub->player->position.x - cub->player->direction.x * PLAYER_SPEED;
		y = cub->player->position.y - cub->player->direction.y * PLAYER_SPEED;
	}
	if (keysym == XK_a)
	{
		x = cub->player->position.x + cub->player->direction.y * PLAYER_SPEED;
		y = cub->player->position.y - cub->player->direction.x * PLAYER_SPEED;
	}
	if (keysym == XK_d)
	{
		x = cub->player->position.x - cub->player->direction.y * PLAYER_SPEED;
		y = cub->player->position.y + cub->player->direction.x * PLAYER_SPEED;
	}
	return (is_valid_move(cub, x, y));
}

int	rotate_player(int keysym, t_data *cub)
{
	if (keysym == XK_Left)
		(void)cub;
	else
		(void)cub;
	return (EXIT_SUCCESS);
}

int	player_movement(int keysym, t_data *cub)
{
	if (keysym == XK_Left || keysym == XK_Right)
		return (rotate_player(keysym, cub));
	if (keysym == XK_w || keysym == XK_s || keysym == XK_a || keysym == XK_d)
		if (move_player(keysym, cub))
			return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
/*
static bool	walk(int x, int y, t_player *player, t_map *map)
{
	int	new_x;
	int	new_y;

	new_x = player->position.x + x;
	new_y = player->position.y + y;
	if (new_x < 0 || new_y < 0 || new_x >= map->width || new_y >= map->height)
		return (false);
	if (map->matriz[new_y][new_x] == '1')
		return (false);
	player->position.x = new_x;
	player->position.y = new_y;
	return (true);
}

static bool	walk_player(int keysym, t_data *cub)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (keysym == XK_w)
	{
	}
	else if (keysym == XK_s)
	{
	}
	else if (keysym == XK_a)
	{
	}
	else if (keysym == XK_d)
	{
	}
	return (walk(x, y, cub->player, cub->map));
}

static void	rotate_player(int keysym, t_player *player)
{
	if (keysym == XK_Left)
	{
		(void)player;
	}
	else if (keysym == XK_Right)
	{
		(void)player;
	}
}

int	player_movement(int keysym, t_data *cub)
{
	if (keysym == XK_Left || keysym == XK_Right)
	{
		rotate_player(keysym, cub->player);
		return (raycasting(cub), EXIT_SUCCESS);
	}
	if (keysym == XK_w || keysym == XK_s || keysym == XK_a || keysym == XK_d)
	{
		if (walk_player(keysym, cub))
			return (raycasting(cub), EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}*/
