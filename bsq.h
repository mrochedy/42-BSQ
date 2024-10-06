/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:07:07 by hdaher            #+#    #+#             */
/*   Updated: 2024/10/06 12:21:21 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

//Includes

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

//Prototypes

//tools.c

int		ft_strlen(char *str);
int		find_first_line_break(char *line);
int		*get_map_size(char **map);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);

//map_tools.c

char	**free_map(char **map);
int		**free_int_map(int **map, int map_height);

//check_map.c

int		is_map_valid(char *line, char *map_chars);

//read_map.c

char	*read_map(char *file_path, int standard_input);

//ft_split.c

char	**ft_split(char *str, char *charset);

//fill_square_in_map.c

int		fill_square_in_map(char **map, char *map_chars, int *map_size);

//get_biggest_square.c

int		*get_biggest_square(int **map, int *map_size, int *sq_size);

//get_int_map.c

int		**get_int_map(char **map, char *map_chars, int *map_size);

//print_final_map.c

void	print_final_map(char **map);

#endif
