/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:24:46 by hdaher            #+#    #+#             */
/*   Updated: 2024/10/06 12:21:54 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**get_map(char *file_path, char **map, char *map_chars, int std_in)
{
	char	*map_string;

	map_string = read_map(file_path, std_in);
	if (!map_string)
	{
		ft_putstr_fd("map error\n", 2);
		return (NULL);
	}
	if (!(is_map_valid(map_string, map_chars)))
	{
		ft_putstr_fd("map error\n", 2);
		free(map_string);
		return (NULL);
	}
	map = ft_split(map_string + find_first_line_break(map_string), "\n");
	free(map_string);
	return (map);
}

void	free_everything(char **map, char *map_chars, int *map_size)
{
	free_map(map);
	if (map_chars)
		free(map_chars);
	if (map_size)
		free(map_size);
}

int	error_case(char **map, char *map_chars, int *map_size)
{
	ft_putstr_fd("map error\n", 2);
	free_everything(map, map_chars, map_size);
	return (1);
}

int	treat_map(char **map, char *map_chars, int **map_size)
{
	if (map)
	{
		*map_size = get_map_size(map);
		if (!*map_size)
			return (error_case(map, map_chars, *map_size));
		if (!fill_square_in_map(map, map_chars, *map_size))
			return (error_case(map, map_chars, *map_size));
		print_final_map(map);
		free_everything(map, map_chars, *map_size);
	}
	else
		free(map_chars);
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	int		*map_size;
	char	**map;
	char	*map_chars;

	i = !(ac == 1);
	while (i < ac)
	{
		map_chars = malloc(4 * sizeof(char));
		if (!map_chars)
			return (error_case(map, map_chars, map_size));
		map = get_map(av[i], map, map_chars, ac - 1);
		if (treat_map(map, map_chars, &map_size))
			return (1);
		if (i++ < ac - 1)
			ft_putchar_fd('\n', 1);
	}
	return (0);
}
