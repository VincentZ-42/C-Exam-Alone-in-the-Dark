/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 11:29:20 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/09 13:54:23 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
 * queue is a data structure that implements FIFO (First in, First Out)
 * Like waiting in a line...
 * Operates similiarly to Linked list
 * Each function adds to the utility of queue data structure
*/

struct s_node {
	void 			*content;
	struct s_node	*next;
};

struct s_queue {
	struct s_node	*first;
	struct s_node	*last;
};

struct s_queue		*init(void)
{
	struct s_queue *queue;

	if (!(queue = malloc(sizeof(struct s_queue))))
		return (NULL);
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

void	enqueue(struct s_queue *queue, void *content)
{
	struct s_node *temp;

	if (!queue)
		return ;
	if (!(temp = malloc(sizeof(struct s_node))))
		return ;
	temp->content = content;
	temp->next = NULL;
	if (queue->first == NULL)
		queue->first = temp;
	else
		queue->last->next = temp;
	queue->last = temp; 
}

void	*dequeue(struct s_queue *queue)
{
	struct s_node *temp;
	void *content;

	if (!queue || !queue->first)
		return (NULL);
	temp = queue->first;
	queue->first = temp->next;
	content = temp->content;
	if (temp == queue->last)
		queue->last = NULL;
	free(temp);
	return (content);
}

void	*peek(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return (NULL);
	return (queue->first->content);
}

int		isEmpty(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return (1);
	return (0);
}

//---------------------------------------------------------------
#include <stdio.h>

int		main(void)
{
	char a[] = "Apples"; (void)a;
 	char b[] = "Banananananas"; (void)b;
 	char c[] = "Charlemagne"; (void)c;
 	char d[] = "ddddduodenum"; (void)d;

	struct s_queue *queue = init();

	printf("isEmpty A: %d\n", isEmpty(queue));
	printf("added a\n");
 	enqueue(queue, a);
 	printf("isEmpty B: %d\n", isEmpty(queue));
 	printf("added b, c, d\n");
	enqueue(queue, b);
 	enqueue(queue, c);
 	enqueue(queue, d);

	printf("Peek: %s\n", peek(queue));
	printf("Pop: %s\n", dequeue(queue));
	printf("Pop: %s\n", dequeue(queue));
 	printf("Pop: %s\n", dequeue(queue));
 	printf("Pop: %s\n", dequeue(queue));
 	printf("Pop: %s\n", dequeue(queue));
 	printf("Peek: %s\n", peek(queue));
 	printf("isEmpty C: %d\n", isEmpty(queue));
 	return (0); 
}
