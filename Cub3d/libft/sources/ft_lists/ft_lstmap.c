/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:01:57 by tgrunho-          #+#    #+#             */
/*   Updated: 2024/03/18 22:54:21 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*tmp;
	void	*content;

	if (lst == NULL)
		return (NULL);
	new_list = NULL;
	tmp = NULL;
	while (lst)
	{
		content = f(lst->content);
		tmp = ft_lstnew(content);
		if (!tmp)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (0);
		}
		ft_lstadd_back(&new_list, tmp);
		lst = lst->next;
	}
	return (new_list);
}
/*
*void	del(void *garen)
{
	garen = NULL;
}

void	*f(void *a)
{
	int		n;
	char 	*c;
	char	*str;

	c = (char *) a;
	str = ft_strdup(c);
	n = 0;
	while(str[n])
	{
		if (str[n] >= 'a' && str[n] <= 'z')
			str[n] = str[n] - 32;
		n++;
	}
	return (str);
}

int main(void)
{
	t_list *lst;
	t_list *lst1;

	lst = ft_lstnew("fF15");
	lst1 = ft_lstnew("fF16");
	ft_lstadd_back(&lst1, lst);
	lst = ft_lstmap(lst, f, del);
	printf("%s", (char *) lst->content);
}*/