/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:37:19 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/10 16:39:33 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//1. find string of len 1 that matches all strings
//2. set ret_start n ret_len to len
//3. inc len by 1
//4. Repeat steps 1-3 until you traverse all of av[1]
//5. output string found in all arguments

int		check_match(char *s1, char *s2, int len)
{
	int i = -1;
	int j;

	while (s2[++i])
	{
		j = -1;
		while (++j < len)
		{
			if (s1[j] != s2[j + i])
				break;
			else if (j == len - 1)
				return (1);
		}
	}
	return (0);
}

int		main(int ac, char **av)
{
	int i;
	int start;
	int ret_start = 0;
	int ret_len = 0;
	int len;

	if (ac > 1)
	{
		start = -1;
		while (av[1][++start])
		{
			len = 1;
			while (av[1][start + len - 1])
			{
				i = 1;
				while (++i < ac)
					if (!check_match(av[1] + start, av[i], len))
						break;
				if (i != ac)
				   break;	
				len++;
			}
			if (len - 1 > ret_len)
			{
				ret_len = len - 1;
				ret_start = start;
			}
		}
		write(1, av[1] + ret_start, ret_len);
	}
	write(1, "\n", 1);
	return (0);
}
