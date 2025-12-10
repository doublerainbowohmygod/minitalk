/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:42:31 by aoneil            #+#    #+#             */
/*   Updated: 2025/05/28 17:46:01 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	srclen;
	size_t	startsizet;

	if (!s)
		return (NULL);
	startsizet = (size_t)start;
	srclen = ft_strlen(s);
	if (startsizet >= srclen)
	{
		substr = (char *)malloc(1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
	}
	else
	{
		if (len > srclen - startsizet)
			len = srclen - startsizet;
		substr = (char *)malloc((len + 1) * sizeof(char));
		if (!substr)
			return (NULL);
		ft_strlcpy(substr, s + startsizet, len + 1);
	}
	return (substr);
}

/*
#include <stdio.h>

int main(void)
{
    const char    *src = "v";
    unsigned int    start = 0;
    size_t          len = 0;

    char *res = ft_substr(src, start, len);
    printf ("this: %s\n",res);

    return(0);
}
*/