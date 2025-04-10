/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:14:55 by tgrunho-          #+#    #+#             */
/*   Updated: 2024/04/10 07:22:41 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (0);
	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i]
		&& i < n - 1 && s1[i] && s2[i])
		i ++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
