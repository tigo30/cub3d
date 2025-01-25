/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:24:58 by tgrunho-          #+#    #+#             */
/*   Updated: 2023/10/25 16:35:57 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}

/*int	main(void)
{
	char *str = "Esta é uma string de teste.";

	ft_putstr_fd(str, 1); // Escreve a string na saída padrão (stdout)

	return (0);
}*/