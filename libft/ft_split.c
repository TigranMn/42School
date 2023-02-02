/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:36:13 by tmnatsak          #+#    #+#             */
/*   Updated: 2023/01/29 16:36:59 by tmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	ft_free(char **split, int i)
{
	while (i--)
		free(split[i]);
	free(split);
}

static int	ft_strlen_word(const char *str, char delimiter)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != delimiter)
		i++;
	return (i);
}

static int	count_words(const char *str, char delimiter)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == delimiter)
			i++;
		if (str[i])
			count++;
		while (str[i] && (str[i]) != delimiter)
			i++;
	}
	return (count);
}

static char	**get_strings(char **strings, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] && (s[j] == c))
			j++;
		if (s[j])
		{
			strings[i] = ft_substr(s, j, ft_strlen_word((s + j), c));
			if (!strings[i])
			{
				ft_free(strings, i);
				return (NULL);
			}
			i++;
		}
		while (s[j] && s[j] != c)
			j++;
	}
	strings[i] = 0;
	return (strings);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;

	if (!s)
		return (NULL);
	strings = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!strings)
		return (NULL);
	strings = get_strings(strings, s, c);
	if (!strings)
		return (NULL);
	return (strings);
}
