/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:55:31 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/09 15:14:10 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
 * function traverses the n-ary tree recursively
 * Will stop once it lands on a leaf of a tree and return 0
 * Because recursive, it will +1 until it gets back to the root
*/

struct s_node {
	int				value;
	struct s_node	**nodes;
};

int		height_tree(struct s_node *root)
{
	int i;
	int max;
	int temp;

	if (!root)
		return (-1);
	i = 0;
	max = 0;
	printf("I am here: %d\n", root->value);
	while (root->nodes[i])
	{
		printf("%d, i=%d\n", root->value, i);
		temp = height_tree(root->nodes[i]) + 1;
		printf("%d, i=%d\n", root->value, i);
		max = (temp > max) ? temp : max;
		printf("max becomes %d\n", max);
		i++;
	}
	printf("max = %d---------------------\n", max);
	return (max);
}

//--------------------------------------------------------------------
#include <stdlib.h>

int	main(void)
{
 	struct s_node *node94 = malloc(sizeof(struct s_node));
 	struct s_node *node34 = malloc(sizeof(struct s_node));
	struct s_node *node52 = malloc(sizeof(struct s_node));
 	struct s_node *node1 = malloc(sizeof(struct s_node));
 	struct s_node *node99 = malloc(sizeof(struct s_node));
 	struct s_node *node11 = malloc(sizeof(struct s_node));
 	struct s_node *node13 = malloc(sizeof(struct s_node));

 	node94->nodes = malloc(sizeof(struct s_node) * 10);
	node94->value = 94;
 	node94->nodes[0] = node34;
 	node94->nodes[1] = node52;

 	node34->nodes = malloc(sizeof(struct s_node) * 10);
 	node34->value = 34;
	node34->nodes[0] = node1;
 	node34->nodes[1] = node99;

 	node52->nodes = malloc(sizeof(struct s_node) * 10);
 	node52->value = 52;
	node52->nodes[0] = node11;

 	node1->nodes = malloc(sizeof(struct s_node) * 10);
 	node1->value = 1;

 	node99->nodes = malloc(sizeof(struct s_node) * 10);
  	node99->value = 99;

 	node11->nodes = malloc(sizeof(struct s_node) * 10);
	node11->value = 11;
	node11->nodes[0] = node13;

 	node13->nodes = malloc(sizeof(struct s_node) * 10);
	node13->value = 13;

 	printf("height = %d\n", height_tree(node94));
}
