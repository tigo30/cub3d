/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 08:21:12 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/02/05 00:45:19 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	*map_file;

	if (argc != 2)
		error("The program requires exactly one map file");
	map_file = get_map(argv[1]);
	if (init_libx(init_data(&data, map_file)))
		game_loop(&data);
	prog_cleanup(&data);
	error("Program left mlx_loop");
}

// int main(int argc, char **argv)
// {
//     t_map *map_file;

//     if (argc != 2)
//     {
//         printf("Usage: %s <map_file>\n", argv[0]);
//         return 1;
//     }

//     map_file = get_map(argv[1]);
//     if (!map_file)
//     {
//         printf("Failed to load the map.\n");
//         return 1;
//     }

//     // Exemplo: imprime o conteúdo do mapa (ajuste conforme necessário)
//     for (int i = 0; map_file->matriz[i]; i++)
//     {
//         printf("%s\n", map_file->matriz[i]);
//     }

//     // Lembre-se de liberar a memória, se aplicável
//     free_map(map_file);
    
//     return 0;
// }



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
