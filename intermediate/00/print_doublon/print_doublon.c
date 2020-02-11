/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 11:23:34 by vzhao             #+#    #+#             */
/*   Updated: 2019/09/09 21:05:19 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
 * The arrays are already sorted, so better to compare as we move along
 * After the first match, we will need to print spaces
 * Using the length as while condition speeds up process
 * *a = int value of current index just like *str is current char
*/

void	print_doublon(int *a, int na, int *b, int nb)
{
	int first;

	first = 1;
	while (na && nb)
	{
		if (*a == *b)
		{
			if (first)
			{
				printf("%d", *a);
				first = 0;
			}
			else
				printf(" %d", *a);
			na--;
			nb--;
			a++;
			b++;
		}
		else if (*a > *b)
		{
			b++;
			nb--;
		}
		else if (*a < *b)
		{
			a++;
			na--;
		}
	}
	printf("\n");
}

// DO NOT SUBMIT MAIN
int		main(void)
{
	int a[] = { -5,  2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000 };
	int b[] = {   2,  4,  5,  6,  7, 10,  40,  70 };
	int na = 11;
	int nb = 8;

	print_doublon(a, na, b, nb);
	return (0);
}
