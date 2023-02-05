/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmnatsak <tmnatsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:01:57 by tmnatsak          #+#    #+#             */
/*   Updated: 2023/02/05 16:51:58 by tmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_specifier(char c, va_list argp)
{
	if (c == 'c')
		return (ft_print_char(va_arg(argp, int), 1));
	if (c == 's')
		return (ft_print_str(va_arg(argp, char *), 1));
	if (c == '%')
		return (ft_print_char('%', 1));
	if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(argp, int), 1));
	if (c == 'u')
		return (ft_print_unbr(va_arg(argp, unsigned int), 1));
	if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(argp, unsigned int), c, 1));
	if (c == 'p')
		return (ft_print_address(va_arg(argp, unsigned long long), 1));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		len;
	int		i;
	va_list	argp;

	va_start(argp, s);
	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1])
		{
			len += handle_specifier(s[i + 1], argp);
			i += 2;
			continue ;
		}
		if (s[i] != '%')
			write(1, &s[i], 1);
		i++;
		len++;
	}
	va_end(argp);
	return (len);
}
