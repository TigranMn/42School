/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:46:53 by tmnatsak          #+#    #+#             */
/*   Updated: 2023/01/22 16:46:55 by tmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int					s_len;
	unsigned int		i;

	if (!s)
		return ;
	i = 0;
	s_len = ft_strlen(s);
	while (s_len--)
	{		
		f(i, &s[i]);
		i++;
	}
}
