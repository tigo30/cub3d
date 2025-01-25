/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:48:17 by tgrunho-          #+#    #+#             */
/*   Updated: 2024/03/18 22:53:58 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int str)
{
	if ((str >= 'A' && str <= 'Z') || (str >= 'a' && str <= 'z'))
	{
		return (1);
	}
	return (0);
}
/*int main()
{
    char test_char = 'A';

    int result = ft_isalpha(test_char);

    printf("letra(%c): %d\n", test_char, result);

    return 0;
}*/