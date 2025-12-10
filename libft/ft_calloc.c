/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:02:16 by aoneil            #+#    #+#             */
/*   Updated: 2025/05/27 17:42:45 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	total = nmemb * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include "libft.h" // Здесь должен быть прототип ft_calloc

int main(void)
{
    // 1. Проверка обычного случая
    int *arr = (int *)ft_calloc(5, sizeof(int));
    if (!arr)
    {
        printf("ft_calloc failed for normal case\n");
        return 1;
    }
    printf("Normal case: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]); // Должно быть 0 0 0 0 0
    printf("\n");
    free(arr);

    // 2. Проверка с нулевым размером
    void *zero = ft_calloc(0, sizeof(int));
    printf("Zero nmemb: %p\n", zero);
    free(zero);

    zero = ft_calloc(10, 0);
    printf("Zero size: %p\n", zero);
    free(zero);

    // 3. Проверка переполнения
    size_t big = (size_t)-1;
    void *overflow = ft_calloc(big, big);
    if (!overflow)
        printf("Overflow correctly detected\n");
    else
    {
        printf("Overflow NOT detected!\n");
        free(overflow);
    }

    return 0;
}
*/