/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 19:59:55 by aoneil            #+#    #+#             */
/*   Updated: 2025/05/31 21:39:29 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s2;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
		i++;
	s2 = malloc(i + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		s2[i] = f(i, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/*
#include <stdio.h>
#include "libft.h"

char	ft_to_n_upper(unsigned int n, char c)
{
	(void)n; 
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}


int main()

{
	char *s = "Hi, is anyone there?";
	char *s2;
	printf ("%s", s);

	s2 = ft_strmapi (s, &ft_to_n_upper);
	printf ("%s", s2);
	return 0;
} 
*/