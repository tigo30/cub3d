/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 20:24:25 by tgrunho-          #+#    #+#             */
/*   Updated: 2023/10/25 16:35:48 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	char			*dest;

	dest = b;
	i = 0;
	while (i < len)
	{
		dest[i] = c;
		i++;
	}
	return ((void *)b);
}

/*int main(void)
{
	char str[7];
	size_t len = 7;

	ft_memset(str, 'A', len);
	printf("str após ft_memset: %s\n", str);
	memset(str, 'B', len);
	printf("str após memset: %s\n", str);
	return (0);
}*/
