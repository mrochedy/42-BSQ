/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:18:12 by hdaher            #+#    #+#             */
/*   Updated: 2024/04/03 18:26:16 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	is_in_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	word;
	int	count;

	i = 0;
	count = 0;
	word = 0;
	while (str[i])
	{
		if (!(is_in_sep(str[i], charset)) && word == 0)
		{
			count++;
			word = 1;
		}
		else if (is_in_sep(str[i], charset))
			word = 0;
		i++;
	}
	return (count);
}

void	insert_word(char *str, char *charset, char **tab, int word)
{
	int	i;

	i = 0;
	while (!(is_in_sep(str[i], charset)))
	{
		tab[word][i] = str[i];
		i++;
	}
	tab[word][i] = '\0';
}

int	insert_in_tab(char *str, char *charset, char **tab, int count)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (!(is_in_sep(str[i], charset)))
		{
			while (!is_in_sep(str[i + j], charset))
				j++;
			tab[count] = (char *)malloc((j + 1) * sizeof(char));
			if (tab[count] == NULL)
			{
				free_map(tab);
				return (1);
			}
			insert_word(str + i, charset, tab, count);
			i += j - 1;
			count++;
		}
		i++;
	}
	tab[count] = NULL;
	return (0);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		count;

	count = 0;
	tab = NULL;
	tab = (char **)malloc((count_words(str, charset) + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	if (insert_in_tab(str, charset, tab, count) == 0)
		return (tab);
	else
		return (NULL);
}
