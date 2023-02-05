/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmnatsak <tmnatsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:03:27 by tmnatsak          #+#    #+#             */
/*   Updated: 2023/02/05 15:23:08 by tmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_print_str(char *s, int fd)
{
	int	s_len;

	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	s_len = ft_strlen(s);
	write(fd, s, s_len);
	return (s_len);
}

int	ft_print_address(unsigned long long num, int fd)
{
	write (fd, "0x\n", 2);
	return (ft_print_hex(num, 'x', fd) + 2);
}
