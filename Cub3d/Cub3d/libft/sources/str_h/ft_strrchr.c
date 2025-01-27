/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:19:46 by tgrunho-          #+#    #+#             */
/*   Updated: 2024/04/10 07:20:23 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	hold;

	hold = -1;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			hold = i;
		i ++;
	}
	if (hold >= 0)
		return ((char *)&s[hold]);
	if (c == 0)
		return ((char *)&s[i]);
	return (0);
}
