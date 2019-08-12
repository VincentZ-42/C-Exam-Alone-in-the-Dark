/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_anagram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 10:05:54 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/08 11:35:59 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	Make a zerod int array and then add on to the int array as you traverse 1st string
 *	Traversing 2nd string should minus all the add-ons if it is an anagram
 *	After traversing both strings, all values in int array should be 0
 *	We are only concerned with values between 32 n 126 (printable ascii chars)
*/

int		is_anagram(char *a, char *b)
{
	int temp[127] = { [0 ... 126] = 0 };
	int i = 31;

	while (*a)
	{
		temp[(int)*a]++;
		a++;
	}
	while (*b)
	{
		temp[(int)*b]--;
		b++;
	}
	while (++i < 127)
		if (temp[i] != 0)
			return (0);
	return (1);
}

// Do not submit main
#include <stdio.h>
int		main(void)
{
	char *a = "abca";
	char *b = "bcab";

	printf("is_anagram = %d\n", is_anagram(a, b));
	return (0);
}
