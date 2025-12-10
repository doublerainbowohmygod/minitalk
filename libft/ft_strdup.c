/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 21:17:59 by aoneil            #+#    #+#             */
/*   Updated: 2025/05/23 21:52:53 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ns;
	size_t	len;

	len = ft_strlen(s) + 1;
	ns = ft_calloc(len, sizeof(char));
	if (ns)
		ft_strlcpy(ns, s, len);
	return (ns);
}

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h" // Здесь должен быть прототип ft_strdup

int main(void)
{
    const char *src = "Hello, libft!";
    char *dup = ft_strdup(src);

    if (!dup)
    {
        printf("ft_strdup returned NULL\n");
        return 1;
    }

    printf("Original: \"%s\"\n", src);
    printf("Duplicate: \"%s\"\n", dup);

    // Проверка побайтного совпадения
    if (strcmp(src, dup) == 0)
        printf("Strings are equal: OK\n");
    else
        printf("Strings are NOT equal: ERROR\n");

    // Проверка завершающего нуля
    if (dup[strlen(src)] == '\0')
        printf("Null-terminator: OK\n");
    else
        printf("Null-terminator: ERROR\n");

    free(dup);

    // Проверка с пустой строкой
    dup = ft_strdup("");
    if (dup && dup[0] == '\0')
        printf("Empty string: OK\n");
    else
        printf("Empty string: ERROR\n");
    free(dup);

    // Проверка с длинной строкой
    char big[1001];
    memset(big, 'A', 1000);
    big[1000] = '\0';
    dup = ft_strdup(big);
    if (dup && strcmp(big, dup) == 0)
        printf("Long string: OK\n");
    else
        printf("Long string: ERROR\n");
    free(dup);

    return 0;
}
*/