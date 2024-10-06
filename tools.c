/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:07:55 by hdaher            #+#    #+#             */
/*   Updated: 2024/10/06 12:22:42 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	find_first_line_break(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
		i++;
	return (i);
}

int	*get_map_size(char **map)
{
	int	i;
	int	j;
	int	*map_size;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	while (map[i - 1][j])
		j++;
	map_size = malloc(sizeof(int) * 2);
	if (!map_size)
		return (0);
	map_size[0] = j;
	map_size[1] = i;
	return (map_size);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar_fd(str[i++], fd);
}
