/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 11:37:17 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/08 12:24:38 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <printf.h>

/*
 * First, take string and lowercase all characters
 * Then, count the # of alpha chars n store in int array
 * Notice that I have to recast char as int to do ^^
 * Traverse string again to print # of repeated alpha along with char
 * ascii 97 to 122 is all lowercase characters
*/

char	*ft_tolower(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
	return (s);
}

void	print_alpha_count(char *s)
{
	int temp[127] = { [0 ... 126] = 0 };
	int first;
	char *str;

	first = 1;
	str = s;
	while (*s)
	{
		temp[(int)*s]++;
		s++;
	}
	while (*str)
	{
		if (*str > 96 && *str < 123)
		{
			if (temp[(int)*str] > 0)
			{
				if (first)
				{
					printf("%d%c", temp[(int)*str], *str);
					first = 0;
				}
				else
					printf(", %d%c", temp[(int)*str], *str);
				temp[(int)*str] = 0;
			}
		}
		str++;
	}	
}

int		main(int ac, char **av)
{
	if (ac == 2)
		print_alpha_count(ft_tolower(av[1]));
	printf("\n");
	return (0);
}
