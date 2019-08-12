/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 10:09:17 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/10 12:30:48 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord_alphlong.h"

// Look at header file for instructions.....

int		ft_strlen(char *s)
{
	int i = -1;
	int len = 0;

	if (!s)
		return (0);
	while (s[++i])
		len++;
	return (len);
}

int		count_words(char *s)
{
	int count = 0;
	
	while (*s)
	{
		while (*s && IS_SPACE(*s))
			s++;
		if (*s && !IS_SPACE(*s))
		{
			count++;
			while (*s && !IS_SPACE(*s))
				s++;
		}
	}
	return (count);
}

char	*store_word(char *s)
{
	int i = 0;
	int len = 0;
	char *word;

	while (s[len] && !IS_SPACE(s[len]))
		len++;
	if (!(word = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s[i] && !IS_SPACE(s[i]))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**make_hope(char *s)
{
	int i = 0;
	int elem = 0;
	char **hope;

	if (!(hope = (char**)malloc(sizeof(char*) * count_words(s) + 1)))
		return (NULL);
	while (s[i] && IS_SPACE(s[i]))
		i++;
	while (s[i])
	{
		hope[elem++] = store_word(s + i);
		while (s[i] && !IS_SPACE(s[i]))
			i++;
		while (s[i] && IS_SPACE(s[i]))
			i++;
	}
	hope[elem] = NULL;
	return (hope);
}

int		compare_words(char *a, char *b)
{
	int i = 0;
	int a_len = ft_strlen(a);
	int b_len = ft_strlen(b);

	if (a_len != b_len)
		return (a_len - b_len);
	while (i < a_len && TO_LOWER(a[i]) == TO_LOWER(b[i]))
		i++;
	return (TO_LOWER(a[i]) - TO_LOWER(b[i]));
}

void	swap_words(char **a, char **b)
{
	char *temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_hope(char **hope)
{
	int i;
	int sorted = 1;

	while (sorted)
	{
		i = 0;
		sorted = 0;
		while (hope[++i])
		{
			if (compare_words(hope[i - 1], hope[i]) > 0)
			{
				swap_words(&hope[i - 1], &hope[i]);
				sorted = 1;
			}
		}
	}
}

void	give_hope(char **hope)
{
	int i = 0;
	int cur_len = ft_strlen(hope[i]);

	while (hope[i])
	{
		PRINT(hope[i]);
		if (cur_len == ft_strlen(hope[i + 1]))
			PRINT(" ");
		else if (cur_len < ft_strlen(hope[i + 1]))
		{
			cur_len = ft_strlen(hope[i + 1]);
			PRINT("\n");
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	char **hope;

	if (ac == 2)
	{
		hope = make_hope(av[1]);
		sort_hope(hope);
		give_hope(hope);
		free(hope);
	}
	PRINT("\n");
	return (0);
}
