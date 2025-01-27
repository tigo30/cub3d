/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:34:49 by tgrunho-          #+#    #+#             */
/*   Updated: 2024/03/18 22:53:53 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*pointer;

	pointer = malloc(nitems * size);
	if (pointer == NULL)
		return (NULL);
	ft_bzero(pointer, nitems * size);
	return (pointer);
}

/*int	main(void)
{
	size_t	num_elements;
	size_t	element_size;
	int		*arr;
	size_t	i;

	num_elements = 5;
	element_size = sizeof(int);
	arr = (int *)ft_calloc(num_elements, element_size);
	if (arr == NULL)
	{
		printf("Falha na alocação de memória.\n");
		return (0);
	}
	i = 0;
	while (i < num_elements)
	{
		printf("arr[%zu] = %d\n", i, arr[i]);
		i++;
	}
	free(arr);
	return (0);
}*/
