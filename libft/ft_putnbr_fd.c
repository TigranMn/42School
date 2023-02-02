/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:24:30 by tmnatsak          #+#    #+#             */
/*   Updated: 2023/01/22 17:24:31 by tmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	get_int_len(int n)
{
	long int	i;

	if (n == 0)
		return (1);
	i = 1;
	while (n)
	{
		n /= 10;
		i *= 10;
	}
	return (i / 10);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	num;
	long int	int_len;

	num = n;
	int_len = get_int_len(num);
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	while (int_len)
	{	
		ft_putchar_fd((num / int_len) % 10 + '0', fd);
		int_len /= 10;
	}
}
