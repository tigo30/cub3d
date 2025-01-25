/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:45:14 by tgrunho-          #+#    #+#             */
/*   Updated: 2024/03/18 22:53:51 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = s;
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
}

/*int	main(void)
{
	char	buffer[10];

	strncpy(buffer, "Hellohell", 10);
	printf("inicio: %s\n", buffer);
	ft_bzero(buffer, 5);
	printf("final: %s\n", buffer);
	return (0);
}*/
