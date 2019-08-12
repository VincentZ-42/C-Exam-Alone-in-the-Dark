/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gold_gain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 17:20:42 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/11 18:45:40 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*
 * 1. Starting at the 1st col, we look backwards at the 3 options that
 * the gold-digger can come from and add the highest value 
 * 
 * 2. We then traverse the matrix a column at a time, repeating ^^^^
 * 
 * 3. Once we get to the last col, all rows should reflect the highest
 * amount the digger and each value is compared to find the max
 *
*/

int		max_of_three(int a, int b, int c)
{
	int max;

	if (a > b)
		max = (a > c) ? a : c;
	else
		max = (b > c) ? b : c;
	return (max);
}

int		gold_gain(int **mine, int n)
{
	int row;
	int col;
	int max;

	row = 0;
	col = 1;
	max = 0;
	while (col < n)
	{
		row = 0;
		while (row < n)
		{
			mine[row][col] += max_of_three(
				(row > 0) ? mine[row - 1][col - 1] : 0,
				mine[row][col - 1],
				(row < n - 1) ? mine[row + 1][col - 1] : 0);
			if (col == n - 1 && mine[row][col] > max)
				max = mine[row][col];
			row++;
		}
		col++;
	}
	return (max);
}

//-----------------------------------------------------------
// Have not tested yet.....Not sure if this works, but in theory it does....
