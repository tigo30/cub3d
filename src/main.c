/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 08:21:12 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/02/13 23:29:03 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../includes/cub3d.h"

// int	main(int argc, char **argv)
// {
// 	t_data	data;
// 	t_map	*map_file;

// 	if (argc != 2)
// 		error("The program requires exactly one map file");
// 	map_file = get_map(argv[1]);
// 	if (init_libx(init_data(&data, map_file)))
// 		execute(&data);
// 	prog_cleanup(&data);
// 	free_map(map_file);
// 	error("Program left mlx_loop");
// 	return (0);
// }




#include <stdio.h>

void print_map_matrix(char **matrix, int height)
{
    if (!matrix)
    {
        printf("Matriz do mapa está vazia.\n");
        return;
    }
    printf("\nMatriz do Mapa:\n");
    for (int i = 0; i < height; i++)
        printf("%s\n", matrix[i]);
}

void print_map_info(t_map *map_file)
{
    if (!map_file)
    {
        printf("Erro ao carregar o ficheiro do mapa.\n");
        return;
    }

    printf("=== Informações do Mapa ===\n");
    printf("Largura: %d\n", map_file->width);
    printf("Altura: %d\n", map_file->height);

    printf("\n=== Texturas ===\n");
    printf("Norte: %s\n", map_file->texture_no ? map_file->texture_no : "Não definida");
    printf("Sul: %s\n", map_file->texture_so ? map_file->texture_so : "Não definida");
    printf("Este: %s\n", map_file->texture_ea ? map_file->texture_ea : "Não definida");
    printf("Oeste: %s\n", map_file->texture_we ? map_file->texture_we : "Não definida");

    printf("\n=== Cores ===\n");
    printf("Teto (Ceil): %d\n", map_file->ceil_color);
    printf("Chão (Floor): %d\n", map_file->floor_color);

    printf("\n=== Posição do Jogador ===\n");
    if (map_file->player_x != -1 && map_file->player_y != -1)
        printf("Posição: (%d, %d)\nDireção: %c\n", map_file->player_x, map_file->player_y, map_file->player_direction);
    else
        printf("Posição do jogador não encontrada no mapa.\n");

    print_map_matrix(map_file->matriz, map_file->height);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Uso: %s <mapa.cub>\n", argv[0]);
        return (1);
    }

    t_map *map_file = get_map(argv[1]);
    if (!map_file)
    {
        printf("Falha ao carregar o mapa.\n");
        return (1);
    }

    print_map_info(map_file);

    free_map(map_file);

    return (0);
}













// int	main(int argc, char **argv)
// {
// 	t_data	data;
// 	t_map	*map_file;

// 	if (argc != 2)
//     	error("The program requires exactly one map file");
// 	map_file = get_map(argv[1]);
// 	if (init_libx(init_data(&data, map_file)) == false)
// 	{
// 		prog_cleanup(&data);
// 		exit(EXIT_FAILURE);
// 	}
// 	game_loop(&data);





	
	// // Exibe informações do mapa (substitua pelos campos reais de `t_map`)
	// printf("Map loaded successfully!\n");
	// printf("Width: %d\n", map_file->width);
	// printf("Height: %d\n", map_file->height);
	// printf("Player position: (%d, %d)\n", map_file->player_x, map_file->player_y);
	// printf("Player direction: %c\n", map_file->player_direction);

	// // Testa se a matriz do mapa foi carregada (exemplo de impressão)
	// if (map_file->matrix)
	// {
	// 	printf("Map matriz:\n");
	// 	for (int i = 0; i < map_file->height; i++)
	// 	{
	// 		printf("%s\n", map_file->matriz[i]);
	// 	}
	// }

	// // Libera os recursos do mapa
	// free_map_file(map_file);

	// return (0);








//EXEMPLO 

// Entrada (arquivo map.cub):
// Conteúdo do arquivo:

// NO ./textures/wall_north.xpm
// SO ./textures/wall_south.xpm
// WE ./textures/wall_west.xpm
// EA ./textures/wall_east.xpm
// 111111
// 100001
// 1001N1
// 111111



// Saída (t_fifo):
// A fila (t_fifo) armazenará cada linha como um item separado:

// t_fifo:
// [
//     "NO ./textures/wall_north.xpm", t_node
//     "SO ./textures/wall_south.xpm",
//     "WE ./textures/wall_west.xpm",
//     "EA ./textures/wall_east.xpm",
//     "111111",
//     "100001",
//     "1001N1",
//     "111111"
// ]
