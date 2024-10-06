/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_biggest_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:20:59 by mrochedy          #+#    #+#             */
/*   Updated: 2024/10/06 11:33:20 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	else
		return (c);
}

int	*get_t_l_coord(int **map, int *map_size, int *b_r_coord)
{
	int	row;
	int	col;
	int	*t_l_coord;

	row = 0;
	while (row < map_size[1])
	{
		col = 0;
		while (col < map_size[0])
		{
			if (map[row][col] > map[b_r_coord[0]][b_r_coord[1]])
			{
				b_r_coord[0] = row;
				b_r_coord[1] = col;
			}
			col++;
		}
		row++;
	}
	t_l_coord = malloc(2 * sizeof(int));
	if (t_l_coord == NULL)
		return (NULL);
	t_l_coord[0] = b_r_coord[0] - map[b_r_coord[0]][b_r_coord[1]];
	t_l_coord[1] = b_r_coord[1] - map[b_r_coord[0]][b_r_coord[1]];
	return (t_l_coord);
}

int	*get_biggest_square(int **map, int *map_size, int *sq_size)
{
	int	row;
	int	col;
	int	b_r_coord[2];
	int	*t_l_coord;

	row = 1;
	while (row < map_size[1])
	{
		col = 1;
		while (col < map_size[0])
		{
			if (map[row][col] != -1)
				map[row][col] = min(map[row - 1][col],
						map[row][col - 1], map[row - 1][col - 1]) + 1;
			col++;
		}
		row++;
	}
	b_r_coord[0] = 0;
	b_r_coord[1] = 0;
	t_l_coord = get_t_l_coord(map, map_size, b_r_coord);
	if (t_l_coord == NULL)
		return (NULL);
	*sq_size = map[b_r_coord[0]][b_r_coord[1]] + 1;
	return (t_l_coord);
}
