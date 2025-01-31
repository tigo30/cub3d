/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:42:14 by tgrunho-          #+#    #+#             */
/*   Updated: 2024/03/18 22:54:08 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (!last)
	{
		*lst = new;
	}
	else
		last->next = new;
}

/*int main(void)
{
	t_list *node = ft_lstnew("abc");
	t_list *new = ft_lstnew("def");
	
	ft_lstadd_back(&node, new);
	printf("%s\n", (char *) node->next->content);
}*/
