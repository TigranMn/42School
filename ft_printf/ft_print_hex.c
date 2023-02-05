/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmnatsak <tmnatsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:07:59 by tmnatsak          #+#    #+#             */
/*   Updated: 2023/02/05 14:42:01 by tmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned	long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_put_hex(unsigned long long num, const char format)
{
	int	len;

	len = 0;
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_print_char((num + '0'), 1);
		else
		{
			if (format == 'x')
			{
				ft_print_char((num - 10 + 'a'), 1);
				len++;
			}
			if (format == 'X')
				ft_print_char((num - 10 + 'A'), 1);
				len++;
		}
	}
}

int	ft_print_hex(unsigned long long num, const char format, int fd)
{
	if (num == 0)
		return (write(fd, "0", 1));
	else
		ft_put_hex(num, format);
	return (ft_hex_len(num));
}
