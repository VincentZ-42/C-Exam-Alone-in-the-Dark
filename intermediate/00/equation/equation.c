/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <vzhao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 08:57:21 by vzhao             #+#    #+#             */
/*   Updated: 2020/02/11 09:59:49 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void		equation(int n)
{
	for (int A = 0; A < 10; A++)
		for (int B = 0; B < 10; B++)
			for (int C = 0; C < 10; C++)
				if (A * 10 + B + C * 10 + A == n)
					printf("A = %d, B = %d, C = %d\n", A, B, C);
}

#ifdef TEST

#include <stdlib.h> // for atoi

int			main(int ac, char **av)
{
	// Use this if you want to test an input
	if (ac == 2)
		equation(atoi(av[1]));
	
	// Use this if you want to test examples in instruction
/*
	int input = 42;
	printf("input = %d\n", input);
	equation(input);
	
	input = 111;
	printf("input = %d\n", input);
	equation(input);

	input = 0;
	printf("input = %d\n", input);
	equation(input);
*/	 
	return (0);
}

#endif
