/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:17:26 by aoneil            #+#    #+#             */
/*   Updated: 2025/05/22 16:08:53 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	srclen = 0;
	dstlen = 0;
	i = 0;
	if (size > 0)
	{
		while (dstlen < size && dst[dstlen] != '\0')
			dstlen++;
		while (dstlen + i < size - 1 && src[srclen] != '\0')
		{
			dst[dstlen + i] = src[srclen];
			i++;
			srclen++;
		}
		if (dstlen + i < size)
			dst[dstlen + i] = '\0';
	}
	while (src[srclen] != '\0')
		srclen++;
	return (dstlen + srclen);
}
