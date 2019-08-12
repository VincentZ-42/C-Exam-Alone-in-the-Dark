/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:19:29 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/10 19:58:05 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int		lg_seq_recur(int *count, struct s_node *node)
{
	int cur;
	int cur_r;
	int cur_l;

	if (!node)
		return (0);
	cur = 1;
	cur_r = lg_seq_recur(count, node->right);
	cur_l = lg_seq_recur(count, node->left);
	if (node->left)
		if (node->left->value != node->value + 1)
			cur_l = 0;
	if (node->right)
		if (node->right->value != node->value + 1)
			cur_r = 0;
	cur += (cur_r > cur_l) ? cur_r : cur_l;
	*count = (*count > cur) ? *count : cur;
	return (cur);
}

int		longest_sequence(struct s_node *node)
{
	int count = 0;

	if (!node)
		return (0);
	lg_seq_recur(&count, node);
	return (count);
}

//-----------------------------------------------------------------------
#define NODE(value, left, right) &(struct s_node){value, left, right}
#define N NULL
#include <stdio.h>

int		main(void)
{
	struct s_node *ex1 = NODE(10, 
			NODE(5, 
				NODE(6, 
					NODE(7, N, N), 
					NODE(13, N, N)),
			   	NODE(9, N, N)), 
			N);

	struct s_node *ex2 = NODE(5, 
			NODE(6, N, N),
			NODE(4,
				NODE(9, 
					NODE(3, N, N),
					NODE(2, N, N)),
				NODE(3, N,
					NODE(2, N, N))));
	struct s_node *ex3 = NODE(30, 
			NODE(15, 
				NODE(61, N, N), 
				N), 
			NODE(41,
				NODE(80, N, N),
				N));
	struct s_node *ex4 = NULL;
	
	printf("ex1: longest sequence = %d\n", longest_sequence(ex1));
	printf("ex2: longest sequence = %d\n", longest_sequence(ex2));
	printf("ex3: longest sequence = %d\n", longest_sequence(ex3));
	printf("ex4: longest sequence = %d\n", longest_sequence(ex4));

	return (0);
}
