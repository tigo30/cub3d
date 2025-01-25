/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 08:47:15 by tgrunho-          #+#    #+#             */
/*   Updated: 2023/10/25 16:36:38 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size_s1;

	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1 != '\0')
		s1++;
	size_s1 = ft_strlen((const char *)s1);
	while (ft_strchr(set, s1[size_s1]) && size_s1 != 0)
		size_s1--;
	return (ft_substr((char *)s1, 0, size_s1 + 1));
}

/*int main(void)
{
	char *str = "olamundooi";
	char *set = "mundo";

	// Chama a função ft_strtrim para remover os caracteres do conjunto `set`.
	char *trimmed_str = ft_strtrim(str, set);

	if (trimmed_str)
	{
		// Imprime a string resultante após a remoção.
		printf("String após a remoção: %s\n");

		// Lembre-se de liberar a memória alocada para a nova string.
		free(trimmed_str);
	}
	else
	{
		printf("A função ft_strtrim retornou NULL devido a entrada inválida.\n");
	}

	return (0);
}*/
