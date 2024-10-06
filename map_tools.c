/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:11:13 by mrochedy          #+#    #+#             */
/*   Updated: 2024/04/03 12:18:18 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**free_int_map(int **int_map, int map_height)
{
	int	row;

	row = 0;
	while (row < map_height)
		if (int_map[row])
			free(int_map[row++]);
	free(int_map);
	return (NULL);
}

char	**free_map(char **map)
{
	int	row;

	row = 0;
	while (map[row])
		free(map[row++]);
	free(map);
	return (NULL);
}
