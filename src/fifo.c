/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:24:22 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/03/02 19:17:28 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fifo.h"

t_fifo	*fifo_init(void)
{
	t_fifo	*fifo;

	fifo = (t_fifo *)malloc(sizeof(t_fifo));
	if (!fifo)
		return (NULL);
	fifo->first = NULL;
	fifo->last = NULL;
	fifo->len = 0;
	return (fifo);
}

void	fifo_add(t_fifo *fifo, char *value)
{
	t_node	*new_node;

	if (!fifo || !value)
		return ;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	if (fifo->len > 0)
	{
		new_node->prev = fifo->last;
		fifo->last->next = new_node;
		fifo->last = new_node;
	}
	else
	{
		new_node->prev = NULL;
		fifo->first = new_node;
		fifo->last = new_node;
	}
	fifo->len++;
}

void	fifo_remove_last(t_fifo *fifo)
{
	t_node	*tmp;

	if (!fifo || fifo->len == 0)
		return ;
	tmp = fifo->last;
	if (fifo->len == 1)
	{
		fifo->last = NULL;
		fifo->first = NULL;
	}
	else
	{
		fifo->last = tmp->prev;
		fifo->last->next = NULL;
	}
	fifo->len--;
	if (tmp->value)
		free(tmp->value);
	free(tmp);
}

void	fifo_free(t_fifo *fifo)
{
	if (!fifo)
		return ;
	while (fifo->len > 0)
		fifo_remove_last(fifo);
	free(fifo);
}

void	fifo_remove_first(t_fifo *fifo)
{
	t_node	*tmp;

	if (!fifo || fifo->len == 0)
		return ;
	tmp = fifo->first;
	if (fifo->len == 1)
	{
		fifo->first = NULL;
		fifo->last = NULL;
	}
	else
	{
		fifo->first = tmp->next;
		fifo->first->prev = NULL;
	}
	fifo->len--;
	if (tmp->value)
		free(tmp->value);
	free(tmp);
}
