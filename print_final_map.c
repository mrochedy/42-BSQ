/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_final_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:06:50 by mrochedy          #+#    #+#             */
/*   Updated: 2024/10/06 12:22:18 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_final_map(char **map)
{
	int	row;

	row = 0;
	while (map[row])
	{
		ft_putstr_fd(map[row], 1);
		ft_putchar_fd('\n', 1);
		row++;
	}
}
