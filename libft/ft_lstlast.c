/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:50:47 by aoneil            #+#    #+#             */
/*   Updated: 2025/12/06 01:49:23 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Assume t_list and ft_lstlast are defined above

t_list	*new_node(char *str)
{
	t_list *node = malloc(sizeof(t_list));
	if (!node) return NULL;
	node->content = strdup(str); // For demo purposes
	node->next = NULL;
	return node;
}

int main(void)
{
	t_list *a = new_node("first");
	t_list *b = new_node("second");
	t_list *c = new_node("third");

	a->next = b;
	b->next = c;

	t_list *last = ft_lstlast(a);
	if (last)
		printf("Last node content: %s\n", (char *)last->content);
	else
		printf("List is empty\n");

	// Free memory
	free(a->content); free(a);
	free(b->content); free(b);
	free(c->content); free(c);

	return 0;
}
*/