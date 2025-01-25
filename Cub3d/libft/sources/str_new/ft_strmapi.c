/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:38:25 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/01/22 23:32:35 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_s;
	unsigned int	i;

	i = 0;
	new_s = (char *)malloc(ft_strlen((const char *)s) + 1);
	if (new_s == NULL)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		new_s[i] = (*f)(i, s[i]);
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

/*char custom_transform(unsigned int index, char c)
 {
	// a função simplesmente retorna cada caractere em maiúsculas.
	if (c >= 'a' && c <= 'z') {
		return (c - 'a' + 'A');
	}
	return (c);
}
int main (void)
{
	const char *input = "Hello!";

	char *result;
	result = ft_strmapi(input, custom_transform);

	printf("String de entrada: %s\n", input);
	printf("String transformada: %s\n", result);

	free(result);

	return (0);
}*/