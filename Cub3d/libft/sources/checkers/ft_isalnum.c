/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:09:33 by tgrunho-          #+#    #+#             */
/*   Updated: 2024/03/18 22:53:55 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
	{
		return (1);
	}
	return (0);
}
/*int main()
{
    char test_char = 'A';

    int result = ft_isalnum(test_char);

    printf("(%c): %d\n", test_char, result);

    return 0;
}*/