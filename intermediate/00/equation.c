/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 08:57:21 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/08 11:34:33 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void		equation(int n)
{
	int A = 0;
	int B = 0;
	int C = 0;

	while (A < 10)
	{
		B = 0;
		while (B < 10)
		{
			C = 0;
			while (C < 10)
			{
				if ((A*10 + B) + (C*10 + A) == n)
					printf("A = %d, B = %d, C = %d\n", A, B, C);
				C++;
			}
			B++;
		}
		A++;
	}
}

// DO NOT INCLUDE MAIN FUNCTION
#include <stdlib.h> // for atoi
int			main(int ac, char **av)
{
	if (ac == 2)
		equation(atoi(av[1]));
	return (0);
}
