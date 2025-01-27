/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:42:01 by tgrunho-          #+#    #+#             */
/*   Updated: 2024/03/18 22:54:29 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char	*buffer1;
	unsigned char	*buffer2;
	size_t			i;

	i = 0;
	buffer1 = (unsigned char *)ptr1;
	buffer2 = (unsigned char *)ptr2;
	while (i != num)
	{
		if (buffer1[i] != buffer2[i])
		{
			return (buffer1[i] - buffer2[i]);
		}
		i++;
	}
	return (0);
}
/*int main()
{
    char str1[] = "Hello";
    char str2[] = "World";

    int result = ft_memcmp(str1, str2, 3);

	if (result == 0)
    {
        printf("As primeiras 3 letras das strings são iguais.\n");
    }
    else if (result < 0)
    {
        printf("A primeira string é menor que a segunda.\n");
    }
    else
    {
        printf("A primeira string é maior que a segunda.\n");
    }
    return 0;
}*/