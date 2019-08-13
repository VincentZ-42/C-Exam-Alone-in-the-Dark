/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volume_histogram.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:49:07 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/12 19:17:57 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * The volume of water is measured by taking the lowest of right or left sides...
 * ...and subtracting by the histogram's height. 
 * First condition: if current level is lower then either side, do calculation
 * Second condition: If left side is greater than current bound, set new left bound...
 * ..or if we hit the right side bound, set new bound for left and right
 * This while loop repeats until we reach the end of the histogram
 * 
 *
*/

int		volume_histogram(int *histogram, int size)
{
	int left_h = 0;
	int right_h = 0;
	int i = -1;
	int j;
	int ret = 0;

	while (++i < size)
	{
		if (histogram[i] < left_h && histogram[i] < right_h)
			ret += (left_h > right_h ? right_h : left_h) - histogram[i];
		if (histogram[i] > left_h || histogram[i] == right_h)
		{
			left_h = histogram[i];
			right_h = 0;
			j = i;
			while (++j < size)
				right_h = (histogram[j] > right_h ? histogram[j] : right_h);
		}
	}
	return (ret);
}

//----------------------------------------------------------------
#include <stdio.h>
int	main(void)
{
 	int	histogram1[] = {2, 1, 2};
 	int	size1 = sizeof(histogram1) / sizeof(*histogram1);
 	printf("Should be 1: %d\n", volume_histogram(histogram1, size1));

 	int	histogram2[] = {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0};
	int	size2 = sizeof(histogram2) / sizeof(*histogram2);
 	printf("Should be 26: %d\n", volume_histogram(histogram2, size2));

	int histogram3[] = {1, 0, 2, 0, 2};
	int	size3 = sizeof(histogram3) / sizeof(*histogram3);
 	printf("Should be 3: %d\n", volume_histogram(histogram3, size3));

}
