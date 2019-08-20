/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_islands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:03:51 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/19 17:59:46 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/*
 * 1. Opens file if can
 * 2. creates a 2D array called map and fills map by...
 * ...reading the file into the array
 * ---special conditions: if \n go to next string
 *  --special conditions: if line_len is not all same, error
 *  --if char is not . or X, error
 * 3. If map is successfully filled, then use update_island funct
 * ---This function uses flood_fill to change the X to numbers
*/ 

int		fill_map(int fd, char map[1024][1024])
{
	char buf[1025] = {[0 ... 1024] = '\0'};
	int ret = 0;
	int row = 0;
	int col = -1;
	int line_len = 0;
	int i;

	while ((ret = read(fd, buf, 1024)) > 0)
	{
		buf[ret] = '\0';
		i = 0;
		while (buf[i] != '\0')
		{
			if (buf[i] == '\n')
			{
				if (line_len == 0)
					line_len = col;
				else if (line_len != col)
					return (0);
				map[row][++col] = '\0';
				row++;
				col = -1;
			}
			else if (buf[i] == '.' || buf[i] == 'X')
				map[row][++col] = buf[i];
			else
				return (0);
			i++;
		}
	}
	map[++row][0] = '\0';
	return (1);
}

void	flood_fill(char map[1024][1024], int row, int col, char fill)
{
	if (row < 0 || col < 0 || row > 1023 || col > 1023 \
			|| map[row][0] == '\0' || map[row][col] == '\0' \
			|| map[row][col] != 'X')
		return;
	
	map[row][col] = fill;
	flood_fill(map, row - 1, col, fill);
	flood_fill(map, row + 1, col, fill);
	flood_fill(map, row, col - 1, fill);
	flood_fill(map, row, col + 1, fill);
}

void	update_islands(char map[1024][1024])
{
	char fill_index = '0' - 1;
	int row = -1;
	int col;

	while (map[++row][0] != '\0')
	{
		col = -1;
		while (map[row][++col] != '\0')
		{
			if (map[row][col] == 'X')
				flood_fill(map, row, col, ++fill_index);
			write(1, &map[row][col], 1);
		}
		write(1, "\n", 1);
	}
}

int		main(int ac, char **av)
{
	int fd;
	char map[1024][1024];

	if (ac == 2 && (fd = open(av[1], O_RDONLY)) != -1)
	{
		if (fill_map(fd, map))
			update_islands(map);
		else
			write(1, "\n", 1);
		close(fd);
	}
	else
		write(1, "\n", 1);
	return (0);
}

