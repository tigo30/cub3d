/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:04:04 by tgrunho-          #+#    #+#             */
/*   Updated: 2024/03/18 22:54:25 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		idx;
	t_list	*position;

	idx = 0;
	position = lst;
	while (position != NULL)
	{
		position = position->next;
		idx++;
	}
	return (idx);
}
/*int main(void)
{
	t_list *node1 = ft_lstnew("as");
	t_list *node2 = ft_lstnew("a");
	t_list *node3 = ft_lstnew("b");
	ft_lstadd_front(&node3, node2);
	ft_lstadd_front(&node2, node1);
	printf("%d", ft_lstsize(node1));
}*/
