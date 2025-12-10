/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:32:46 by aoneil            #+#    #+#             */
/*   Updated: 2025/06/01 19:07:54 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include "libft.h"

size_t	ft_nlen(int n);
char	*ft_putnbr2s(char *s, long lnb, size_t *i);

size_t	ft_nlen(int n)
{
	int		tmp;
	size_t	nlen;

	tmp = n;
	nlen = 1;
	if (tmp < 0)
	{
		tmp = -tmp;
		nlen++;
	}
	while (tmp / 10 > 0)
	{
		tmp /= 10;
		nlen++;
	}
	return (nlen);
}

char	*ft_putnbr2s(char *s, long lnb, size_t *i)
{
	if (lnb < 0)
	{
		s[(*i)] = '-';
		(*i)++;
		lnb *= -1;
	}
	if (lnb >= 10)
		ft_putnbr2s(s, lnb / 10, i);
	s[(*i)] = (char)((lnb % 10) + '0');
	(*i)++;
	s[(*i)] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	len;
	size_t	i;

	i = 0;
	if (n == -2147483648)
	{
		s = malloc(11 + 1);
		if (!s)
			return (NULL);
		ft_strlcpy(s, "-2147483648", 12);
		return (s);
	}
	len = ft_nlen(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	ft_putnbr2s(s, n, &i);
	return (s);
}

/*
#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int n);

int main(void)
{
    int n = 0;
    char *result = ft_itoa(n);
	printf("Number:%d\n",n);

    if (!result)
    {
        printf("Split failed!\n");
        return 1;
    }
	printf("main GOT result!\n");
	printf("RESULT: %s", result);

    free(result);
    return 0;
}
*/