/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 08:53:34 by hdaher            #+#    #+#             */
/*   Updated: 2024/04/03 11:03:43 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = ft_strlen(dest);
	while (src[i] && i < nb)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = 0;
	return (dest);
}

char	*ft_realloc(char *str, int size)
{
	char	*new_str;
	int		str_size;

	if (str == NULL)
		str_size = 0;
	else
		str_size = ft_strlen(str);
	new_str = malloc(((str_size + size + 1) * sizeof(char)));
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
	new_str[0] = '\0';
	ft_strncat(new_str, str, str_size);
	free(str);
	return (new_str);
}

int	init_variables(char **map_string, char **buff)
{
	*map_string = malloc(sizeof(char));
	if (!*map_string)
		return (0);
	*map_string[0] = '\0';
	*buff = malloc(sizeof(char) * 1025);
	if (!*buff)
	{
		free(*map_string);
		return (0);
	}
	return (1);
}

int	make_the_reading(int fd, char *buff, char **map_string)
{
	int	ret;

	ret = read(fd, buff, 1024);
	while (ret > 0)
	{
		buff[ret] = '\0';
		*map_string = ft_realloc(*map_string, ret);
		if (!*map_string)
		{
			free(buff);
			return (0);
		}
		ft_strncat(*map_string, buff, ret);
		ret = read(fd, buff, 1024);
	}
	return (1);
}

char	*read_map(char *file_path, int standard_input)
{
	int		fd;
	char	*buff;
	char	*map_string;

	if (!init_variables(&map_string, &buff))
		return (NULL);
	fd = 0;
	if (standard_input != 0)
		fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		free(map_string);
		free(buff);
		return (NULL);
	}
	if (!make_the_reading(fd, buff, &map_string))
		return (NULL);
	close(fd);
	free(buff);
	return (map_string);
}

/*int	main(void)
{
	char	*str;

	str = read_map("./example_file", 1);
	printf("%s\n", str);
	free(str);
}*/
