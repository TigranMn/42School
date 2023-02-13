/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmnatsak <tmnatsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:01:36 by tmnatsak          #+#    #+#             */
/*   Updated: 2023/02/05 15:16:36 by tmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(const char *s, ...);
int	ft_print_char(char c, int fd);
int	ft_print_str(char *s, int fd);
int	ft_print_nbr(int n, int fd);
int	ft_print_unbr(unsigned int n, int fd);
int	ft_print_hex(unsigned long long num, const char format, int fd);
int	ft_print_address(unsigned long long num, int fd);

#endif~