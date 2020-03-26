/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 09:30:27 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/08 11:35:54 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* right = sum of all values after 1st value in array
 * left = first value
 * As we move the pivot point, we subtract from the right sum to...
 * ...see if left sum matches
*/

int		find_pivot(int *arr, int n)
{
	int left;
	int right;
	int i;

	left = 0;
	right = 0;
	i = -1;
	while (++i < n)
		right += arr[i];
	i = -1;
	while (++i < n)
	{
		if (i > 0)
			left += arr[i - 1];
		right -= arr[i];
		if (left == right)
			return (i);
	}
	return (-1);
}

// Do not include main function
#include <stdio.h>
void	print_arr_pivot(int *arr, int n, int pivot)
{
	int i = -1;

	printf("arr = [");
	while (++i < n)
		printf(" %d ", arr[i]);
	printf("]\n");
	printf("pivot = %d\n\n", pivot);
}

int		main(void)
{
	int arra[6] = {1, 2, 3, 4, 0, 6};
	print_arr_pivot(arra, 6, find_pivot(arra, 6));
	
	int arrb[] = { 5, 0 };	
	print_arr_pivot(arrb, 2, find_pivot(arrb, 2));

	int arrc[] = { 1, 100, 0, 0, 1 };
	print_arr_pivot(arrc, 5, find_pivot(arrc, 5));

	int arrd[] = { -5, 10, 2, 5 };
	print_arr_pivot(arrd, 4, find_pivot(arrd, 4));	
	
	int arrf[] = { 7, 9, 8 };
	print_arr_pivot(arrf, 3, find_pivot(arrf, 3));

	int arrg[] = { 1, 2 };
	print_arr_pivot(arrg, 2, find_pivot(arrg, 2));

	int arrz[] = { 0, 0, 0, 0, 1, 0, 0, 0, 0 };
	print_arr_pivot(arrz, 9, find_pivot(arrz, 9));

	int arrh[1000001] = { [0 ... 100000] = 5 };
	int nh = 1000001;
	print_arr_pivot(arrh, nh, find_pivot(arrh, nh));
	
	return (0);
}
