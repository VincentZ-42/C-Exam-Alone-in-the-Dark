/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 10:10:54 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/10 12:30:36 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORD_ALPHLONG_H
# define ORD_ALPHLONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //for troubleshooting, don't really need

# define PRINT(x) write(1, x, ft_strlen(x))
# define IS_SPACE(c) ((c == ' ' || c == '\t') ? 1 : 0)
# define TO_LOWER(c) ((c >= 'A' && c <= 'Z') ? c + 32 : c)

int		ft_strlen(char *s);
int		count_words(char *s);
char	*store_word(char *s);
char	**make_hope(char *s);
int		compare_words(char *a, char *b);
void	swap_words(char **a, char **b);
void	sort_hope(char **hope);
void	give_hope(char **hope);

/*
 * First, make array of strings same way as str_split
 * Then, sort the array with short len first, then alphabettical order
 * Then, print the array, with special conditions
 * if length of string is same as last, print space
 * if length of string is bigger, print newline and set as new length
*/ 

#endif
