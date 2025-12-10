/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 22:28:02 by aoneil            #+#    #+#             */
/*   Updated: 2025/06/02 11:02:40 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x = 42;
    t_list *node1 = ft_lstnew(&x);
    if (!node1)
    {
        printf("Malloc error!\n");
        return (1);
    }
	printf("  content1: %d\n", *(int*)node1->content);
    printf("  next1: %p \n", (void*)node1->next);

	char s[] = "hi";
    t_list *node2 = ft_lstnew(s);
    if (!node2)
    {
        printf("Malloc error!\n");
        return (1);
    }
	printf("  content2: %s\n", (char*)node2->content);
    printf("  next2: %p \n", (void*)node2->next);

	ft_lstadd_front (&node1, node2);

    printf("New node changed:\n");
	
    printf("  content1: %s\n", (char*)node1->content);
    printf("  next1: %d \n", *(int*)(void*)node1->next);

	printf("  content2: %d\n", *(int*)node2->content);
    printf("  next2: %p \n", (void*)node2->next);

    free(node1->next);
    free(node1);

    return 0;
}
*/