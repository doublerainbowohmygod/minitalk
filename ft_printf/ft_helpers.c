/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:41:52 by aoneil            #+#    #+#             */
/*   Updated: 2025/12/06 01:55:26 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

size_t	ft_strlen_f(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	ft_putint_count(int n, int *count)
{
	if (n == INT_MIN)
	{
		ft_putstr_count("-2147483648", count);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_count('-', count);
		n = -n;
	}
	if (n > 9)
		ft_putint_count(n / 10, count);
	ft_putchar_count ((n % 10) + '0', count);
}

void	ft_putnbr_ull_count(unsigned long long n, int *count)
{
	if (n > 9)
		ft_putnbr_ull_count(n / 10, count);
	ft_putchar_count ((n % 10) + '0', count);
}

void	ft_putnbr_hex_count(unsigned long long n, const char *base, int *count)
{
	size_t	base_type;

	base_type = ft_strlen_f(base);
	if (n >= base_type)
		ft_putnbr_hex_count(n / base_type, base, count);
	ft_putchar_count(base[n % base_type], count);
}

void	ft_putptr_count(void *ptr, int *count)
{
	if (!ptr)
		ft_putstr_count("(nil)", count);
	else
	{
		ft_putstr_count("0x", count);
		ft_putnbr_hex_count((unsigned long long)ptr, "0123456789abcdef", count);
	}
}
