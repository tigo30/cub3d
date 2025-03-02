/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 20:24:25 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/03/02 21:43:03 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *old, size_t old_size, size_t new_size)
{
	char	*new;

	if (!old)
		return ((char *)malloc((new_size)));
	new = (char *)malloc((new_size));
	if (!new)
		return (NULL);
	ft_memcpy(new, old, old_size);
	free(old);
	return (new);
}
