
#ifndef FIFO_H
# define FIFO_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	char			*value;  // Valor armazenado no nó
	struct s_node	*prev;   // Ponteiro para o nó anterior
	struct s_node	*next;   //Ponteiro para o próximo nó
}	t_node;

typedef struct s_fifo
{
	t_node	*first; //Primeiro nó da fila
	t_node	*last;  // Último nó da fila
	size_t	len;     // Comprimento da fila
}	t_fifo;

t_fifo	*fifo_init(void);             //Inicializa a fila
void	fifo_free(t_fifo *fifo);      //Libera a fila e todos os seus nós
void	fifo_add(t_fifo *fifo, char *value); // Adiciona um novo nó ao final
void	fifo_remove_last(t_fifo *fifo);      // Remove o último nó da fila
void	fifo_remove_first(t_fifo *fifo);     // Remove o primeiro nó da fila

#endif