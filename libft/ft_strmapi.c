/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:27:00 by tmnatsak          #+#    #+#             */
/*   Updated: 2023/01/22 16:27:02 by tmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*res;
	int					s_len;
	unsigned int		i;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * s_len + 1);
	if (!res)
		return (NULL);
	while (s_len--)
	{		
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
