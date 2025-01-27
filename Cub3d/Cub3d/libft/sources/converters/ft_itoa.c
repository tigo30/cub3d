/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:09:58 by tgrunho-          #+#    #+#             */
/*   Updated: 2024/03/18 22:54:05 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_digits(int n)
{
	int	result;

	result = 0;
	if (n == 0)
	{
		return (1);
	}
	else if (n < 0)
	{
		n *= -1;
		result++;
	}
	while ((unsigned int)n > 0)
	{
		n = (unsigned int)n / 10;
		result++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		num_digits;

	num_digits = ft_number_digits(n);
	res = ft_calloc((num_digits + 1), sizeof(char));
	if (res == NULL)
		return (NULL);
	if (n == 0)
	{
		res[0] = 48;
		return (res);
	}
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	while ((num_digits - 1) >= 0 && (unsigned int)n > 0)
	{
		res[num_digits - 1] = ((unsigned int)n % 10) + '0';
		n = (unsigned int)n / 10;
		num_digits--;
	}
	return (res);
}
/*int main(void)
 {
	int num = 0;
	char *str = ft_itoa(num);

	printf("Número como string: %s\n", str);
	free(str);
	return (0);
}*/
