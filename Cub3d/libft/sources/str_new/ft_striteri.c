/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:22:33 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/01/22 23:32:32 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (!s || !f)
	{
		return ;
	}
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*void custom_action(unsigned int index, char *c)
{
	printf("Caractere '%c' na posição %u\n", *c, index);
}

int	main(void) {
	char input[] = "Hello, World!";

	ft_striteri(input, custom_action);

	return (0);

}*/