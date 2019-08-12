/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 10:42:00 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/08 11:07:47 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_doublon(int *a, int na, int *b, int nb)
{
	int i;
	int j;
	int count;

	i = -1;
	count = 0;
	while (++i < na)
	{
		j = -1;
		while (++j < nb)
		{
			if (a[i] == b[j])
			{
				if (count > 0)
					printf(" ");
				printf("%d", a[i]);
				count++;
			}
		}
	}
	printf("\n");
}

int		main(void)
{
	int a[] = { 100,  200, 300 };
	int b[] = {  1,    2,   3, 4 };
	int na = 3;
	int nb = 4;

	print_doublon(a, na, b, nb);
	return (0);
}
