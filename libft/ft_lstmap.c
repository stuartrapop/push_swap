/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:10:36 by srapopor          #+#    #+#             */
/*   Updated: 2022/10/10 11:12:37 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static t_list	*ft_clear_free(t_list **lst, void (*del)(void *))
{
	ft_lstclear(lst, del);
	free(*lst);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*current;

	if (!lst)
		return (NULL);
	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	current = head;
	while (lst != NULL)
	{
		current->content = (*f)(lst->content);
		if (lst -> next != NULL)
		{
			current->next = malloc(sizeof(t_list));
			if (current->next == NULL)
				return (ft_clear_free(&head, del));
		}
		else
			current->next = NULL;
		current = current->next;
		lst = lst->next;
	}
	return (head);
}
