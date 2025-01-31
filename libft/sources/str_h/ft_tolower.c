/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:59:13 by tgrunho-          #+#    #+#             */
/*   Updated: 2023/11/03 16:24:16 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int arg)
{
	if (arg >= 'A' && arg <= 'Z')
	{
		return (arg + 32);
	}
	return (arg);
}
/*int main()
{
    char uppercaseChar = 'A';
    
    int result1 = ft_tolower(uppercaseChar);
    printf("ft_tolower('%c') = '%c'\n", uppercaseChar, result1);
	return (0);
}*/