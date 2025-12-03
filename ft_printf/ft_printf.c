/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:50:53 by aoneil            #+#    #+#             */
/*   Updated: 2025/07/28 20:45:45 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

void	ft_putchar_count(char c, int *count)
{
	write(1, &c, 1);
	if (count)
		(*count)++;
}

void	ft_putstr_count(char *s, int *count)
{
	if (!s)
	{
		ft_putstr_count("(null)", count);
		return ;
	}
	while (*s)
		ft_putchar_count(*s++, count);
}

int	find_char_in(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

void	do_param(const char *str, va_list ap, int *count)
{
	if (*str == '%')
		ft_putchar_count ('%', count);
	else if (*str == 'c')
		ft_putchar_count (va_arg(ap, int), count);
	else if (*str == 's')
		ft_putstr_count (va_arg(ap, char *), count);
	else if (*str == 'd' || *str == 'i')
		ft_putint_count(va_arg(ap, int), count);
	else if (*str == 'u')
		ft_putnbr_ull_count ((unsigned long long)va_arg(ap, unsigned int),
			count);
	else if (*str == 'x')
		ft_putnbr_hex_count ((unsigned long long)va_arg(ap, unsigned int),
			"0123456789abcdef", count);
	else if (*str == 'X')
		ft_putnbr_hex_count ((unsigned long long)va_arg(ap, unsigned int),
			"0123456789ABCDEF", count);
	else if (*str == 'p')
		ft_putptr_count(va_arg(ap, void *), count);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			count;

	if (!str)
		return (-1);
	va_start(ap, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (find_char_in("cspdiuxX%",*str))
				do_param(str, ap, &count);
			else
				ft_putchar_count('%', &count);
			str++;
		}
		else
		{
			ft_putchar_count(*str++, &count);
		}
	}
	va_end(ap);
	return (count);
}
