/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <vzhao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 08:29:32 by vzhao             #+#    #+#             */
/*   Updated: 2020/02/11 09:56:10 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/* 
 * increment i up to value of n
 * send i into counter func to see if there are any 2's (of any tenth place)
*/

void	counter(int n, int *count)
{
	if (n > 9)
		counter(n / 10, count);
	if (n % 10 == 2)
		*count += 1;
}

int		count_of_2(int n)
{
	int count = 0;
	int i = 1;

	if (n <= 1)
		return (0);
	while (++i <= n)
		counter(i, &count);
	return (count);
}

#ifdef TEST

#include <stdio.h> // for printf
#include <stdlib.h> // for atoi

// Usage:
// 1. Compile in terminal with: gcc -Wall -Wextra -Werror -DTEST count_of_2.c
// 2. Run executable to test inputs: ./a.out ## (## = any positive number)

int		main(int ac, char **av)
{
	if (ac == 2)
		printf("input = %d\noutput = %d\n", atoi(av[1]), count_of_2(atoi(av[1])));
	return (1);
}

#endif
