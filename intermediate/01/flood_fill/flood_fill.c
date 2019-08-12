/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 13:45:05 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/08 13:57:18 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void	f_fill(char **tab, t_point size, int y, int x, char target)
{
	if (tab[y][x] == 'F' || tab[y][x] != target)
		return;
	if (y < 0 || x < 0 || y >= size.y || x >= size.x)
		return;
	tab[y][x] = 'F';

	f_fill(tab, size, y, x - 1, target);
	f_fill(tab, size, y, x + 1, target);
	f_fill(tab, size, y - 1, x, target);
	f_fill(tab, size, y + 1, x, target);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char target;

	target = tab[begin.y - 1][begin.x - 1];
	f_fill(tab, size, begin.y - 1, begin.x - 1, target);
}
