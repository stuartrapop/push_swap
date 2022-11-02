/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 09:02:58 by srapopor          #+#    #+#             */
/*   Updated: 2022/10/30 15:09:47 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"
#include <unistd.h>
#include "push_swap.h"

t_list	*ft_remove_and_return_first(t_list **lst)
{
	t_list	*first_element;

	if (*lst == NULL)
		return (NULL);
	else
	{
		first_element = *lst;
		*lst = (*lst)->next;
		first_element->next = NULL;
	}
	return (first_element);
}

t_list	*ft_remove_and_return_last(t_list **lst)
{
	t_list	*last_element;
	t_list	*current;

	if (*lst == NULL)
		return (NULL);
	if ((*lst)->next == NULL)
	{
		last_element = *lst;
		*lst = NULL;
		return (last_element);
	}
	current = *lst;
	while (current->next->next != NULL)
		current = (current)->next;
	last_element = current->next;
	current->next = NULL;
	return (last_element);
}

void	swap_first_two(t_list **lst)
{
	t_list	*tmp;

	if (*lst == NULL)
		return ;
	if ((*lst)->next == NULL)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
}

void	rotate_list(t_list **lst)
{
	t_list	*item_to_append;

	item_to_append = ft_remove_and_return_first(lst);
	if (item_to_append == NULL)
		return ;
	ft_lstadd_back(lst, item_to_append);
}

void	rotate_reverse_list(t_list **lst)
{
	t_list	*item_to_append;

	item_to_append = ft_remove_and_return_last(lst);
	if (item_to_append == NULL)
		return ;
	ft_lstadd_front(lst, item_to_append);
}
