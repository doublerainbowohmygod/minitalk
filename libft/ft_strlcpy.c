/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:18:31 by aoneil            #+#    #+#             */
/*   Updated: 2025/05/22 15:16:21 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;

	srclen = 0;
	if (size > 0)
	{
		while (srclen < size - 1 && src[srclen] != '\0')
		{
			dst[srclen] = src[srclen];
			srclen++;
		}
		dst[srclen] = '\0';
	}
	while (src[srclen] != '\0')
		srclen++;
	return (srclen);
}
