/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_subarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:47:54 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/12 18:42:20 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * 1. count the number of even and odd numbers
 * 2. set cur_len = 2x whichever is lower
 * 3. starting from index of 0, check if even and odd numbers...
 * ...balance each other out to 0, if not, move index foward...
 * ...until you reach max_len of input
 * 4. reset index to 0, and shorten cur_len by 1
 * 5. repeat 1-4 until find balance or no subarray balance
 *
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define IS_ODD(n) ((n % 2 == 1) ? 1 : 0)

char	*ft_strndup(char *str, int len)
{
	char *new = malloc(sizeof(char) * (len + 1));
	new[len] = '\0';

	int i = -1;
	while (++i < len)
		new[i] = str[i];
	return (new);
}

int		check_balance(char *str, int len)
{
	int balance = 0;
	int i = 0;
	while (i < len)
	{
		if (IS_ODD((int)str[i]))
			balance++;
		else
			balance--;
		i++;
	}
	return (balance);
}

int		min_odds_evens(char *str)
{
	int odds = 0;
	int evens = 0;

	while (*str)
	{
		if (IS_ODD(*str))
			odds++;
		else
			evens++;
		str++;
	}
	return (odds < evens ? odds : evens);
}

char	*longest_subarray(char *arr)
{
	int max_len = strlen(arr);
	int cur_len = 2 * min_odds_evens(arr);
	int start = 0;

	while (check_balance(arr + start, cur_len) != 0)
	{
		if (start + cur_len >= max_len)
		{
			start = 0;
			cur_len--;
		}
		else
			start++;
	}
	return(ft_strndup(arr + start, cur_len));
}

//-----------------------------------------------------
int	main(void)
{
	char str1[] = "1357913579024680213579";
	printf("79135790246802\n%s\n", longest_subarray(str1));

	char str2[] = "134";
	printf("\n34\n%s\n", longest_subarray(str2));

	char str3[] = "454";
	printf("\n45\n%s\n", longest_subarray(str3));

	char str4[] = "2010102";
	printf("\n0101\n%s\n", longest_subarray(str4));

	char str5[] = "2";
	printf("\n[blank]\n%s\n", longest_subarray(str5));

	char str6[] = "";
	printf("\n[blank]\n%s\n", longest_subarray(str6));

	//Moulinette test 6
	char str7[] = "222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222202222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222202222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222223222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222122222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222220222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222253222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222322222222222222222222222222222222222222222222222222222022222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222292222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222022222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222";
	printf("\n2253\n%s\n", longest_subarray(str7));
}