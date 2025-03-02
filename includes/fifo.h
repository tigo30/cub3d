/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:47:29 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/03/02 21:47:31 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIFO_H
# define FIFO_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	char			*value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_fifo
{
	t_node	*first;
	t_node	*last;
	size_t	len;
}	t_fifo;

t_fifo	*fifo_init(void);
void	fifo_free(t_fifo *fifo);
void	fifo_add(t_fifo *fifo, char *value);
void	fifo_remove_last(t_fifo *fifo);
void	fifo_remove_first(t_fifo *fifo);

#endif