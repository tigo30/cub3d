/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:02:21 by tgrunho-          #+#    #+#             */
/*   Updated: 2024/03/18 22:54:09 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst == NULL)
	{
		new->next = NULL;
		*lst = new;
	}
	else
	{
		new->next = *lst;
		*lst = new;
	}
}
/*int main(void)
{
	void *content = "Ola";
	t_list *node = ft_lstnew("abc");
	t_list *new = ft_lstnew(content);
	
	ft_lstadd_front(&new, node);
	printf("%s\n", (char *) node->content);
	printf("%s", (char *) node->next->content);
}*/