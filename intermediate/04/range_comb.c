/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_comb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:53:25 by vzhao             #+#    #+#             */
/*   Updated: 2019/09/02 14:52:23 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

/* 
 * Factorial funct
 * - Calculates the factorial of number (all possible permutations)
 * Permute funct
 * - Recursively filles up an int array (soln) before copying it into tab
 * -- Uses 2 int arrays (1 for availability) & (1 for solution combinations)
 * -- Once you reach n, it copies soln arr into tab arr
 * -- As it goes down the stack from recursion, it will fill up the soln arr...
 * ... again and keep going until each permutation is reached
 * Range_comb funct
 * - mallocs for our tab and each int array in our tab n NULL terminates it
 * - initializes available int array for usage
 * - Sends all variables into permute function for recursive filling
*/

int		factorial(int n)
{
	int ret = n;

	while (--n > 1)
		ret *= n;
	return (ret);
}

void	permute(int **tab, int *avail, int *soln, int n, int cur, int *soln_i)
{
	int i = -1;
	if (cur == n)
		memcpy(tab[++(*soln_i)], soln, n * sizeof(int));
	else
	{
		while (++i < n)
		{
			if (avail[i] == 1)
			{
				soln[cur] = i;
				avail[i] = 0;
				permute(tab, avail, soln, n, cur + 1, soln_i);
				avail[i] = 1;
			}
		}
	}
}

int		**range_comb(int n)
{
	if (n <= 0)
		return (NULL);
		
	int i = -1;
	int permutations = factorial(n);
	int soln[n];
	int avail[n];

	while (++i < n)
		avail[i] = 1;

	int **tab = malloc(sizeof(*tab) * (permutations + 1));
	tab[permutations] = NULL;

	i = -1;
	while (++i < permutations)
		tab[i] = malloc(sizeof(**tab) * n);

	int soln_i = -1;
	permute(tab, avail, soln, n, 0, &soln_i);
	return (tab);
}

//-------------------------------------------
#include <stdio.h>
int	main(void)
{
	int n = 3;
 	int **arr = range_comb(n);
 	int i = -1;
 	int j;
 	int size = factorial(n);
 	while (++i < size)
 	{
 		j = -1;
 		while (++j < n)
 			printf("%d, ", arr[i][j]);
 		printf("\n");
 	}
	free(arr);
	return (0);
}
