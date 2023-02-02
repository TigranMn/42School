/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:35:56 by tmnatsak          #+#    #+#             */
/*   Updated: 2023/01/21 15:35:59 by tmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	strlen;
	void	*ptr;

	strlen = ft_strlen(s1) + 1;
	ptr = (char *)malloc(strlen);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, strlen);
	return (ptr);
}
