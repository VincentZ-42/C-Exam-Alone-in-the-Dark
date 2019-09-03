/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_diam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:15:01 by vzhao             #+#    #+#             */
/*   Updated: 2019/09/02 17:26:59 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define IS_NUM(x) ((x >= '0' && x <= '9') ? 1 : 0)

/* Functions I need:
 * ft_atoi---
 * ft_putnbr---
 * find_max_int---
 * populate_arr
 * recur
 * find_longest_chain
 *
 * 1. find the max number of string (used to create int **arr)
 * 2. malloc accordingly for arr and another arr called visited
 * -- Visited int arr will be used for tracking if we passed through node
 * -- Set each int in arr to 0 (each link will be used as a tunnel to next row)
 * 3. Next, you populate the arr by traversing the string and setting the ...
 * ... respective row and col equal to 1
 * 4. Next, we traverse each row and see where we can get longest chain...
 * ...recursively
 * 5. Longest chain is a static variable that we declare early on and ...
 * ... now we print out it after modifiying it in the longest chain function
 *
*/ 

int		ft_atoi(char *s)
{
	int ans = 0;

	while (*s && IS_NUM(*s))
	{
		 ans *= 10;
		 ans += *s - '0';
		 s++;
	}
	return (ans);
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	n = (n % 10) + '0';
	write(1, &n, 1);
}

int		find_max_int(char *s)
{
	int max = 0;
	int temp = 0;

	while (*s)
	{
		while (*s && !IS_NUM(*s))
			s++;
		if (IS_NUM(*s))
			temp = ft_atoi(s);
		max = (temp > max) ? temp : max;
		while (*s && IS_NUM(*s))
			s++;
	}
	return (max);
}

static int LONGEST_CHAIN;

void	populate_arr(int **arr, char *s)
{
	int a;
	int b;

	while (*s)
	{
		while (*s && !IS_NUM(*s))
			s++;
		a = ft_atoi(s);
		while (*s && IS_NUM(*s))
			s++;
		while (*s && !IS_NUM(*s))
			s++;
		b = ft_atoi(s);
		while (*s && IS_NUM(*s))
			s++;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
}

void	recur(int *visited, int **arr, int max, int row, int local_len)
{
	visited[row] = 1;
	int col = -1;
	while (++col <= max)
	{
		if (visited[col] == 0 && arr[row][col] != 0)
		{
			if (LONGEST_CHAIN <= local_len)
				LONGEST_CHAIN = local_len + 1;
			recur(visited, arr, max, col, local_len + 1);
		}
	}
	visited[row] = 0;	
}

void	find_longest_chain(int *visited, int **arr, int max)
{
	LONGEST_CHAIN = 2;
	int row = -1;

	while (++row <= max)
		recur(visited, arr, max, row, 1);
}

int		main(int ac, char **av)
{

	if (ac == 2)
	{
		int max = find_max_int(av[1]);
		int **arr = malloc(sizeof(int*) * max + 1);
		int *visited = malloc(sizeof(int) * max + 1);
		int i = -1;
		int j;
		while (++i < max + 1)
		{
			visited[i] = 0;
			arr[i] = malloc(sizeof(int) * max + 1);
			j = -1;
			while (++j < max + 1)
				arr[i][j] = 0;
		}

		populate_arr(arr, av[1]);
		find_longest_chain(visited, arr, max);
		ft_putnbr(LONGEST_CHAIN);
		free(arr);
		free(visited);
	}
	write(1, "\n", 1);
	return (0);
}
