/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:50:54 by tgrunho-          #+#    #+#             */
/*   Updated: 2024/03/18 22:54:15 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*position;

	if (!lst)
		return ;
	position = lst;
	while (position != NULL)
	{
		(*f)(position->content);
		position = position->next;
	}
}
/*
int main(void)
{
	t_list *node1 = ft_lstnew("ola");
	t_list *node2 = ft_lstnew("adeus");
	t_list **lst = &node1;
	ft_lstadd_front(lst, node2);
	ft_lstiter(lst, f);
}
*/