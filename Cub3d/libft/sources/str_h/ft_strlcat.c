/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:53:30 by tgrunho-          #+#    #+#             */
/*   Updated: 2024/04/08 23:39:15 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	len_d;
	unsigned int	len_s;
	unsigned int	i;

	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	if (dstsize <= len_d)
		return (dstsize + ft_strlen(src));
	else
		len_s += len_d;
	i = 0;
	while (src[i] != '\0' && len_d < dstsize - 1)
	{
		dst[len_d] = src[i];
		i ++;
		len_d++;
	}
	dst[len_d] = '\0';
	return (len_s);
}
