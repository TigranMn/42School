/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:21:44 by tmnatsak          #+#    #+#             */
/*   Updated: 2023/01/21 13:21:45 by tmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last = NULL;
	size_t		s_size;

	s_size = ft_strlen(s) + 1;
	while (s_size--)
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	return ((char *)last);
}
