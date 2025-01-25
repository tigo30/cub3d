/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:34:13 by tgrunho-          #+#    #+#             */
/*   Updated: 2023/10/25 16:35:53 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

/*int main(void)
{
	char *str = "Esta é uma string de teste.";

	ft_putstr_fd(str, 1); // Escreve a string na saída padrão (stdout)

	return (0);
}*/
