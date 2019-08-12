/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 14:10:38 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/11 17:52:21 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define MAX(a, b) ((a > b) ? a : b)

/*
 * Uses recursion to go all the way down the binary tree
 * Then counts the nodes as it goes back down the stack
 * --And stores longest length in cur_len which is returned
 * --and contributes to the total length as it goes down the stack
 * Max_width is calculated by adding both lengths from left n right nodes
 * from each recursion and comparing that to the global max
 * Works dynamically and changes max if it encounters a larger width
*/

struct	s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int		scan(struct s_node *node, int *max_width)
{
	int left;
	int right;
	int cur_len;
	int cur_width;

	if (!node)
		return (0);
	left = scan(node->left, max_width);
	right = scan(node->right, max_width);
	cur_len = 1 + MAX(left, right);
	cur_width = 1 + left + right;
	if (cur_width > *max_width)
		*max_width = cur_width;
	return (cur_len);
}

int		width_tree(struct s_node *n)
{
	int max_width = 0;
	scan(n, &max_width);
	return (max_width);
}

//-------------------------------------------------
#include <stdio.h>
#define NODE(value, left, right) &(struct s_node){value, left, right}
#define N NULL

int		main(void)
{
	struct s_node *ex1 = NODE(1, 
			NODE(2,
				NODE(3, N, N),	
				NODE(4, 
					NODE(6, N, N),
					N)),
			NODE(5,
				NODE(7, N, N),
				NODE(8, N, N)));
	struct s_node *ex2 = NODE(1, 
			NODE(2,
				NODE(4,
					NODE(5,
						N,
						NODE(8, N, N)),
					NODE(6, N, N)),
				NODE(7,
					NODE(9,
						NODE(11, N, N),
						NODE(12, N, N)),
					NODE(10,
						N,
						NODE(13, N, N)))),
			NODE(3, N, N));
	struct s_node *ex3 = NODE(10, 
			N, 
			NODE(12, N, N));
	struct s_node *ex4 = NODE(25, 
			NODE(33, 
				NODE(12, N, N),
				NODE(9, 
					NODE(3, N, N),
					N)),
			N);
	struct s_node *ex5 = NODE(10, N, N);
	struct s_node *ex6 = N;

	printf("ex1: width_tree = %d\n", width_tree(ex1));
	printf("ex2: width_tree = %d\n", width_tree(ex2));
	printf("ex3: width_tree = %d\n", width_tree(ex3));
	printf("ex4: width_tree = %d\n", width_tree(ex4));
	printf("ex5: width_tree = %d\n", width_tree(ex5));
	printf("ex6: width_tree = %d\n", width_tree(ex6));
	return (0);
}
