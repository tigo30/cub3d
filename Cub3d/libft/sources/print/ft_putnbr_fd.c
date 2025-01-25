/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:39:13 by tgrunho-          #+#    #+#             */
/*   Updated: 2023/11/03 12:59:23 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_module_fd(int n)
{
	if (n < 0)
		return (n * (-1));
	else
		return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
	}
	number = ft_module_fd(n);
	if (number > 9)
	{
		ft_putnbr_fd(number / 10, fd);
		ft_putchar_fd(number % 10 + '0', fd);
	}
	else
		ft_putchar_fd(number % 10 + '0', fd);
}

/*int	main(void)
{
	int t = 125466;
	int fd = 1;

	ft_putnbr_fd(t, fd);
	return (0);
}*/
