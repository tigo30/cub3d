/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 08:21:12 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/02/23 03:25:04 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	cub;

	if (argc != 2)
		error("The program requires exactly one map file");
	init_data(&cub);
	if (load_data(&cub, argv[1]))
		execute(&cub);
	close_program(&cub);
	error("Program left mlx_loop");
	return (0);
}
