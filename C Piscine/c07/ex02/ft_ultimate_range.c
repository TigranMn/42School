/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:33:48 by tmnatsak          #+#    #+#             */
/*   Updated: 2022/10/19 15:33:49 by tmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*buffer;

	i = 0;
	if (min >= max)
	{
		range = (int **)0;
		return (0);
	}
	buffer = (int *)malloc(sizeof(int) * (max - min));
	if (!buffer)
		return (-1);
	*range = buffer;
	while (i < max - min)
	{
		buffer[i] = min + i;
		i++;
	}
	return (max - min);
}
