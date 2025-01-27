/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:54:41 by tgrunho-          #+#    #+#             */
/*   Updated: 2023/11/03 16:24:44 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int arg)
{
	if (arg >= 'a' && arg <= 'z')
	{
		return (arg - 32);
	}
	return (arg);
}
/*int main()
{
    char uppercaseChar = 'a';
    
    int result1 = ft_toupper(uppercaseChar);
    printf("ft_toupper('%c') = '%c'\n", uppercaseChar, result1);
	return (0);
}*/