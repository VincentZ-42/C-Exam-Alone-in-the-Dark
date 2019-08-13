/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 11:18:00 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/12 12:25:48 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Make sure to keep referrences to the head of the input list and your clone
 * Use the clones to traverse the lists
 * 1. Create the clone head
 * 2. Clone the entire list using node->next pointers
 * 3. Set node->other to proper nodes by traversing again and ...
 * ... make sure to find the right nodes to set as pointers
*/ 

#include <stdlib.h>

struct s_node {
	int				data;
	struct s_node	*next;
	struct s_node	*other;
};

struct s_node	*ft_create(struct s_node *node)
{
	struct s_node *new;

	if (!(new = (struct s_node*)malloc(sizeof(struct s_node))))
		return (NULL);
	new->data = node->data;
	new->next = NULL;
	new->other = NULL;
	return (new);
}

struct s_node	*clone_list(struct s_node *node)
{
	struct s_node *r_node;
	struct s_node *clone;
	struct s_node *r_clone;
	struct s_node *find_node;
	struct s_node *find_clone;

	if (!node)
		return (NULL);
	r_node = node;
	clone = ft_create(node);
	r_clone = clone;
	while (r_node->next)
	{
		r_clone->next = ft_create(r_node->next);
		r_node = r_node->next;
		r_clone = r_clone->next;
	}
	r_clone = node;
	r_clone = clone;
	while (r_node)
	{
		if (r_node->other == r_node)
			r_clone->other = r_clone;
		else if (r_node->other)
		{
			find_node = node;
			find_clone = clone;
			while (r_node->other != find_node)
			{
				find_node = find_node->next;
				find_clone = find_clone->next;
			}
			r_clone->other = find_clone;
		}
		r_node = r_node->next;
		r_clone = r_clone->next;
	}
	return (clone);
}

//-------------------------------------------------------------------------
#include <stdio.h>
#define CE(node) ft_create(node);
void	print_list(struct s_node *head)
{
 	while (head)
 	{
 		printf("Node: %p\nData: %d\nNext: %p\nOther: %p\n", head, head->data, head->next, head->other);
 		if (head->other)
 			printf("%d", head->other->data);
 		printf("\n---\n");
		head = head->next;
	}
}

int		main(void)
{

	struct s_node *node = malloc(sizeof(struct s_node));
	node->data = 5;
	node->next = NULL;
	node->other = NULL;
 	struct s_node *head = CE(node);
 	head->next = CE(node);
 	head->next->next = CE(node);
 	head->next->next->next = CE(node);
 	head->next->next->next->next = CE(node);
 	head->next->next->next->next->next = CE(node);
 	head->next->next->next->next->next->other = head->next->next->next->next; //25
 	head->next->next->next->next->other = head; //5
 	head->next->next->next->other = head->next; //10
 	head->next->next->other = head->next->next; //15
 	print_list(head);
 	printf("\n\n");

	print_list(clone_list(head));
}
