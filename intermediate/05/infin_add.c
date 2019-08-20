/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 18:26:09 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/19 17:36:55 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
//----------------
#include <stdio.h>
//----------------
/* 
 * Functions needed for this:
 *  -ft_strlen
 *  -ft_strcmp
 *  -init_str
 *  -biggest_First
 *  -check_negative
 *  -add
 *  -subtract
 *
 *  1.  we reorganize the two inputs, putting the larger of the 2 inputs...
 *  ...size-wise (first) and not account for negative
 *  2. Then we use the length of the bigger input to initialize our output
 *  3. Run both inputs through check negative function
 *  ---if either of inputs are negative, use subtract function
 *  ---if larger input is negative, print '-' and use subtract function
 *  ---else ret = 0, and we use add function
 *  ---move pointers so '-' char is ignored
 *  4. add function simply adds both inputs together from the back to the front...
 *  ...storing the answer into the string we malloced
 *  ...if the sum of two digits > 10, then we simply just reuse the tenth place...
 *  ...as we iterate into the next loop
 *  5. subtract function does same as add but with (minus equal) -= operator
 *  ...special in a way that if sum of two inputs < 10, we need to subtract 10...
 *  ...to make sure the tenth place loses 1 in the next iteration. 
*/ 
#define PRINT(x) write(1, x, ft_strlen(x))
#define MAX_TWO(a, b) ((a > b) ? a : b)
#define ABS(x) ((x < 0) ? -x : x)

int		ft_strlen(char *s)
{
	int len = 0;

	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

int		ft_strcmp(char *a, char *b)
{
	int i = 0;

	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return (a[i] - b[i]);
}

char	*init_str(char *a, char *b)
{
	int len = 1 + MAX_TWO(ft_strlen(a), ft_strlen(b));
	char *fresh;

	if (!(fresh = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	fresh[len] = '\0';
	return (fresh);
}

/*
 * Finds the longer of the two strings
*/
void	biggest_first(char **big, char **small)
{
	char *a = *big;
	char *b = *small;
	char *temp;

	if (*a == '-')
		a++;
	if (*b == '-')
		b++;
	if (ft_strlen(a) < ft_strlen(b) || (ft_strlen(a) == ft_strlen(b) && ft_strcmp(a, b) < 0))
	{
		temp = *big;
		*big = *small;
		*small = temp;
	}
}

int		check_negative(char **a, char **b)
{
	int ret = 0;

	// Sum will be positive, but will need to implement subtract fuction
	if ((**a == '-' && **b != '-') || (**a != '-' && **b == '-'))
		ret = 1;
	// Sum will be negative, so prints the minus sign
	if (**a == '-')
		write(1, "-", 1);

	//Moves the pointer to the first actual number so we can do calculation
	if (**a == '-')
		(*a)++;
	if (**b == '-')
		(*b)++;
	return (ret);
}

void	add(char *big, char *small, char *print)
{
	int b = ft_strlen(big) - 1;
	int s = ft_strlen(small) - 1;
	int i = ft_strlen(print);
	int carry = 0;

	while (b >= 0 || carry)
	{
		carry += big[b] - '0';
		if (s >= 0)
			carry += small[s] - '0';
		print[--i] = (carry % 10) + '0';
		b--;
		s--;
		carry /= 10;
	}
	PRINT(print + i);
}

void	subtract(char *big, char *small, char *print)
{
	int b = ft_strlen(big) - 1;
	int s = ft_strlen(small) - 1;
	int i = ft_strlen(print);
	int carry = 0;

	while (b >= 0 || carry)
	{
		carry += big[b] - '0';
		if (s >= 0)
			carry -= small[s] - '0';
		if (carry < 0)
		{
			carry -= 10;
			print[--i] = (10 - ABS(carry % 10)) + '0';
		}
		else
			print[--i] = ABS(carry % 10) + '0';
		carry /= 10;
		b--;
		s--;
	}
	PRINT(print + i);
}

int		main(int ac, char **av)
{
	char *print;
	if (ac == 3)
	{
		biggest_first(&av[1], &av[2]);
		print = init_str(av[1], av[2]);
		if (check_negative(&av[1], &av[2]))
			subtract(av[1], av[2], print);
		else
			add(av[1], av[2], print);
		free(print);
	}
	write(1, "\n", 1);
	return (0);
}
