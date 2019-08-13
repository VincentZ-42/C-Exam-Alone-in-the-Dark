/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 10:35:56 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/12 10:58:00 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
 * Need above libary to use NULL
 * ret = leftmost node with lowest value
 * 1. go to the lowest node
 * 2. Recursively make links with pointers pointed to place fillers
 * 3. top node (bst) is then filled in between place fillers ...
 * ... to create the circular doubly linked list
 * 4. ret (lowest value) is then returned...
*/ 

struct s_node {
	int			value;
	struct s_node *right;
	struct s_node *left;
};

struct s_node	*convert_bst(struct s_node *bst)
{
	struct s_node *ret;

	if (!bst)
		return (NULL);
	ret = convert_bst(bst->left);
	bst->right = convert_bst(bst->right);
	if (ret)
	{
		ret->left->right = bst;
		bst->left = ret->left;
	}
	else
		ret = bst;
	if (bst->right)
	{
		bst->right->left->right = ret;
		ret->left = bst->right->left;
		bst->right->left = bst;
	}
	else
	{
		bst->right = ret;
		ret->left = bst;
	}
	return (ret);
}

//---------------------------------------------------------
#include <stdio.h>

void	print_list(struct s_node *cur)
{
	struct s_node *first = cur;

 	printf("%d", cur->value);
 	cur = cur->right;

 	while (cur != first)
 	{
 		printf(" -> %d", cur->value);
 		cur = cur->right;
 	}
 	printf("\n");
}

#define NODE(v, r, l) &(struct s_node){v, l, r}
int	main(void)
{
 	struct s_node *root = NODE(10,
 		NODE(5,
 			NODE(4,
 				NODE(2,
 					NODE(1, 0, 0),
 					NODE(3, 0, 0)
					),
 				0
				),
 			NODE(7,
 				NODE(6, 0, 0),
 				NODE(8, 0, 0)
 				)
 			),
 		NODE(12,
 			NODE(11, 0, 0),
 			NODE(15,
 				0,
 				NODE(17,
 					NODE(16, 0, 0),
 					NODE(20, 0, 0)
 					)
 				)
			)
 		);
 	print_list(convert_bst(root));
}
