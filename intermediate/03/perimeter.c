/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perimeter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:10:50 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/11 17:54:53 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
 * perimeter prints root node,
 * print_left prints all values to the left of it
 * -- then any leaf nodes to the right
 *  print_right prints all leaf nodes to the left of the first
 * -- then recursively prints backwards all the right branches up to root
*/

struct	s_node	{
	int				value;
	struct s_node	*right;
	struct s_node	*left;
};

void	print_leaf(struct s_node *node)
{
	if (!node)
		return;
	if (!node->left && !node->right)
		printf(" %d", node->value);
	else
	{
		print_leaf(node->left);
		print_leaf(node->right);
	}
}

void	print_left(struct s_node *node)
{
	if (!node)
		return;
	printf(" %d", node->value);
	print_left(node->left);
	print_leaf(node->right);
}

void	print_right(struct s_node *node)
{
	if (!node)
		return;
	print_leaf(node->left);
	print_right(node->right);
	printf(" %d", node->value);
}

void	perimeter(struct s_node *root)
{
	if (!root)
		return;
	printf("%d", root->value);
	print_left(root->left);
	print_right(root->right);
	printf("\n");
}

#define NODE(v, l, r) &(struct s_node){v, r, l}
int		main(void)
{
	struct s_node *root = NODE(92,
			NODE(85,
				NODE(79,
					0,
					NODE(10, 
						NODE(39, 
							NODE(35,
								NODE(96, 0, 0),
								0),
							0),
						0)),
				0),
			NODE(26,
				0,
				NODE(64,
					NODE(40,
						NODE(88,
							NODE(12,
								NODE(58, 0, 0),
								0),
							NODE(55,
								NODE(58, 0, 0),
								NODE(41, 0, 0))),
						NODE(10,
							NODE(52,
								NODE(22, 0, 0),
								NODE(35, 0, 0)),
							NODE(87,
								0,
								NODE(31, 0, 0)))),
					NODE(78,
						NODE(2,
							NODE(33,
								0,
								NODE(55, 0, 0)),
							NODE(11,
								NODE(99, 0, 0),
								0)),
						NODE(85,
							0,
							NODE(51, 0, 0))))));

	perimeter(root);
	return (0);
}
