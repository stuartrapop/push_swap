/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 09:02:58 by srapopor          #+#    #+#             */
/*   Updated: 2022/11/03 15:19:54 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include "libft/libft.h"
#include <unistd.h>
#include "push_swap.h"

t_node	*ft_remove_and_return_first(t_node **lst)
{
	t_node	*first_element;

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

t_node	*ft_remove_and_return_last(t_node **lst)
{
	t_node	*last_element;
	t_node	*current;

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

void	swap_first_two(t_node **lst)
{
	t_node	*tmp;

	if (*lst == NULL)
		return ;
	if ((*lst)->next == NULL)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
}
