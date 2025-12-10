/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:04:26 by aoneil            #+#    #+#             */
/*   Updated: 2025/12/06 01:50:56 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);

size_t	ft_countwords(char const *s, char c)
{
	size_t	flag;
	size_t	i;
	size_t	wordcount;

	flag = 0;
	i = 0;
	wordcount = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && flag == 0)
		{
			wordcount++;
			flag = 1;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (wordcount);
}

char	*ft_newword(char const *s, size_t *i, char c)
{
	char			*newword;
	unsigned int	wordstart;
	size_t			wordlen;

	wordlen = 0;
	while (s[*i] == c && s[*i] != '\0')
		(*i)++;
	wordstart = *i;
	while (s[*i] != c && s[*i] != '\0')
	{
		(*i)++;
		wordlen++;
	}
	newword = ft_substr(s, wordstart, wordlen);
	return (newword);
}

void	ft_freearrarr(size_t *j, char **arrarr)
{
	while (*j > 0)
	{
		free (arrarr[*j - 1]);
		(*j)--;
	}
	free (arrarr);
}

static char	**fill_arrarr(char const *s, char **arr, size_t wordcount, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < wordcount)
	{
		arr[j] = ft_newword(s, &i, c);
		if (!arr[j])
		{
			ft_freearrarr(&j, arr);
			return (NULL);
		}
		j++;
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arrarr;
	size_t	wordcount;

	if (!s)
		return (NULL);
	wordcount = ft_countwords(s, c);
	arrarr = ft_calloc(wordcount + 1, sizeof(char *));
	if (!arrarr)
		return (NULL);
	arrarr = fill_arrarr(s, arrarr, wordcount, c);
	return (arrarr);
}

/*
#include <stdio.h>
#include <stdlib.h>

char    **ft_split(char const *s, char c);

int main(void)
{
    char *str = "  hello  world  42  ";
    char sep = ' ';
    char **result = ft_split(str, sep);
	printf("Str:%s\n",str);

    if (!result)
    {
        printf("Split failed!\n");
        return 1;
    }
	printf("main GOT result!\n");
	printf("RESULT: %s", result[0]);
	printf("RESULT: %s", result[1]);
	printf("RESULT: %s", result[2]);
	printf("RESULT: %s", result[3]);


    int i = 0;
    while (result[i])
    {
        printf("Word %d: '%s'\n", i, result[i]);
        free(result[i]);
        i++;
    }
    free(result);

    return 0;
}
*/