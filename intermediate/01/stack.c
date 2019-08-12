/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 10:37:32 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/09 13:55:24 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
 * Data structure that implements FILO (First in, Last Out)
 * Works similarily to Linked List or memory where you have to deal with the top
 * before getting to the bottom
*/

struct s_node {
	void			*content;
	struct s_node	*next;
};

struct s_stack {
	struct s_node	*top;
};

struct s_stack		*init(void)
{
	struct s_stack *stack;
	
	if (!(stack = malloc(sizeof(struct s_stack))))
		return (NULL);
	stack->top = NULL;
	return (stack);
}

void				*pop(struct s_stack *stack)
{
	struct s_node *node;
	void *content;

	if (!stack || !stack->top)
		return (NULL);
	if (!(node = malloc(sizeof(struct s_node))))
		return (NULL);
	node = stack->top;
	content = node->content;
	stack->top = node->next;
	free(node);
	return (content);	
}

void				push(struct s_stack *stack, void *content)
{
	struct s_node *node;

	if (!stack)
		return ;
	if (!(node = malloc(sizeof(struct s_node))))
		return ;
	node->content = content;
	node->next = stack->top;
	stack->top = node;
}

void				*peek(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return (NULL);
	return (stack->top->content);
}

int					isEmpty(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return (1);
	return (0);
}

//---------------------------------------------------------------------
#include <stdio.h>

int		main(void)
{
 	char a[] = "aaaaa";			(void)a;
 	char b[] = "bbbbb";			(void)b;
 	char c[] = "ccccc";			(void)c;
 	char d[] = "dddddicks";		(void)d;
 	struct s_stack *stack;

 	stack = init(); 			(void)stack;
 	printf("isEmpty: %d\n", isEmpty(stack));
 	printf("peek: %s\n", peek(stack));
 	printf("pop: %s\n", pop(stack));
 	push(stack, a); push(stack, b); push(stack, c); push(stack, d);
	printf("push a, then b, then c, then d\n");
 	printf("isEmpty: %d\n", isEmpty(stack));
 	printf("peek: %s\n", peek(stack));
 	printf("pop: %s\n", pop(stack));
 	printf("pop: %s\n", pop(stack));
	printf("pop: %s\n", pop(stack));
 	printf("pop: %s\n", pop(stack));
 	printf("pop: %s\n", pop(stack));
 	printf("isEmpty: %d\n", isEmpty(stack));

	return (0);
}
