/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:21:12 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/01/24 23:21:53 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	convert_rgb(char *texture)
{
	char	**rgb;  
	int		r;
	int		g;
	int		b;
	int		color; 
	size_t	len;

	if (!texture)
		return (-1);
	rgb = ft_split(texture, ',');
	if (!rgb)
		return (-1);
	len = ft_split_len(rgb);
	if (len != 3)
	{
		ft_clear_split(rgb);
		return (-1);
	}
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	ft_clear_split(rgb);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	color = (r << 16) | (g << 8) | b;
	return (color);
}

// int main(void)
// {
// 	// Testes de entrada válidos
// 	char *valid1 = "255,128,64";      // Cor válida
// 	char *valid2 = "0,0,0";          // Preto
// 	char *valid3 = "255,255,255";    // Branco

// 	// Testes de entrada inválidos
// 	char *invalid1 = "300,128,64";   // R fora do intervalo
// 	char *invalid2 = "255,-1,64";    // G fora do intervalo
// 	char *invalid3 = "255,64";       // Faltando um componente
// 	char *invalid4 = NULL;           // String nula
// 	char *invalid5 = " , , ";        // Somente vírgulas e espaços

// 	// Testando entradas válidas
// 	printf("Cor '%s': 0x%X\n", valid1, parse_rgb(valid1)); // Deve imprimir 0xFF8040
// 	printf("Cor '%s': 0x%X\n", valid2, parse_rgb(valid2)); // Deve imprimir 0x000000
// 	printf("Cor '%s': 0x%X\n", valid3, parse_rgb(valid3)); // Deve imprimir 0xFFFFFF

// 	// Testando entradas inválidas
// 	printf("Cor '%s': %d\n", invalid1, parse_rgb(invalid1)); // Deve imprimir -1
// 	printf("Cor '%s': %d\n", invalid2, parse_rgb(invalid2)); // Deve imprimir -1
// 	printf("Cor '%s': %d\n", invalid3, parse_rgb(invalid3)); // Deve imprimir -1
// 	printf("Cor (NULL): %d\n", parse_rgb(invalid4));         // Deve imprimir -1
// 	printf("Cor '%s': %d\n", invalid5, parse_rgb(invalid5)); // Deve imprimir -1

// 	return 0;
// }