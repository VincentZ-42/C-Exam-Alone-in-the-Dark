/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 16:02:58 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/11 17:57:46 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * First, we pass tree_size n answer into function as address (global-ish variables)
 * We count the tree size n check if even # of nodes
 * If not, then can't split...
 * If yes, then divide by 2, and run the count_nodes again
 * If the lengthes (left n right) of ANY NODE match tree_size, then success!
*/ 

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int		count_nodes(struct s_node *n, int *tree_size, int *answer)
{
	int count;

	if (!n || *answer == 1)
		return (0);

	count = 1 + count_nodes(n->left, tree_size, answer) \
			+ count_nodes(n->right, tree_size, answer);
	if (count == *tree_size)
		*answer = 1;
	return (count);
}

int		can_split(struct s_node *n)
{
	int tree_size = -1;
	int answer = 0;

	tree_size = count_nodes(n, &tree_size, &answer);
	if (tree_size % 2 == 1)
		return (0);
	tree_size /= 2;
	count_nodes(n, &tree_size, &answer);
	return (answer);
}

#define NODE(v, l, r) &(struct s_node){v, l, r}
#include <stdio.h>

int		main(void)
{
	struct s_node *ex1 = NODE(28,
			NODE(51,
				NODE(26,
					NODE(76, 0, 0),
					NODE(13, 0, 0)),
				NODE(48, 0, 0)),
			0);

	struct s_node *ex2 = NODE(30,
			NODE(15,
				NODE(61, 0, 0),
				0),
			NODE(41, 
				NODE(80, 0, 0),
				0));

	struct s_node *ex3 = NODE(10,
			0,
			NODE(12, 0, 0));

	struct s_node *ex4 = NODE(5,
			NODE(1, 0, 0),
			NODE(6, 
				NODE(7,
					NODE(3, 0, 0),
					NODE(2, 0, 0)),
				NODE(4,
					NODE(8, 0, 0),
					0)));

	printf("ex1: can split? %d\n", can_split(ex1));
	printf("ex2: can split? %d\n", can_split(ex2));
	printf("ex3: can split? %d\n", can_split(ex3));
	printf("ex4: can split? %d\n", can_split(ex4));
	return (0);
}
