/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:02:18 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/26 22:14:12 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

void	print_map_matrix(char **matrix, int height)
{
	if (!matrix)
	{
		printf("Matriz do mapa está vazia.\n");
		return;
	}
	printf("[MAP MATRIX]\n");
	for (int i = 0; i < height; i++)
		printf("%s\n", matrix[i]);
}

void	print_map_info(t_map *map_file)
{
    if (!map_file)
    {
        printf("Erro ao carregar o ficheiro do mapa.\n");
        return;
    }
    printf("== MAP DATA ==\n");
    printf("[width]\t\t[%d]\n", map_file->width);
    printf("[height]\t[%d]\n", map_file->height);
    printf("[texture_no]\t[%s]\n", map_file->texture_no ? map_file->texture_no : "Não definida");
    printf("[texture_so]\t[%s]\n", map_file->texture_so ? map_file->texture_so : "Não definida");
    printf("[texture_ea]\t[%s]\n", map_file->texture_ea ? map_file->texture_ea : "Não definida");
    printf("[texture_we]\t[%s]\n", map_file->texture_we ? map_file->texture_we : "Não definida");
    printf("[CEIL]\t\t[%d]\n", map_file->ceil_color);
    printf("[FLOOR]\t\t[%d]\n", map_file->floor_color);
    if (map_file->player_x != -1 && map_file->player_y != -1)
        printf("[player_x]\t[%d]\n[player_y]\t[%d]\n[direction]\t[%c]\n", map_file->player_x, map_file->player_y, map_file->player_direction);
    else
        printf("Posição do jogador não encontrada no mapa.\n");
    print_map_matrix(map_file->matriz, map_file->height);
}


void	print_wall_pixel_data(int **wall)
{
	int	i;
	int	x;

	i = -1;
	while (++i < 4)
	{
		x = -1;
		printf("== WALL %d ==\n", i);
		while (++x < (TILE * TILE) - 1)
			printf("[%d]", wall[i][x]);
		printf("\n");
	}
}

void	print_frame_data(int **frame)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		printf("== ROW %d ==\n", y);
		x = -1;
		while (++x < WIDTH)
			printf("[%d]", frame[y][x]);
	}
}

void print_ray_data(t_ray *ray)
{
    if (ray == NULL)
        return;
    printf("== [RAY DATA] ==\n");
    printf("[position.x]\t[%d]\n[position.y]\t[%d]\n", ray->position.x, ray->position.y);
    printf("[step.x]\t[%d]\n[step.y]\t[%d]\n", ray->step.x, ray->step.y);
    printf("[direction.x]\t[%f]\n[direction.y]\t[%f]\n", ray->direction.x, ray->direction.y);
    printf("[side.x]\t[%f]\n[side.y]\t[%f]\n", ray->side.x, ray->side.y);
    printf("[delta.x]\t[%f]\n[delta.y]\t[%f]\n", ray->delta.x, ray->delta.y);
    printf("[distance]\t[%f]\n[wall]\t\t[%f]\n[camera]\t[%f]\n", ray->distance, ray->wall, ray->camera);
    printf("[line]\t\t[%d]\n[start]\t\t[%d]\n[end]\t\t[%d]\n", ray->line, ray->start, ray->end);
    printf("[flag]\t\t[%s]\n", ray->flag ? "true" : "false");
}

void print_player_data(t_player *player)
{
    if (player == NULL)
        return;
    printf("== [PLAYER DATA] ==\n");
    printf("[position.x]\t[%f]\n[position.y]\t[%f]\n", player->position.x, player->position.y);
    printf("[direction.x]\t[%f]\n[direction.y]\t[%f]\n", player->direction.x, player->direction.y);
    printf("[plane.x]\t[%f]\n[plane.y]\t[%f]\n", player->plane.x, player->plane.y);
}

void	print_data(t_data *cub)
{
	if (cub == NULL)
		return ;
	printf("=== [MAIN DATA STRUCT] ===\n");
	printf("[init]\t\t[%p]\n[window]\t[%p]\n", cub->init, cub->window);
	print_ray_data(cub->ray);
	print_player_data(cub->player);
	print_map_info(cub->map);
}
