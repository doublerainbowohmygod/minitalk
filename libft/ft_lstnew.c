/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 21:30:41 by aoneil            #+#    #+#             */
/*   Updated: 2025/12/06 02:02:59 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node1;

	node1 = malloc(sizeof(t_list));
	if (!node1)
		return (NULL);
	node1->content = content;
	node1->next = NULL;
	return (node1);
}

/*
#include <stdio.h>

int main()
{
    int x = 42;
    t_list *node = ft_lstnew(&x);

    if (!node)
    {
        printf("Malloc error!\n");
        return (1);
    }

    printf("New node created:\n");
    printf("  content: %d\n", *(int*)node->content);
    printf("  next: %p (NULL)\n", (void*)node->next);

    free(node);
    return 0;
}
*/