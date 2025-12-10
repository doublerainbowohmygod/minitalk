/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:48:10 by aoneil            #+#    #+#             */
/*   Updated: 2025/06/03 20:28:49 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free (lst);
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
void del_content(void *content)
{
	free(content);
}

int main(void)
{
	t_list *a = new_node("first");
	t_list *b = new_node("second");
	t_list *c = new_node("third");

	a->next = b;
	b->next = c;
	printf("Node content: %s\n", (char *)a->content);
	t_list *next =  a->next;
	printf("Node content: %s\n", (char *)next->content);
	next =  next->next;
	printf("Node content: %s\n", (char *)next->content);

	a->next = b->next;
	ft_lstdelone(b, del_content);
	
	printf("Node content: %s\n", (char *)a->content);
	next =  a->next;
	printf("Node content: %s\n", (char *)next->content);
	next =  next->next;
	printf("Node content: %s\n", (char *)next->content);

	// Free memory
	free(a->content); free(a);
	free(b->content); free(b);
	free(c->content); free(c);

	return 0;
}
*/