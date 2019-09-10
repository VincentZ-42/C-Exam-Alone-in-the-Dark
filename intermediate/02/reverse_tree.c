/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:34:21 by vzhao             #+#    #+#             */
/*   Updated: 2019/09/03 08:25:20 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int				value;
	struct s_node	*right;
	struct s_node	*left;
};

void	reverse_tree(struct s_node *root)
{
	struct s_node *temp;

	if (!root)
		return;
	temp = root->right;
	root->right = root->left;
	root->left = temp;

	reverse_tree(root->right);
	reverse_tree(root->left);
}

//--------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#define NODE(value, left, right) &(struct s_node){value, left, right}

void	print_in_order(struct s_node *node)
{
	if (!node)
 		return;

 	if (node->left)
 		print_in_order(node->left);
 	printf("%d, ", node->value);
 	if (node->right)
 		print_in_order(node->right);
}

int	main(void)
{
/*
            10
            / \
           11  9
          / \   \
         /   \   \
        6     9   8
       / \         \
      /   \         \
     7   13          7
    /                 \
   /                   \
  8                     6

 Longest sequence: 3 (6 -> 7 -> 8)
*/
	struct s_node *root1 = NODE(
 		10,
 		NODE(
 			11,
 			NODE(
 				6,
 				NODE(7, 
 					NODE(8, NULL, NULL),
 					NULL
 					),
 				NODE(13, NULL, NULL)
 				),
 			NODE(9, NULL, NULL)
 			),
 		NODE(
 			9,
 			NODE(
				8,
 				NODE(
 					7,
 					NODE(6, NULL, NULL),
 					NULL
 					),
 				NULL
 				),
 			NULL)
 		);
 	print_in_order(root1);
 	printf("\n");
 	reverse_tree(root1);
 	print_in_order(root1);
 	printf("\n");

 	struct s_node *root2 = NULL;
 	reverse_tree(root2);
	return (0);
}
