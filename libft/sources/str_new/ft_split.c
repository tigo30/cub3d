/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:58:18 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/03/02 21:43:39 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

static int	ft_size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

size_t	ft_split_len(char **split)
{
	size_t	len;

	len = 0;
	while (split[len])
		len++;
	return (len);
}

static void	ft_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**strs;
	int		size;
	int		j;

	i = 0;
	j = -1;
	strs = (char **)ft_calloc((ft_count_word(s, c) + 1), sizeof(char *));
	if (!strs)
		return (NULL);
	while (++j < ft_count_word(s, c))
	{
		while (s[i] == c)
			i++;
		size = ft_size_word(s, c, i);
		strs[j] = ft_substr(s, i, size);
		if (!strs[j])
		{
			ft_free(strs, j);
			return (NULL);
		}
		i += size;
	}
	return (strs);
}

/*int	main(void)
{
	char const	*str;
	char		c;
	char		**result;
	int			j;

	str = "Hello World Split Me";
	c = ' ';
	result = ft_split(str, c);
	if (result)
	{
		for (int i = 0; result[i]; i++)
			printf("Substring %d: %s\n", i, result[i]);
		// Libera memória alocada para o array de substrings e o array em si.
		j = -1;
		while (result[++j])
			free(result[j]);
		free(result);
	}
	else
		printf("A função ft_split retornou NULL devido a entrada inválida.\n");
	return (0);
}*/
