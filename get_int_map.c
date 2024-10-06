/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:37:05 by mrochedy          #+#    #+#             */
/*   Updated: 2024/10/06 11:33:32 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**get_int_map(char **map, char *map_chars, int *map_size)
{
	int	**int_map;
	int	row;
	int	col;

	int_map = malloc(map_size[1] * sizeof(int *));
	if (int_map == NULL)
		return (NULL);
	row = 0;
	while (row < map_size[1])
	{
		col = 0;
		int_map[row] = malloc(map_size[0] * sizeof(int));
		if (int_map[row] == NULL)
			return (free_int_map(int_map, map_size[1]));
		while (col < map_size[0])
		{
			if (map[row][col] == map_chars[1])
				int_map[row][col++] = -1;
			else
				int_map[row][col++] = 0;
		}
		row++;
	}
	return (int_map);
}
