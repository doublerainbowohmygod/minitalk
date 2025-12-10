/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 21:35:38 by aoneil            #+#    #+#             */
/*   Updated: 2025/05/31 22:32:58 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*
#include <stdio.h>
#include "libft.h"

void	ft_to_n_upper(unsigned int n, char *c)
{
	(void)n;
	unsigned char	ch;

	ch = *c;
	if (ch >= 'a' && ch <= 'z')
		*c = ch - 32;
	return;
}

int main()
{
	char s[] = "hi, is anyone there?";
	printf ("%s\n", s);
	ft_striteri (s, &ft_to_n_upper);
	printf ("%s\n", s);
	return 0;
} 
*/