/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square_in_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:39:14 by mrochedy          #+#    #+#             */
/*   Updated: 2024/10/06 11:33:09 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	fill_square_in_map(char **map, char *map_chars, int *map_size)
{
	int	**int_map;
	int	*t_l_coord;
	int	sq_size;
	int	row;
	int	col;

	int_map = get_int_map(map, map_chars, map_size);
	if (int_map == NULL)
		return (0);
	sq_size = 0;
	t_l_coord = get_biggest_square(int_map, map_size, &sq_size);
	free_int_map(int_map, map_size[1]);
	if (t_l_coord == NULL)
		return (0);
	row = t_l_coord[0];
	while (row++ < t_l_coord[0] + sq_size)
	{
		col = t_l_coord[1];
		while (col++ < t_l_coord[1] + sq_size)
			map[row - 1][col - 1] = map_chars[2];
	}
	free(t_l_coord);
	return (1);
}
