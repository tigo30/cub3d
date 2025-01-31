/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:54:12 by tgrunho-          #+#    #+#             */
/*   Updated: 2024/03/18 22:54:02 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int argument)
{
	if (argument >= '0' && argument <= '9')
	{
		return (argument);
	}
	return (0);
}

/*int	main(void)
{
	int t = 5;

	printf("%d", ft_isdigit(t));
	return (0);
}*/
