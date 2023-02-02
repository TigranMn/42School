/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:51:25 by tmnatsak          #+#    #+#             */
/*   Updated: 2023/01/21 15:51:26 by tmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	sub_len;
	char	*sub;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	sub_len = 0;
	if (start < slen)
		sub_len = slen - start;
	else
		return (ft_strdup(""));
	if (sub_len > len)
		sub_len = len;
	sub = (char *)malloc(sizeof(char) * sub_len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, (s + start), (sub_len + 1));
	return (sub);
}
