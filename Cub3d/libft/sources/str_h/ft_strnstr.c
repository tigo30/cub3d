/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:47:32 by tgrunho-          #+#    #+#             */
/*   Updated: 2023/10/25 16:36:30 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *need, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (need[0] == '\0')
	{
		return ((char *)s);
	}
	while (s[i] != '\0' && i < len)
	{
		while (s[i + j] == need[j] && i + j < len)
		{
			if (need[j + 1] == '\0')
			{
				return ((char *)&s[i]);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

/*int	main(void)
{
	const char	*t = "Esta é uma string de teste.";
	const char	*n = "é";
	char		*d;

	d = ft_strnstr(t, n, 8);
	printf("%s\n", d);
	return (0);
}*/
