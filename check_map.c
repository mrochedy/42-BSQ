/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:42:39 by hdaher            #+#    #+#             */
/*   Updated: 2024/10/06 12:18:01 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_first_line(char *line, char *map_chars)
{
	int	i;
	int	first_len;
	int	lines_count;

	i = 0;
	first_len = 0;
	lines_count = 0;
	while (line[first_len] != '\n')
		first_len++;
	if ((first_len < 4 || line[first_len - 1] == line[first_len - 2]
			|| line[first_len - 1] == line[first_len - 3]
			|| line[first_len - 2] == line[first_len - 3]))
		return (0);
	while (i < first_len - 3)
	{
		lines_count = lines_count * 10 + (line[i] - '0');
		if (line[i] < '0' || line[i++] > '9')
			return (0);
	}
	map_chars[0] = line[first_len - 3];
	map_chars[1] = line[first_len - 2];
	map_chars[2] = line[first_len - 1];
	map_chars[3] = '\0';
	return (lines_count);
}

int	is_map_chars(char *line, char *map_chars)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
		i++;
	while (line[i])
	{
		if (line[i] != '\n'
			&& (line[i] != map_chars[0] && line[i] != map_chars[1]))
			return (0);
		i++;
	}
	return (1);
}

int	get_first_line_length(char *line)
{
	int	i;
	int	first_line_length;

	i = 0;
	first_line_length = 0;
	while (line[i] && line[i] != '\n')
		i++;
	i++;
	while (line[i + first_line_length] && line[i + first_line_length] != '\n')
		first_line_length++;
	return (first_line_length + 1);
}

int	check_lines(char *line, int line_count)
{
	int	i;
	int	newline_count;
	int	j;
	int	first_line_length;

	i = 1;
	j = 1;
	newline_count = 0;
	first_line_length = get_first_line_length(line);
	while (line[i - 1] != '\n')
		i++;
	while (line[i])
	{
		if (line[i++] == '\n')
		{
			if (first_line_length != j)
				return (0);
			newline_count++;
			j = 0;
		}
		j++;
	}
	if (newline_count != line_count || line[i - 1] != '\n')
		return (0);
	return (1);
}

int	is_map_valid(char *line, char *map_chars)
{
	int	lines_count;

	if (!line[0])
		return (0);
	lines_count = check_first_line(line, map_chars);
	if (lines_count == 0)
		return (0);
	if (check_lines(line, lines_count) == 0)
		return (0);
	if (is_map_chars(line, map_chars) == 0)
		return (0);
	return (1);
}
