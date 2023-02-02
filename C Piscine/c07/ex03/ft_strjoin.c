/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:32:45 by tmnatsak          #+#    #+#             */
/*   Updated: 2022/10/20 18:54:42 by tmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	print_sep(int s, char *sep, char *mystr)
{
	int	i;
	int	d;

	d = s;
	i = 0;
	while (sep[i] != '\0')
	{
		mystr[s] = sep[i];
		i++;
		s++;
	}
	return (s - d - 1);
}

int	get_final_len(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			len++;
			j++;
		}
		i++;
	}
	i = 0;
	while (sep[i] != '\0')
		i++;
	len += i * (size - 1);
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*mystr;
	int		len;
	int		i;
	int		j;
	int		s;

	i = -1;
	s = -1;
	len = get_final_len(size, strs, sep);
	if (size == 0)
		return ("");
	mystr = (char *)malloc(sizeof(char) * len + 1);
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j] != '\0')
			mystr[++s] = strs[i][j];
		if (++s != len)
			s += print_sep(s, sep, mystr);
	}
	mystr[s] = '\0';
	return (mystr);
}
