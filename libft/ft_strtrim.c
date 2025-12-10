/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 23:43:30 by aoneil            #+#    #+#             */
/*   Updated: 2025/05/26 15:15:24 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_charfromset(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_charfromset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_charfromset(s1[end - 1], set))
		end--;
	if (start >= end)
	{
		trimmed = malloc(1);
		if (!trimmed)
			return (NULL);
		trimmed[0] = '\0';
		return (trimmed);
	}
	trimmed = ft_substr(s1, start, end - start);
	return (trimmed);
}

/*
#include <stdio.h>
int	main(void)
{
	char const	*str = " oh my god it's youu!";
	char const	*set = " ";
	printf("%s\n", ft_strtrim(str, set));

	char const	*str1 = "";
	char const	*set1 = " ";
	printf("%s\n", ft_strtrim(str1, set1));

	char const	*str2 = " oh my god it's youu!";
	char const	*set2 = " u!";
	printf("%s\n", ft_strtrim(str2, set2));
	return (0);
}
*/