/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:34:15 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/09 16:17:33 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * is_looping uses a fast and slow iterator
 * fast jumps 2 nodes ahead
 * slow proceeds 1 node at a time
 * when they finally meet, if they ever do
 * this will end the iterating and return 1
*/

struct s_node {
	int value;
	struct s_node *next;
};

int		is_looping(struct s_node *node)
{
	if (!node || !node->next)
		return (0);
	struct s_node *fast;
	struct s_node *slow;

	slow = node;
	fast = node->next;
	while (fast->next && fast->next->next)
	{
		if (fast == slow)
			return (1);
		slow = slow->next;
		fast = fast->next->next;
	}
	return (0);
}

//------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#define CE(data) create_elem(data)

struct s_node	*create_elem(int data)
{
	struct s_node *node;

	if (!(node = (struct s_node*)malloc(sizeof(struct s_node))))
		return (NULL);
	node->value = data;
	node->next = NULL;
	return (node);
}

int		main(void)
{
	struct s_node *head;

	head = CE(12);
	head->next = CE(150);
	head->next->next = CE(30);
	head->next->next->next = CE(50);
	head->next->next->next->next = CE(345);
	head->next->next->next->next->next = CE(120);
	head->next->next->next->next->next->next = head->next;

/*	// This while loop prints ou the linked list to verify it exists
	// Don't use this when you make the loop
	while (head != 0)
	{
		printf("head->value = %d\n", head->value);
		head = head->next;
	}
*/
	printf("is_looping? %d\n", is_looping(head));
	return (0);
}
