/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 18:27:26 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/19 17:44:24 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
//----------------
#include <stdio.h>

/*
 * 1. Check if any input = 0 or if negative
 * ---If so, then either 0, or whole output is - and movep pointers
 * 2. max len is the int_len of boht inputs + 1
 * 3. use max len to initialize output string
 * ---output string is filled with 0s because we don't know output #
 * 4. Run infin_mult function to fill output with calculation
 * ---calcuation goes like this
 *  --As iterate through one input, mutiple this digit with every digit...
 *  --...in the second input and add that into output from the back
 *  --offset is calculated from (len - current digit place - 1) of both digits
 * 5. input result is the function that handles the offseting of the calculation
 *  --Takes value and set carry = value % 10 + current value in output
 *  --Replaces output with new digit
 *  -- divides both value and carry by 10 and continue process
*/

int		ft_strlen(char *s)
{
	int len = 0;

	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*init_str(int len)
{
	char *fresh;
	int i = -1;

	if (!(fresh = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (++i < len)
		fresh[i] = '0';
	fresh[i] = '\0';
	return (fresh);
}

void	print_str(char *s, int len)
{
	int i = 0;
	while (i < len && s[i] == '0')
		i++;
	write(1, s + i, len - i);
}

void	check_negative(char **a, char **b)
{
	if ((**a == '-' && **b != '-') || (**a != '-' && **b == '-'))
		write(1, "-", 1);
	if (**a == '-')
		(*a)++;
	if (**b == '-')
		(*b)++;
}

void	input_result(int value, char *output, int i)
{
	int carry = 0;
	while (value > 0 || carry > 0)
	{
		i--;
		value += carry;
		carry = (value % 10) + (output[i] - '0');
		output[i] = (carry % 10) + '0';
		carry /= 10;
		value /= 10;
	}
}

void	infin_mult(char *a, char *b, char *output, int len)
{
	int len_a = ft_strlen(a);
	int len_b = ft_strlen(b);
	int ia = len_a;
	int ib;
	int offset;
	int result;

	while (--ia >= 0)
	{
		ib = len_b;
		while (--ib >= 0)
		{
			result = (a[ia] - '0') * (b[ib] - '0');
			offset = (len_a - ia - 1) + (len_b - ib - 1);
			input_result(result, output, len - offset);
		}
	}
}

int		main(int ac, char **av)
{
	char *a;
	char *b;
	int len;
	char *output;

	if (ac == 3)
	{
		a = av[1];
		b = av[2];
		if (*a == '0' || *b == '0')
		{
			write(1, "0\n", 2);
			return (0);
		}
		check_negative(&a, &b);
		len = 1 + ft_strlen(a) + ft_strlen(b);
		output = init_str(len);
		infin_mult(a, b, output, len);
		print_str(output, len);
		free(output);
	}
	write(1, "\n", 1);
	return (0);
}
