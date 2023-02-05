/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmnatsak <tmnatsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:06:19 by tmnatsak          #+#    #+#             */
/*   Updated: 2023/02/05 14:42:11 by tmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long	get_int_len(unsigned int n)
{
	unsigned long	i;

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

int	ft_print_nbr(int n, int fd)
{
	long int		num;
	unsigned long	int_len;
	int				len;

	len = 0;
	num = n;
	if (num < 0)
	{
		ft_print_char('-', fd);
		num *= -1;
		len++;
	}
	int_len = get_int_len(num);
	while (int_len)
	{	
		ft_print_char((num / int_len) % 10 + '0', fd);
		int_len /= 10;
		len++;
	}
	return (len);
}

int	ft_print_unbr(unsigned int n, int fd)
{
	unsigned long	int_len;
	int				len;

	len = 0;
	int_len = get_int_len(n);
	while (int_len)
	{	
		ft_print_char((n / int_len) % 10 + '0', fd);
		int_len /= 10;
		len++;
	}
	return (len);
}
