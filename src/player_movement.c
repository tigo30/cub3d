/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:01:05 by joandre-          #+#    #+#             */
/*   Updated: 2025/03/09 02:42:31 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_player	rotation(t_data *cub, double speed)
{
	t_player	player;
	double		tmp_x;

	ft_bzero(&player, sizeof(t_player));
	player = *cub->player;
	tmp_x = player.direction.x;
	player.direction.x = player.direction.x * cos(speed)
		- player.direction.y * sin(speed);
	player.direction.y = tmp_x * sin(speed) + player.direction.y * cos(speed);
	tmp_x = player.plane.x;
	player.plane.x = player.plane.x * cos(speed) - player.plane.y * sin(speed);
	player.plane.y = tmp_x * sin(speed) + player.plane.y * cos(speed);
	return (player);
}

static bool	is_valid_move(t_data *cub, double x, double y)
{
	if (x < 0.25 || y < 0.25)
		return (false);
	if (x >= cub->map->width - 1.25 || y >= cub->map->height - 0.25)
		return (false);
	if (cub->map->matriz[(int)(y - 0.01)][(int)(x - 0.01)] != '0')
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
		cub->control = rotation(cub, ROTATION_SPEED * -1);
	else
		cub->control = rotation(cub, ROTATION_SPEED);
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
