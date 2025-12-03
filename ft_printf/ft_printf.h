/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:40:22 by aoneil            #+#    #+#             */
/*   Updated: 2025/12/03 12:57:22 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdarg.h>

int		find_char_in(const char *s, int c);
void	ft_putchar_count(char c, int *count);
void	ft_putstr_count(char *s, int *count);
size_t	ft_strlen_f(const char *s);
void	ft_putint_count(int n, int *count);
void	ft_putnbr_ull_count(unsigned long long n, int *count);
void	ft_putnbr_hex_count(unsigned long long n, const char *base, int *count);
void	ft_putptr_count(void *ptr, int *count);
void	do_param(const char *str, va_list ap, int *count);
int		ft_printf(const char *str, ...);

#endif
