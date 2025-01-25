/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:53:01 by tgrunho-          #+#    #+#             */
/*   Updated: 2024/03/18 22:54:12 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*position;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		position = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = position;
	}
}
/*int main(void)
{
	t_list *node1 = ft_lstnew("ola");
	t_list *node2 = ft_lstnew("adeus");
	t_list **lst = &node1;
	ft_lstadd_front(lst, node2);
	ft_lstclear(lst, del);
}*/
