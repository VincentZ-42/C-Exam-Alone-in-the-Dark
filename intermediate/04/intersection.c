/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 10:59:50 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/12 11:12:06 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Loops lst2 for every value of lst1 until it finds a match
 * return 0 is same as return NULL
 * return void * because we are returning memory address
 *
*/

struct s_node {
	void			*content;
	struct s_node	*next;
};

void	*intersection(struct s_node *lst1, struct s_node *lst2)
{
	struct s_node *temp1 = lst1;
	struct s_node *temp2 = lst2;

	while (temp1 != 0)
	{
		temp2 = lst2;
		while (temp2 != 0)
		{
			if (temp1 == temp2)
				return (temp1);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return (0);
}

//-----------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

struct s_node *create_node(void)
{
	struct s_node *cur = malloc(sizeof(struct s_node));
	cur->next = 0;
 	cur->content = 0;
	return (cur);
}

int	main(void)
{
	struct s_node *head1 = create_node();
 	head1->next = create_node();
 	head1->next->next = create_node();
 	head1->next->next->next = create_node();
 	head1->next->next->next->next = create_node();

 	struct s_node *head2 = create_node();
 	head2->next = create_node();
 	head2->next->next = create_node();
 	head2->next->next->next = create_node();
 	head2->next->next->next->next = create_node();

 	printf("%p\n", intersection(head1, head2));

 	head2->next->next->next->next->next = head1->next->next->next->next;
 	printf("%p\n", intersection(head1, head2));
}
