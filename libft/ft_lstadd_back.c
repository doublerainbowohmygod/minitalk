/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:18:17 by aoneil            #+#    #+#             */
/*   Updated: 2025/06/03 20:26:37 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	last = ft_lstlast(*lst);
	last->next = new;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	t_list *last = ft_lstlast(a);
	if (last)
		printf("Last node content: %s\n", (char *)last->content);
	else
		printf("List is empty\n");

	ft_lstadd_back(&a, c);
	
	t_list *new_last = ft_lstlast(a);
		if (new_last)
		printf("Last node content: %s\n", (char *)new_last->content);
	else
		printf("List is empty\n");
	// Free memory
	free(a->content); free(a);
	free(b->content); free(b);
	free(c->content); free(c);

	return 0;
}
*/