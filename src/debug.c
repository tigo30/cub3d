/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:02:18 by joandre-          #+#    #+#             */
/*   Updated: 2025/02/18 02:58:03 by joandre-         ###   ########.fr       */
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

void	print_texture(t_img *wall)
{
	if (wall == NULL)
		return ;
	printf("[img]\t\t[%p]\n[addr]\t\t[%p]\n", wall->img, wall->addr);
	printf("[bpp]\t\t[%i]\n[size_line]\t[%i]\n[endian]\t[%i]\n[width]\t\t[%i]\n[height]\t[%i]\n",
		wall->bpp, wall->size_line, wall->endian, wall->width, wall->height);
}

void	print_ray_data(t_ray *ray)
{
	if (ray == NULL)
		return ;
	printf("== [RAY DATA] ==\n");
	printf("[horizontal.x]\t[%f]\n[horinzontal.y]\t[%f]\n",
		ray->horizontal.x, ray->horizontal.y);
	printf("[vertical.x]\t[%f]\n[vertical.y]\t[%f]\n",
		ray->vertical.x, ray->vertical.y);
	printf("[angle]\t\t[%f]\n[flag]\t\t[%b]\n", ray->angle, ray->flag);
}

void	print_player_data(t_player *player)
{
	if (player == NULL)
		return ;
	printf("== [PLAYER DATA] ==\n");
	printf("[x]\t\t[%i]\n[y]\t\t[%i]\n[angle]\t\t[%f]\n[fov]\t\t[%f]\n",
		player->x, player->y, player->angle, player->fov);
}

void	print_data(t_data *cub)
{
	if (cub == NULL)
		return ;
	printf("=== [MAIN DATA STRUCT] ===\n");
	printf("[init]\t\t[%p]\n[window]\t[%p]\n", cub->init, cub->window);
	printf("== [DISPLAY] ==\n");
	print_texture(&cub->display);
	printf("== [NORTH WALL] ==\n");
	print_texture(&cub->wall->no);
	printf("== [SOUTH WALL] ==\n");
	print_texture(&cub->wall->so);
	printf("== [EAST WALL] ==\n");
	print_texture(&cub->wall->ea);
	printf("== [WEST WALL] ==\n");
	print_texture(&cub->wall->we);
	print_ray_data(cub->ray);
	print_player_data(cub->player);
	print_map_info(cub->map);
}
